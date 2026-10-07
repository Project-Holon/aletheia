/*
 * file:     worldtrade_adapter_p22.c
 * unit:     yes
 * function: func_021FF0E8, func_021FF118, func_021FF174, func_021FF198
 * address:  0x021FF0E8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135
 *   func_020221A4 0x020221A4 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020362DC 0x020362DC arm
 *   func_0202208C 0x0202208C thumb
 *   func_021FFB00 0x021FFB00 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj07250.h"
#include "../../matched/include/Obj05418.h"
#include "../../matched/include/Obj07251.h"
#include "../../matched/include/Obj08192.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern u32 func_02202840(u8 *p);
extern u32 func_020221A4(void);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_020362DC(void);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021FFB00(int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
int func_021FF0E8(u8 *p);
int func_021FF118(char *p);
int func_021FF174(u8 *p);
int func_021FF198(char *p);


/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int func_021FF0E8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07250 *)p)->fDFC > 0x2d) {
            ((struct Obj07250 *)p)->fDFC = 0;
            ((struct Obj07250 *)p)->f28 = ((struct Obj07250 *)p)->f2C;
        }
    }
    return 2;
}

/*
 * volatile: 021FF12E reads hardware register 04000304.
 */
int func_021FF118(char *p)
{
    ++((struct Obj05418 *)p)->fD3C;
    if (func_020221A4()) {
        *(volatile u16 *)0x04000304 |= 0x8000;
        ((struct Obj05418 *)p)->fD3C = -16;
        if (((struct Obj05418 *)p)->fE1A) {
            ((struct Obj05418 *)p)->f28 = 2;
            func_021F4EC0((u8 *)p, 3, 16);
            ((struct Obj05418 *)p)->fD4 = 0;
        }
        func_0204B3DC((struct Obj *)((struct Obj05418 *)p)->fD38, 0);
    }
    return 2;
}


/*
 * Decrement the countdown at +0xd3c and, when the tick returns non-zero, zero it and latch state 1.
 */
int func_021FF174(u8 *p)
{
    u32 v = ((struct Obj07251 *)p)->fD3C - 1;

    ((struct Obj07251 *)p)->fD3C = v;
    if (func_020221A4() != 0) {
        ((struct Obj07251 *)p)->fD3C = 0;
        ((struct Obj07251 *)p)->f28 = 1;
    }
    return 2;
}

int func_021FF198(char *p)
{
    int r;
    if (func_020362DC() & 1) {
        func_0202208C(0, 0, 0, 0, 16, 1, 72);
    } else {
        r = func_021FFB00(((struct Obj08192 *)p)->fD0);
        if (((struct Obj08192 *)p)->fE1A && r >= 0) {
            func_0204B878((struct Obj *)(*(unsigned *)(p + 0xd0c + (r + 1) * 4)), (u16)(16 + r * 4));
            ((struct Obj08192 *)p)->f28 = 2;
            func_021F4EC0((u8 *)p, 3, 0);
            ((struct Obj08192 *)p)->fD4 = r;
            func_020061E4(0x54c);
        }
    }
    return 2;
}
