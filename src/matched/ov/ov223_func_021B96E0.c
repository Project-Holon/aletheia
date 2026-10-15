/*
 * function: PSEL_Main
 * address: 0x021B96E0
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B96E0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   callbacks 0x021BC84C data a4
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PSEL_UpdateAF30 0x021BAF30 thumb ov223
 *   PSEL_GRAPHIC_Draw 0x021BC4F4 thumb ov223
 *   PSEL_GRAPHIC_ApplyLight 0x021BC508 thumb ov223
 *   PSEL_DrawObjects 0x021B97F8 thumb ov223
 *   PSEL_GRAPHIC_DrawEnd 0x021BC514 thumb ov223
 */
#include "../include/Obj03962.h"
extern int (*callbacks[])(char *,int *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void PSEL_UpdateAF30(int *);
extern void PSEL_GRAPHIC_Draw(char *);
extern void PSEL_GRAPHIC_ApplyLight(unsigned char *p);
extern void PSEL_DrawObjects(char *p);
extern void PSEL_GRAPHIC_DrawEnd(unsigned char *p);
int PSEL_Main(void *a,int *state,void *b,char *p)
{
    int old=*state;
    *state=callbacks[*state](p,(int *)(p+12));
    if(*state!=13) {
        if(*state!=old) ((struct Obj03962 *)p)->fC=0;
    } else return 1;
    if(*state>=2&&*state<=11) {
        PRINTSYS_QUE_Main(((struct Obj03962 *)p)->f1C);
        PSEL_UpdateAF30((int *)p);
        PSEL_GRAPHIC_Draw(*(char * *)&((struct Obj03962 *)p)->f14);
        PSEL_GRAPHIC_ApplyLight(((struct Obj03962 *)p)->f14);
        PSEL_DrawObjects(p);
        PSEL_GRAPHIC_DrawEnd(((struct Obj03962 *)p)->f14);
    }
    return 0;
}
