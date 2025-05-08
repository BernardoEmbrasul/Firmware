/*****************************************************************************
 *   display.h:  
 *
 *
 *   History
 *   
 *
 ******************************************************************************/
#ifndef __DISPLAY_H__
#define __DISPLAY_H__


extern void WriteChar( WORD DpyNum, BYTE DPYchar, DWORD ponto);
extern void DisplayInit(void);
extern void SkewBanner(void);
extern void WriteString(WORD posInicial, char *str);
extern void FloatToStr(float numero, char *str, int *FlagKilo,int *FlagMenos );
extern void FloatToStr8algarismos(float numero, char *str, int *FlagKilo,int *FlagMenos);
extern void WriteBanner(BYTE posInicial, char str[]);
extern void IntToStr(short numero, char *str);
extern void IntToStr1(unsigned int numero, char *str);
extern void setDpyPiscante(char PrimeiroDpyPiscante_, char UltimoDpyPiscante_);
#endif

