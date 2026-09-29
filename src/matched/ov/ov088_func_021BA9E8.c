/*
 * function: func_021BA9E8
 * address:  0x021BA9E8
 * packet:   pkt_ov088_021BA9E8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-background graphics setup: bank select, BG mode header copied from
 * a 16-byte template, then seven 32-byte BG templates each copied to the
 * stack and handed to func_0203FCA0.  Twin: ov088_func_021BCF6C.c.
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_021BD678     0x021BD678  data  a4
 *   d_021BD724     0x021BD724  data  a4
 *   d_021BD764     0x021BD764  data  a4
 *   d_021BD6C4     0x021BD6C4  data  a4
 *   d_021BD6E4     0x021BD6E4  data  a4
 *   d_021BD744     0x021BD744  data  a4
 *   d_021BD6A4     0x021BD6A4  data  a4
 *   d_021BD704     0x021BD704  data  a4
 */

typedef unsigned int u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

extern A16 d_021BD678;
extern B32 d_021BD724;
extern B32 d_021BD764;
extern B32 d_021BD6C4;
extern B32 d_021BD6E4;
extern B32 d_021BD744;
extern B32 d_021BD6A4;
extern B32 d_021BD704;

extern void func_0203F8F4(int);
extern void func_0203FC28(void *);
extern void func_0203FCA0(int, void *, int);
extern void func_020434DC(int, int);
extern void func_02043598(u32 mask, u32 enable);

void func_021BA9E8(void)
{
    A16 a;
    B32 b0;
    B32 b1;
    B32 b2;
    B32 b3;
    B32 b4;
    B32 b5;
    B32 b6;

    func_0203F8F4(0xb);
    a = d_021BD678;
    func_0203FC28(&a);
    b0 = d_021BD724;
    func_0203FCA0(0, &b0, 0);
    b1 = d_021BD764;
    func_0203FCA0(1, &b1, 0);
    b2 = d_021BD6C4;
    func_0203FCA0(2, &b2, 0);
    b3 = d_021BD6E4;
    func_0203FCA0(3, &b3, 0);
    b4 = d_021BD744;
    func_0203FCA0(4, &b4, 0);
    b5 = d_021BD6A4;
    func_0203FCA0(5, &b5, 0);
    b6 = d_021BD704;
    func_0203FCA0(6, &b6, 0);
    func_020434DC(0xf, 1);
    func_02043598(7, 1);
}
