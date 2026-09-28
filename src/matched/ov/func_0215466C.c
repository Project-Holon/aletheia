/*
 * function: func_0215466C
 * address:  0x0215466C
 * packet:   pkt_0215466C
 * region:   ov001
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator call with a callback, then a two-argument tail setup; returns the
 * allocator result.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_02154560  0x02154560  thumb  ov001
 *   func_021542C0  0x021542C0  thumb  ov001
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void func_02154560(void *obj, void *p, int a, int b);
void func_021542C0(void);

void *func_0215466C(void *p, int a)
{
    void *r6 = func_020122C0(p, 0, func_021542C0, 0x3B4);
    func_02154560(r6, p, a, 0);
    return r6;
}
