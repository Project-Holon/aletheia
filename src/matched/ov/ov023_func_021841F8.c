/*
 * function: func_021841F8
 * address:  0x021841F8
 * packet:   pkt_ov023_021841F8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021844D8  0x021844D8  thumb  ov023
 *   func_02186860  0x02186860  thumb  ov023
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01674.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_02082B0C(void *src, void *dst, u32 n);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_021844D8(char *p, int x, int y);
extern void func_02186860(char *p, int x, int y);

void func_021841F8(int a, int b, u8 *c, u8 *d, int e)
{
    int n;
    int off;
    u32 t;

    if (func_02039338() != 0) {
        off = c[0x3ec] * 0x3e8;
        if (off > 0x3840) {
            func_02082B0C(c, d + 0x4290 + off, 0x190);
        } else {
            func_02082B0C(c, d + 0x4290 + off, 0x3e8);
        }
        func_02082B0C(d + 0x4290,
                      func_020437D4(func_02045770((struct Descriptor *)((struct Obj01674 *)d)->f118)),
                      0x3840);
        t = ((struct Obj01674 *)d)->f118;
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_020409B4(func_02045730((struct Descriptor *)t));
    } else {
        n = ((struct Obj01674 *)d)->f428C;
        if (n * 1000 < 0x3840) {
            ((struct Obj01674 *)d)->f428C += 1;
            func_021844D8((char *)d, ((struct Obj01674 *)d)->f428C, e);
        } else {
            func_02186860((char *)d, 0x2904, 0);
        }
    }
}
