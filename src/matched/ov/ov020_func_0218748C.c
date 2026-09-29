/*
 * function: func_0218748C
 * address:  0x0218748C
 * packet:   pkt_ov020_0218748C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_02045CAC(int, u16, int);
extern void func_0201F250(int, int, int);
extern int func_0219129C(int, int, char *, int, int, int);
extern u16 d_02187E04[];

void func_0218748C(char *p, int a1, int *out, int a3, u16 a4)
{
    int i;

    func_02045CAC(*(int *)(p + 0x18),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + *(u16 *)(p + 0x4c) * 8)),
                  *(int *)(p + 0x24));
    func_0201F250(*(int *)(p + 0x1c), *(int *)(p + 0x20), *(int *)(p + 0x24));
    i = 0;
    *(int *)(p + 0x10) = func_0219129C(*(int *)(p + 0xc), 2, p + 0x34, *(int *)(p + 0x20), i, i);
    *out = 0x10;
    *(u16 *)(p + 0x4e) = a3;
    *(u16 *)(p + 0x50) = a4;
    *(u16 *)(p + 0x52) = 0;
    *(u8 *)(p + 0x54) = 1;
    *(u8 *)(p + 0x55) = 1;
}
