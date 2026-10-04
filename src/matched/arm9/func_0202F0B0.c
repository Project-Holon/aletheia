/*
 * function: func_0202F0B0
 * address:  0x0202F0B0
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_020439A0   0x020439A0  arm
 *   func_02045334   0x02045334  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F0B0.c \
 *       --func func_0202F0B0 --addr 0x0202F0B0 --cc 1.1p1 --thumb
 */
#include "../include/Obj01310.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Bmp;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02045334(struct Descriptor *a);

void func_0202F0B0(u8 *p)
{
    if (((struct Obj01310 *)p)->f18 == 0)
        return;

    if (((struct Obj01310 *)p)->f13 == 0) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01310 *)p)->f8)), ((struct Obj01310 *)p)->f12);
        func_020439A0((struct Bmp *)(((struct Obj01310 *)p)->fC), (struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj01310 *)p)->f8)), 0,
                      (u32)((struct Obj01310 *)p)->f15 << 4, 0, 0, 0x10, 0x10, 0);
        func_02045334((struct Descriptor *)((struct Obj01310 *)p)->f8);

        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f14;
        ((struct Obj01310 *)p)->f15 = ((struct Obj01310 *)p)->f15 + 1;

        if (((struct Obj01310 *)p)->f15 == 8)
            ((struct Obj01310 *)p)->f15 = 0;
    } else {
        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f13 - 1;
    }
}
