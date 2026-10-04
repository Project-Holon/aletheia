/*
 * function: func_021DA32C
 * address:  0x021DA32C
 * packet:   pkt_ov093_021DA32C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7D54   0x021C7D54  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */
#include "../include/Obj06255.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021D775C(int a);
extern u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
/* lo/hi sums are u16 accumulators; a u8 third parameter keeps its reload
   after the +0xf store. */
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DA32C(int a, int b, u8 c)
{
    u8 buf[4];
    u8 n;
    u16 lo;
    u16 hi;
    u8 i;
    int k;
    void *q;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    n = func_021C7D54((u8 *)b, (u8 *)c, buf);
    if (n == 0)
        return;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        q = func_021C7CF4((int *)b, buf[i]);
        lo = lo + (u16)func_021D59B4(q, 9);
        hi = hi + (u16)func_021D59B4(q, 0xb);
    }
    if (lo >= hi)
        k = 3;
    else
        k = 1;
    p = func_021C88A4(b, 0xe, c);
    ((struct Obj06255 *)p)->f0 |= 2 << 22;
    p[0xf] = 1;
    p[0x10] = c;
    ((struct Obj06255 *)p)->f4 = k;
    p[0xc] = 1;
    func_021C88C8((void *)b, p);
}
