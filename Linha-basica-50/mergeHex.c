// mergehex.c
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PATH_LEN  260
#define MAX_LINE_LEN 1024

// Intel-HEX EOF record
static const char *EOF_REC = ":00000001FF";

void merge_file(FILE *in, FILE *out) {
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), in)) {
        // Remove CR/LF
        line[strcspn(line, "\r\n")] = 0;
        // Skip only the EOF record
        if (strcmp(line, EOF_REC) == 0)
            continue;
        fprintf(out, "%s\n", line);
    }
}

int main(void) {
    char exeFull[MAX_PATH_LEN];
    // 1) Get full path to this executable
    if (!GetModuleFileNameA(NULL, exeFull, MAX_PATH_LEN)) {
        fprintf(stderr, "Error: GetModuleFileName failed\n");
        return 1;
    }
    
    // 2) Remove executable name -> dir of exe (typically ...\Port...\Debug)
    char exeDir[MAX_PATH_LEN];
    strcpy(exeDir, exeFull);
    char *p = strrchr(exeDir, '\\');
    if (!p) {
        fprintf(stderr, "Error: unexpected path format\n");
        return 1;
    }
    *p = '\0';  // exeDir now is the Debug folder

    // 3) Compute project root by going up two levels for input files
    char projectRoot[MAX_PATH_LEN];
    strcpy(projectRoot, exeDir);
    for (int i = 0; i < 2; ++i) {
        char *pp = strrchr(projectRoot, '\\');
        if (pp) *pp = '\0';
    }

    // 4) Build input paths
    char bootPath[MAX_PATH_LEN], appPath[MAX_PATH_LEN];
    snprintf(bootPath, MAX_PATH_LEN, "%s\\BootloaderComSTM32F427AGH6\\Debug\\BootloaderComSTM32F427AGH6.hex", projectRoot);
    snprintf(appPath,  MAX_PATH_LEN, "%s\\PortLinhaBasicaComSTM32F427AGH6_mod\\Debug\\PortLinhaBasicaComSTM32F427AGH6_mod.hex", projectRoot);

    // 5) Create timestamped output filename: firmware_YYYYMMDD.hex in the same Debug folder as exe
    time_t t = time(NULL);
    struct tm local;
    localtime_s(&local, &t);
    char dateStr[16];
    strftime(dateStr, sizeof(dateStr), "%Y%m%d", &local);

    char outPath[MAX_PATH_LEN];
    snprintf(outPath, MAX_PATH_LEN, "%s\\firmware_%s.hex", exeDir, dateStr);

    // 6) Open files
    FILE *fb = fopen(bootPath, "r");
    FILE *fa = fopen(appPath,  "r");
    FILE *fo = fopen(outPath,  "w");
    if (!fb || !fa || !fo) {
        fprintf(stderr, "Error opening files:\n Boot: %s\n App:  %s\n Output: %s\n", 
                fb ? "ok" : "failed", fa ? "ok" : "failed", outPath);
        return 1;
    }

    // 7) Merge
    merge_file(fb, fo);
    merge_file(fa, fo);
    // 8) Write single EOF record
    fprintf(fo, "%s\n", EOF_REC);

    fclose(fb);
    fclose(fa);
    fclose(fo);

    printf("Success: generated %s\n", outPath);
    return 0;
}
