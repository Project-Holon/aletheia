/*
 * function: func_021D4D84
 * address:  0x021D4D84
 * packet:   pkt_ov093_021D4D84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-03 (wave B3 lane 03): EXACT. func_021D7D18 returns a one-word
 * union by value (as in its own matched definition). That return reserves
 * the frame word (push r4-r6 + sub sp,#8) and also stops mwcc from deriving
 * 0x272 from the hoisted 0x1f8 and 0x143 from the argument 0x9e, which was
 * the whole earlier DIFF. With a u32 return every spelling of the body
 * keeps the constant chain (push r3-r7).
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_02017F90  0x02017F90  thumb
 *   func_021D4EFC  0x021D4EFC  thumb  ov093
 *   func_021D4F84  0x021D4F84  thumb  ov093
 *   func_021D53C0  0x021D53C0  thumb  ov093
 *   func_021D63B8  0x021D63B8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D67F4  0x021D67F4  thumb  ov093
 *   func_021D6DC4  0x021D6DC4  thumb  ov093
 *   d_021F3AA4     0x021F3AA4  data  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
union Slot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};
typedef struct S {
    void *f00;
    u32 f04;
    u8 pad08[4];
    u16 f0c;
    u16 f0e;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u8 f18;
    u8 f19;
    u8 f1a;
    u8 lo : 5;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    union Slot w1c[40];
    u8 pad_bc[0xfc - 0xbc];
    u8 f0fc[8];
    u8 pad104[0x140 - 0x104];
    u8 f140;
    u8 f141;
    u8 f142;
    u8 f143;
    u8 f144;
    u8 pad145;
    u16 f146;
    u16 f148;
    u16 f14a;
    u16 f14c;
    u16 f14e;
    u8 pad150[2];
    u8 f152;
    u8 f153[2];
    u8 f155[2];
    u8 pad157[0x1f2 - 0x157];
    u16 f1f2;
    u16 f1f4;
    u8 f1f6;
    u8 pad1f7;
} S;
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02019C90(u16, u16, u32);
extern u32 func_02017F90(void *);
extern void func_021D4EFC(S *, void *, u32, u32);
extern int func_021D4F84(u8 *p, void *h, int reset);
extern void func_021D53C0(u8 *);
extern void func_021D63B8(u8 *p, int all);
extern union Slot func_021D7D18(int);
extern void func_021D67F4(u8 *p);
extern void func_021D6DC4(u8 *p);
extern const char d_021F3AA4[];
S *func_021D4D84(void *a, u8 b, u32 c)
{
    S *p;
    u32 n;

    p = sub_02030734(c, 0x1f8, 1, d_021F3AA4, 0xe3);
    p->f19 = b;
    p->f0c = func_02017E1C(a, 5, 0);
    p->f00 = a;
    p->f10 = func_02017E1C(a, 0xa0, 0);
    p->f0e = func_02017E1C(a, 0xa1, 0);
    p->f12 = func_02017E1C(a, 6, 0);
    if (p->f12 > 0x272) p->f12 = 0;
    p->f14 = 0;
    p->b5 = 0;
    p->f04 = 0;
    p->b6 = 0;
    p->b7 = 0;
    p->lo = func_02017E1C(a, 0x6f, 0);
    p->f16 = func_02017E1C(a, 0xa, 0);
    p->f18 = func_02017E1C(a, 0x9e, 0);
    p->f1a = func_02019C90(p->f0c, p->lo, 1);
    func_021D4EFC(p, a, 1, 1);
    p->f140 = func_021D4F84((u8 *)p, a, 1);
    p->f143 = 0;
    func_021D53C0(p->f0fc);
    func_021D63B8((u8 *)p, 1);
    n = func_02017F90(a);
    if (n != 0) {
        p->w1c[n] = func_021D7D18(n);
        *((u8 *)p + 0xac + n) = 0;
    }
    p->f148 = 10000;
    p->f146 = 0;
    p->f1f2 = 0;
    p->f14a = 0;
    p->f14c = 0;
    p->f144 = 0x11;
    p->f14e = 0;
    p->f1f4 = 0;
    p->f1f6 = 0x1f;
    p->f142 = 0;
    MI_CpuFill8(p->f153, 0, sizeof(p->f153));
    MI_CpuFill8(p->f155, 0, sizeof(p->f155));
    func_021D67F4((u8 *)p);
    func_021D6DC4((u8 *)p);
    return p;
}
