/*
 * function: func_021BCF6C
 * address:  0x021BCF6C
 * packet:   pkt_ov088_021BCF6C
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02040EBC  0x02040EBC  arm
 *   d_021BD980     0x021BD980  data  a4
 *   d_021BD990     0x021BD990  data  a4
 */

typedef unsigned int u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

extern A16 d_021BD980;
extern B32 d_021BD990;

typedef unsigned short u16;
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(void *);
extern void func_0203FCA0(int, void *, int);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02040EBC(u32 a0, u32 a1);

void func_021BCF6C(void)
{
    A16 a;
    B32 b;

    func_0203F8F4(0x81);
    a = d_021BD980;
    func_0203FC28(&a);
    b = d_021BD990;
    func_0203FCA0(0, &b, 0);
    func_020434DC(1, 1);
    func_02040EBC(0, 0x7D8C);
    func_02040EBC(4, 0x7D8C);
}
