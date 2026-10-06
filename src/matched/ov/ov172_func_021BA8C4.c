/*
 * function: func_021BA8C4
 * address:  0x021BA8C4
 * packet:   pkt_ov172_021BA8C4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scene teardown.
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE1A4  0x021BE1A4  thumb  ov172
 *   func_0203D34C  0x0203D34C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01265.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16  func_021BE00C(u16 *p);
extern void func_021BE1A4(char *p);
extern void func_0203D34C(u32 a, u32 b);
struct Descriptor;
struct Obj;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
struct Obj;
extern void func_0204B3DC(struct Obj *a, unsigned int b);
extern void func_020414EC(u32 a);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void func_02040588(unsigned char which, unsigned char enable);

void func_021BA8C4(u16 *a0, char *p)
{
    u32 r;
    u8 i;
    u16 v;

    v = func_021BE00C(a0);
    if (((struct Obj01265 *)p)->f28 == 1) {
        ((struct Obj01265 *)p)->f28 = (((struct Obj01265 *)p)->f24 == 0) ? 0 : 3;
    }
    r = 0;
    func_0203D34C(0, v);
    func_0201F7A8((void *)(((struct Obj01265 *)p)->f48), 0);
    r = ((struct Obj01265 *)p)->f48;
    func_020456F8((struct Descriptor *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    func_020452E8((struct Descriptor *)(((struct Obj01265 *)p)->f48));
    r = ((struct Obj01265 *)p)->f4C;
    func_020456F8((struct Descriptor *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    func_020452E8((struct Descriptor *)(((struct Obj01265 *)p)->f4C));
    r = ((struct Obj01265 *)p)->f50;
    if (r != 0) {
        func_020456F8((struct Descriptor *)r);
        func_020409B4(func_02045730((struct Descriptor *)r));
        func_020452E8((struct Descriptor *)(((struct Obj01265 *)p)->f50));
        ((struct Obj01265 *)p)->f50 = 0;
    }
    for (i = 0; i < 5; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4 + 0x70)));
    }
    for (i = 0; i < 6; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4 + 0x58)));
    }
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f90));
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f8C));
    func_0204B3DC((struct Obj *)((struct Obj01265 *)p)->f88, 0);
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f88));
    func_0204B3DC((struct Obj *)((struct Obj01265 *)p)->f84, 0);
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f84));
    func_020414EC(0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_021BE1A4((char *)a0);
}
