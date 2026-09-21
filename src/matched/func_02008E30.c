/*
 * function: func_02008E30
 * address:  0x02008E30
 * packet:   pkt_02008E30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209DDA0 - data table named by one pool word in the whole image,
 *           this function's own.  The `literal` class discards that witness
 *           under the honesty rule and no cut helps (the pool word is inside
 *           the section whatever the range).  Every concrete byte is right:
 *           56 bytes, 3 calls resolved, 1 ABS32 wildcarded.
 * symbols:
 *   g_0209DDA0      0x0209DDA0  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Entry02008E30 {
    u16 a;
    u16 b;
};

extern struct Entry02008E30 g_0209DDA0[5];
extern int  func_02008DFC(void *p, u16 v);
extern void func_02008D58(void *p, u16 a, int b);
extern void func_02008D1C(void *p, u16 v, int z);

void func_02008E30(void *a0)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        u16 b = g_0209DDA0[i].b;

        func_02008D58(a0, g_0209DDA0[i].a, func_02008DFC(a0, b));
        func_02008D1C(a0, b, 0);
    }
}
