/*
 * function: func_02013360
 * address:  0x02013360
 * packet:   pkt_02013360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200873C   0x0200873C  thumb
 *   func_0200C0E8   0x0200C0E8  thumb
 *   func_0200C258   0x0200C258  thumb
 *   func_0200CA1C   0x0200CA1C  thumb
 *   func_02012924   0x02012924  thumb
 *   func_0201292C   0x0201292C  thumb
 *   func_02012944   0x02012944  thumb
 *   func_0201296C   0x0201296C  thumb
 *   func_02012EBC   0x02012EBC  thumb
 *   func_02012F20   0x02012F20  thumb
 *   func_02012F2C   0x02012F2C  thumb
 *   func_02013144   0x02013144  thumb
 *   func_020142E8   0x020142E8  thumb
 *   func_02082D44   0x02082D44  arm
 *
 * btl_setup.c.  The shared setup-object initialiser every builder of the
 * family calls with (o, a1, sub): reset the flag and slot fields, read the
 * per-battle values out of the game-data object a1, and copy the 0x10-byte
 * sub-block a2 to +8.
 *
 * Two facts closed it (docs/notes/pkt_02013360.c.txt had it at 266 bytes
 * out, every line phase-shifted from the head):
 *  - 0x02082D44 is MI_CpuCopy8 (layout/symbols_sdk.txt), whose order is
 *    (src, dst, size): the image computes o + 8 into r1 and a2 into r0.
 *    With that order the whole body is byte-exact and only the head differs.
 *  - The first loop counter is initialised at its declaration, ahead of the
 *    store run.  That puts the constant 0 (shared by the zero stores and the
 *    counter) before the 0xffff store in the IR, so the zero takes r0 and
 *    the 0x84 base is built in r1 from the o copy, which is the image's
 *    head.  With `for (i = 0; ...)` the base coalesces into r0 instead and
 *    every later line is displaced.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013360.c  *       --func func_02013360 --addr 0x02013360 --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Big;
struct Blk34;
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_0200C0E8(void *sys);
extern u32 func_0200C258(struct Blk34 *p);
extern void *func_0200CA1C(void *a);
struct BigObj;
extern u32 func_02012924(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern u32  func_02012F20(void *a);
extern void *func_02012F2C(int *p);
extern void func_02013144(void *p, int v);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_02082D44(const void *src, void *dst, u32 n);

void func_02013360(u8 *o, void *a1, const void *a2)
{
    u32 i = 0;
    u32 j;
    u32 t;
    u32 u;

    ((struct Obj00155 *)o)->f84 = 0xffff;
    *(o + 0x20) = 0;
    *(o + 0x21) = 0;
    *(o + 0x22) = 0;
    ((struct Obj00155 *)o)->f94 = 0;
    *(o + 0x23) = 0;
    *(o + 0xc1) = *(o + 0xc1) & ~1;
    ((struct Obj00155 *)o)->f1C = 0;
    *(o + 0xc1) = *(o + 0xc1) & ~2;
    ((struct Obj00155 *)o)->f58 = (u32)a1;
    for (; i < 4; i++) {
        *(u32 *)(o + i * 4 + 0x24) = 0;
        *(u32 *)(o + i * 4 + 0x34) = 0;
    }
    for (j = 0; j < 6; j++) {
        *(o + j + 0xc2) = 0;
    }
    *(o + 0x7f) = 1;
    for (i = 0; i < 7; i++) {
        *(o + i + 0x78) = 0;
    }
    ((struct Obj00155 *)o)->f34 = (u32)func_02012944(a1);
    ((struct Obj00155 *)o)->f60 = func_0201292C(a1);
    ((struct Obj00155 *)o)->f64 = func_02012924(a1);
    ((struct Obj00155 *)o)->f68 = (u32)func_0200CA1C(a1);
    ((struct Obj00155 *)o)->f70 = func_02012F20(a1);
    ((struct Obj00155 *)o)->f6C = (u32)func_02012F2C(a1);
    t = (u32)func_02012EBC(a1);
    u = (u32)func_0200C0E8((void *)t);
    ((struct Obj00155 *)o)->f5C = (u32)func_0200873C((void *)t);
    *(o + 0x80) = (u8)func_0200C258((struct Blk34 *)u);
    func_02082D44(a2, o + 8, 0x10);
    ((struct Obj00155 *)o)->f18 = 0x468;
    ((struct Obj00155 *)o)->f1A = 0x468 + 0x14;
    ((struct Obj00155 *)o)->f8C = 1;
    if (func_020142E8((void *)func_0201296C(a1), 0x96d) != 0) {
        func_02013144(o, 2);
    }
}
