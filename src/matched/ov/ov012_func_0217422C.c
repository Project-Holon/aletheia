/*
 * function: func_0217422C
 * address: 0x0217422C
 * packet: pkt_ov012_0217422C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02175628 0x02175628 data ov012 a1
 */
typedef unsigned char u8;
extern void func_02034714(void *, int, void *);
extern u8 d_02175628[];
void func_0217422C(u8 *p, int a, int b)
{
    if (*(int *)(p + 0x354c) != 0 || *(int *)(p + 0x3548) != 0)
        func_02034714(d_02175628, 0, d_02175628);
    *(int *)(p + 0x354c) = a;
    *(int *)(p + 0x3550) = b;
    p[0x3554] = 0;
}
