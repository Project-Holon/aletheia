/*
 * function: MYSTERY_UTIL_BuildPaletteRow
 * address: 0x021DAA28
 * packet: pkt_ov121_021DAA28
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 * symbols:
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 */
#include "../include/Obj02470.h"
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
typedef unsigned short u16;
struct Bmp;
struct StrObj;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
void MYSTERY_UTIL_BuildPaletteRow(char *p,int a,int *out)
{
    int x,y;
    switch(((struct Obj02470 *)p)->f14) {
    case 0:
        *(Pair *)out=*(Pair *)(p+12);
        break;
    case 1:
        x=BMP_GetWidth((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        y=BMP_GetHeight((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D304(((struct Obj02470 *)p)->f18,a,0)/2;
        y-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=x+((struct Obj02470 *)p)->fC;
        out[1]=y+((struct Obj02470 *)p)->f10;
        break;
    case 2:
        x=BMP_GetHeight((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=((struct Obj02470 *)p)->fC;
        out[1]=x+((struct Obj02470 *)p)->f10;
        break;
    }
}
