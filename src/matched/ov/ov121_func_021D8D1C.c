/*
 * function: MYSTERY_CardViewAnimScroll
 * address: 0x021D8D1C
 * packet: pkt_ov121_021D8D1C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware stores at 021D8D9A and 021D8DEC.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   MYSTERY_SetupBg 0x021D694C thumb ov121
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 *   MYSTERY_StartScroll 0x021D9254 thumb ov121
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00498.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *,int,int,int,int);
struct Actor;
struct Obj;
extern void MYSTERY_SetupBg(u16 *p, int mode);
extern void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern void MYSTERY_StartScroll(char *p, int n);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void MYSTERY_CardViewAnimScroll(u8 *p)
{
    s16 y;
    switch(((struct Obj00498 *)p)->f20) {
    case 0:
        func_02040588(2,0);
        MYSTERY_SetupBg(((struct Obj00498 *)p)->f24,2);
        ((struct Obj00498 *)p)->f20=1;
        return;
    case 1:
        func_0207D63C((void *)0x04000050,4,8,0,16);
        func_02040588(2,1);
        ((struct Obj00498 *)p)->f18=0;
        ((struct Obj00498 *)p)->f20=2;
        return;
    case 2: {
        u32 n=(((struct Obj00498 *)p)->f18*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        ((struct Obj00498 *)p)->f30=(((struct Obj00498 *)p)->f18*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange((void *)15,(u16 *)(p+50),((struct Obj00498 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        MYSTERY_UTIL_BlendPaletteRange((void *)31,(u16 *)(p+82),((struct Obj00498 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((struct Obj00498 *)p)->f18)++>120) {
            *(volatile u16 *)0x04000050=0;
            MYSTERY_StartScroll(((struct Obj00498 *)p)->f28,1);
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=3;
            return;
        }
        break;
    }
    case 3:
        if((((struct Obj00498 *)p)->f18)++>180) {
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=4;
            return;
        }
        break;
    case 4:
        y=((214-((struct Obj00498 *)p)->f128)*((struct Obj00498 *)p)->f18)/60u-96;
        CLACT_SetActorSurfacePosAxis(((struct Obj00498 *)p)->f4,y,0,1);
        if(y>=-48 && y<=192) CLACT_SetActorDrawEnable(((struct Obj00498 *)p)->f4,1);
        if((((struct Obj00498 *)p)->f18)++>=60) {
            GFL_USE_PlaySeDefaultVolume(1649);
            MYSTERY_StartScroll(((struct Obj00498 *)p)->f28,0);
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=5;
            return;
        }
        break;
    case 5:
        if((((struct Obj00498 *)p)->f18)++>60) {
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=6;
            return;
        }
        break;
    case 6:
        ((struct Obj00498 *)p)->f8=1;
        break;
    }
}
