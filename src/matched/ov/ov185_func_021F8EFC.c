/*
 * function: BR_POKESEARCH_CreateSearch
 * address: 0x021F8EFC
 * packet: pkt_ov185_021F8EFC
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   BR_POKESEARCH_Create 0x021FFBD4 thumb ov186
 *   BR_POKESEARCH_Open 0x021FFE5C thumb ov186
 */
#include "../include/Obj00278.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern char *BR_POKESEARCH_Create(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern void BR_POKESEARCH_Open(char *);
void BR_POKESEARCH_CreateSearch(char *p,int *source)
{
    if(*(int *)&((struct Obj00278 *)p)->f0==0) {
        int c=BR_GRAPHIC_GetActorUnit((u8 *)source[2]);
        char *result;
        if(*(int *)&((struct Obj00278 *)p)->f4==0)
            ((struct Obj00278 *)p)->f4=BR_UTIL_CreateTextWin((int)((void *)source[3]),(void *)(*(int *)&((struct Obj00278 *)p)->f2C),((struct Obj00278 *)p)->f30);
        BR_UTIL_SetWindowText(((struct Obj00278 *)p)->f4,(void *)source[3],(void *)0x2c);
        result=BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData((void *)source[6]),(void *)source[3],c,*(int *)&((struct Obj00278 *)p)->f28,source[0],((struct Obj00278 *)p)->f38,((struct Obj00278 *)p)->f3C,((struct Obj00278 *)p)->f30);
        *(char * *)&((struct Obj00278 *)p)->f0=result;
        BR_POKESEARCH_Open(result);
    }
}
