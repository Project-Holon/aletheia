/*
 * function: func_021BB54C
 * address:  0x021BB54C
 * packet:   pkt_ov172_021BB54C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   func_021BE0B4  0x021BE0B4  thumb  ov172
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021C6FB2     0x021C6FB2  data
 *   d_021C6FB4     0x021C6FB4  data
 *   d_021C6FB6     0x021C6FB6  data
 *   d_021C6FB8     0x021C6FB8  data
 */
#include "../include/Obj00024.h"

typedef unsigned char u8;
typedef unsigned long u32;

typedef unsigned short u16;
struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_021BE0B4(void *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern const u8 d_021C6FB2[];
extern const u8 d_021C6FB4[];
extern const u8 d_021C6FB6[];
extern const u8 d_021C6FB8[];

void func_021BB54C(void *ctx, u8 *p)
{
    int r;

    func_0204B878(((struct Obj00024 *)p)->f58, d_021C6FB2[((struct Obj00024 *)p)->f28 == 0]);
    func_0204B878(((struct Obj00024 *)p)->f5C, d_021C6FB4[((struct Obj00024 *)p)->f28 == 1]);
    func_0204B878(((struct Obj00024 *)p)->f60, d_021C6FB6[((struct Obj00024 *)p)->f28 == 2]);
    func_0204B878(((struct Obj00024 *)p)->f64, d_021C6FB8[((struct Obj00024 *)p)->f28 == 3]);
    r = func_021BE0B4(ctx);
    if (r == 1) {
        func_0204B878(((struct Obj00024 *)p)->f68, 12);
    } else {
        func_0204B878(((struct Obj00024 *)p)->f68, 10);
    }
    if (((struct Obj00024 *)p)->f28 != 0 && ((struct Obj00024 *)p)->f10 == 1) {
        ((struct Obj00024 *)p)->f10 = 0;
        func_0204B3DC(((struct Obj00024 *)p)->f84, 0);
        func_0204B9A0(((struct Obj00024 *)p)->f84);
        func_0204B8C4(((struct Obj00024 *)p)->f84, 0);
        func_0204B92C(((struct Obj00024 *)p)->f84, 0);
        func_0204B3DC(((struct Obj00024 *)p)->f90, 0);
    }
    if (((struct Obj00024 *)p)->f28 != 3 && ((struct Obj00024 *)p)->f14 == 1) {
        ((struct Obj00024 *)p)->f14 = 0;
        func_0204B3DC(((struct Obj00024 *)p)->f88, 0);
        func_0204B9A0(((struct Obj00024 *)p)->f88);
        func_0204B8C4(((struct Obj00024 *)p)->f88, 0);
        func_0204B92C(((struct Obj00024 *)p)->f88, 0);
        func_0204B3DC(((struct Obj00024 *)p)->f90, 0);
    }
}
