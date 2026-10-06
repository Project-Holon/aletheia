/*
 * function: func_021BC9CC
 * address:  0x021BC9CC
 * packet:   pkt_ov021_021BC9CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD1DC  0x021BD1DC  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021BD1FC  0x021BD1FC  thumb  ov021
 *   func_021BD204  0x021BD204  thumb  ov021
 *   func_021BD1EC  0x021BD1EC  thumb  ov021
 *   func_021BD1F4  0x021BD1F4  thumb  ov021
 *   func_020439A0  0x020439A0  arm
 */
#include "../include/Obj01123.h"

typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021BD1DC(u8 *a0);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern int func_021BD1FC(int a);
extern int func_021BD204(int a);
extern int func_021BD1EC(int a);
extern int func_021BD1F4(u8 *a0);
typedef unsigned int   u32;
struct Bmp;
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

void func_021BC9CC(char *p)
{
    int r4;
    int a, b;
    u16 c, d, e, f;

    r4 = *(int *)(p + 0xc8 + 4 * ((struct Obj01123 *)p)->f14A);
    if (r4 != 0) {
        a = func_021BD1DC((u8 *)r4);
        b = (int)func_02045770((struct Descriptor *)*(int *)&((struct Obj01123 *)p)->f24);
        c = func_021BD1FC(r4);
        d = func_021BD204(r4) - 8;
        e = func_021BD1EC(r4);
        f = func_021BD1F4((u8 *)r4);
        func_020439A0((struct Bmp *)a, (struct Bmp *)b, 0, 0, c, d, e, f, 0);
    }
    (((struct Obj01123 *)p)->f14A)++;
}
