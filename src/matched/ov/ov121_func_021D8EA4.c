/*
 * function: func_021D8EA4
 * address: 0x021D8EA4
 * packet: pkt_ov121_021D8EA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware stores at 021D8F44, 021D8F96, 021D9062, 021D908E, 021D9116.
 * symbols:
 *   func_021D6CF4 0x021D6CF4 thumb ov121
 *   func_021D6D50 0x021D6D50 thumb ov121
 *   func_021D6D6C 0x021D6D6C thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D694C 0x021D694C thumb ov121
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   func_021D9254 0x021D9254 thumb ov121
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00184.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 x,y;} Position;
extern void func_021D6CF4(int *,int);
extern void func_021D6D50(int *,int,int,int);
extern int func_021D6D6C(void **,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D694C(u16 *,int);
extern void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
struct Obj;
extern void func_021D9254(char *p, int n);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021D8EA4(u8 *p)
{
    Position pos;
    switch(((struct Obj00184 *)p)->f20) {
    case 0:
        func_021D6CF4((int *)(p+0x118),((struct Obj00184 *)p)->f0);
        func_021D6D50((int *)(p+0x118),0x22,0x26,((struct Obj00184 *)p)->f0);
        func_02040588(2,0);
        func_021D694C(*(u16 * *)&((struct Obj00184 *)p)->f24,2);
        ((struct Obj00184 *)p)->f20=1;
        return;
    case 1:
        func_0207D63C((void *)0x04000050,4,8,0,16);
        func_02040588(2,1);
        ((struct Obj00184 *)p)->f18=0;
        ((struct Obj00184 *)p)->f20=2;
        return;
    case 2: {
        u32 n=(((struct Obj00184 *)p)->f18*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        ((struct Obj00184 *)p)->f30=(((struct Obj00184 *)p)->f18*32767u)/120u;
        func_021DAB50((void *)15,(u16 *)(p+50),((struct Obj00184 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        func_021DAB50((void *)31,(u16 *)(p+82),((struct Obj00184 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((struct Obj00184 *)p)->f18)++>120) {
            *(volatile u16 *)0x04000050=0;
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=3;
            return;
        }
        break;
    }
    case 3:
        if((((struct Obj00184 *)p)->f18)++>180) {
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=6;
            func_0207D63C((void *)0x04000050,1,31,0,16);
            func_021D6D6C((void **)(p+0x118),0);
            func_021D6D6C((void **)(p+0x118),1);
            func_021D6D6C((void **)(p+0x118),2);
            GFL_USE_PlaySeDefaultVolume(0x794);
            return;
        }
        break;
    case 6:
        if((((struct Obj00184 *)p)->f18)++>120) {
            GFL_USE_PlaySeDefaultVolume(0x795);
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=4;
            func_021D9254(((struct Obj00184 *)p)->f28,1);
            return;
        }
        break;
    case 4:
        pos.x=128;
        pos.y=118-((struct Obj00184 *)p)->f128;
        CLACT_AddActorSurfacePos(((struct Obj00184 *)p)->f4,(const struct Vec2 *)(&pos),0);
        CLACT_SetActorDrawEnable(((struct Obj00184 *)p)->f4,1);
        ((struct Obj00184 *)p)->f1C=0;
        ((struct Obj00184 *)p)->f20=5;
        return;
    case 5: {
        u32 n=(((struct Obj00184 *)p)->f1C*16u)/10u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        (((struct Obj00184 *)p)->f18)++;
        if((((struct Obj00184 *)p)->f1C)++>10) {
            ((struct Obj00184 *)p)->f1C=0;
            ((struct Obj00184 *)p)->f20=7;
            return;
        }
        break;
    }
    case 7:
        if((((struct Obj00184 *)p)->f18)++>90) {
            *(volatile u16 *)0x04000050=0;
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=8;
            return;
        }
        break;
    case 8:
        if((((struct Obj00184 *)p)->f18)++>10) {
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=9;
            return;
        }
        break;
    case 9:
        ((struct Obj00184 *)p)->f30=(((struct Obj00184 *)p)->f18*32767u)/120u;
        func_021DAB50((void *)14,(u16 *)(p+178),((struct Obj00184 *)p)->f30,14,(const u16 *)(p+242),(const u16 *)(p+210));
        if((((struct Obj00184 *)p)->f18)++>120) {
            func_021D9254(((struct Obj00184 *)p)->f28,0);
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=10;
            return;
        }
        break;
    case 10:
        if((((struct Obj00184 *)p)->f18)++>60) {
            GFL_USE_PlaySeDefaultVolume(0x671);
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=11;
            return;
        }
        break;
    case 11:
        *(volatile u16 *)0x04000050=0;
        ((struct Obj00184 *)p)->f8=1;
        break;
    }
}
