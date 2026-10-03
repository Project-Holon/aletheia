/*
 * function: func_021B6844
 * address:  0x021B6844
 * packet:   pkt_ov071_021B6844
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BA7D4     0x021BA7D4  data  a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_02025318  0x02025318  thumb
 *   func_02025538  0x02025538  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct S6844 {
    int w0, w4;
    u8 b8, b9, ba, bb;
    int wc;
    u16 h10, h12, h14, h16;
    int w18;
};

extern struct S6844 d_020A1448;
extern char d_021BA7D4;

struct W6844 {
    int w0;
    u8 *unk_04;
    int pad_08[3];
    void *unk_14;
    int pad_18[5];
    void *unk_2c;
};

typedef unsigned int   u32;
struct Bank;
void func_021B6844(struct W6844 *p)
{
    struct S6844 s;
    void func_0204A48C(void *, void *, int);
    struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
    void func_0204B270(struct Bank *bank);
    u8 *func_02025318(u32 a0, u8 a1, u8 a2);
    void *func_02025538(unsigned int a0, void *a1);

    s = d_020A1448;
    s.b8 = 4;
    s.b9 = 0x7c;
    s.ba = 4;
    s.bb = 0x7c;
    s.h10 = 0x60;
    s.h14 = 0x40;
    func_0204A48C(&s, &d_021BA7D4, 0x61);
    p->unk_14 = func_0204B100(0x60, 0, 0x61);
    func_0204B270(p->unk_14);
    p->unk_04 = func_02025318(0x61, 0x10, 0x10);
    p->unk_2c = func_02025538(0x61, p->unk_14);
}
