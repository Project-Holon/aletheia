/*
 * function: func_021D8D1C
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
 *   func_021D694C 0x021D694C thumb ov121
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   func_021D9254 0x021D9254 thumb ov121
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
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
extern void func_021D694C(u16 *p, int mode);
extern void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern void func_021D9254(char *p, int n);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020061E4(u32 a);
void func_021D8D1C(u8 *p)
{
    s16 y;
    switch(((struct Obj00498 *)p)->f20) {
    case 0:
        func_02040588(2,0);
        func_021D694C(((struct Obj00498 *)p)->f24,2);
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
        func_021DAB50((void *)15,(u16 *)(p+50),((struct Obj00498 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        func_021DAB50((void *)31,(u16 *)(p+82),((struct Obj00498 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((struct Obj00498 *)p)->f18)++>120) {
            *(volatile u16 *)0x04000050=0;
            func_021D9254(((struct Obj00498 *)p)->f28,1);
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
        if(y>=-48 && y<=192) func_0204B3DC(((struct Obj00498 *)p)->f4,1);
        if((((struct Obj00498 *)p)->f18)++>=60) {
            func_020061E4(1649);
            func_021D9254(((struct Obj00498 *)p)->f28,0);
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
