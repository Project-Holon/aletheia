/*
 * file:     palette_anime_p09.c
 * unit:     yes
 * function: func_021C20D8, func_021C20EC, func_021C2118, func_021C211C, func_021C2188, func_021C218C, func_021C2194, func_021C21C4, func_021C2250
 * address:  0x021C20D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C2260  0x021C2260  thumb  ov217
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B9C4 0x0204B9C4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj06717.h"
#include "../../matched/include/Obj06718.h"
#include "../../matched/include/Obj14763.h"
#include "../../matched/include/Obj26020.h"
#include "../../matched/include/Obj06719.h"
#include "../../matched/include/Obj06720.h"

struct Obj;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Vec2 { short x,y; };

extern u32 func_021C2260();
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B8C4(struct Obj *,u32);
extern void func_0204B9C4(struct Actor *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B954(struct Actor *,u32);
extern void func_0204B95C(struct Actor *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B974(struct Actor *a);
u32 func_021C20D8(u32 a0);
void func_021C20EC(void *p);
void func_021C2118(void *p);
void func_021C211C(void *p);
void func_021C2188(void *p);
void func_021C218C(void *p, u32 v);
u32 func_021C2194(void *p);
void func_021C21C4(u8 *p,int index);
void func_021C2250(u32 a0, u32 a1);

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C20D8(u32 a0)
{
    func_021C218C((void *)a0, 0);
    return func_021C2260(a0);
}


void func_021C20EC(void *p)
{
    switch (((struct Obj06717 *)p)->f20) {
    case 0: func_021C2118(p); break;
    case 1: func_021C211C(p); break;
    case 2: func_021C2188(p); break;
    }
    (((struct Obj06717 *)p)->f24)++;
}


/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2118(void *p)
{
}


void func_021C211C(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj06717 *)p)->f298; i++) {
        char *e = (char *)p + i * 0x18;
        if (((struct Obj06718 *)e)->f28 == 0 && ((struct Obj06718 *)e)->f2C <= ((struct Obj06717 *)p)->f24)
            func_021C21C4(p, (u8)i);
        if (((struct Obj06718 *)e)->f28 == 1 && ((struct Obj06718 *)e)->f30 == 1 && ((struct Obj06718 *)e)->f34 <= ((struct Obj06717 *)p)->f24)
            func_021C2250((u32)p, (u8)i);
    }
    if (func_021C2194(p))
        func_021C218C(p, 2);
}


void func_021C2188(void *p)
{
}


/*
 * Set +0x20 and clear +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021C218C(void *p, u32 v)
{
    ((struct Obj14763 *)p)->f20 = v;
    ((struct Obj14763 *)p)->f24 = 0;
}


u32 func_021C2194(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj26020 *)p)->f298; i++) {
        if (*(u32 *)((char *)p + 0x28 + i * 0x18) == 0)
            return 0;
    }
    return 1;
}

/*
 * tail: two zero padding bytes at 0x021C224E, not a follower.
 * ABI: B8C4's own source omits the visible original r1=0; retain it.
 *      Palette is selected only for the original modes 0..3; original
 *      default branch retains entry r5 without initializing it.
 */
void func_021C21C4(u8 *p,int index)
{
    u8 *record=p+0x28+index*24;
    struct Obj *obj=*(struct Obj * *)&((struct Obj06720 *)record)->f14;
    struct Vec2 point;
    u16 palette;
    point.x=record[0xe];
    point.y=record[0xf];
    ((struct Obj06720 *)record)->f0=1;
    switch (((struct Obj06720 *)record)->f10) {
    case 0: palette=((struct Obj06719 *)p)->f16; break;
    case 1: palette=((struct Obj06719 *)p)->f18; break;
    case 2: palette=((struct Obj06719 *)p)->f1A; break;
    case 3: palette=((struct Obj06719 *)p)->f1C; break;
    }
    func_0204B404(obj,&point,((struct Obj06719 *)p)->f14);
    func_0204B878(obj,palette);
    func_0204B8C4(obj,0);
    func_0204B9C4((struct Actor *)obj,1);
    func_0204B92C(obj,1);
    func_0204B954((struct Actor *)obj,0x12000);
    func_0204B95C((struct Actor *)obj);
    func_0204B3DC(obj,1);
}

void func_021C2250(u32 a0, u32 a1)
{
    func_0204B974((struct Actor *)(*(u32*)(((u8*)a0 + a1 * 24) + 60)));
}
