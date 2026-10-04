/*
 * function: func_021F27D4
 * address:  0x021F27D4
 * packet:   pkt_ov032_021F27D4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  label/matched. Every concrete byte is right; three call sites stay
 *           wildcarded because their targets are unlabelled arm9 leaves with no
 *           caller outside this range (Ilias's, inside arm9). Each was verified
 *           EXACT with `one --thumb` and no --region:
 *             0x020275A8  u32 func_020275A8(u32 a) { return a; }
 *             0x020275AC  u8 func_020275AC(u8 *p) { return p[0xb0e]; }
 *             0x02010F7C  u32 func_02010F7C(u32 heap)
 *                         { return func_02048F60(0x26, 0, heap); }
 *                         (func_02048F60 0x02048F60 arm, a tail call)
 *           Once those three are matched in arm9, this file is EXACT as it stands.
 *           The min of p[0x7b] and 4 must be an if/else of two stores: the
 *           ternary inverts the branch (blo for bhs; b).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 *
 * symbols:
 *   func_021F27D4  0x021F27D4  thumb
 *   func_02012A54  0x02012A54  thumb
 *   func_020275A8  0x020275A8  thumb
 *   func_02165B04  0x02165B04  thumb  ov010
 *   func_020275AC  0x020275AC  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_02008730  0x02008730  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02165B2C  0x02165B2C  thumb  ov010
 *   func_02165B10  0x02165B10  thumb  ov010
 *   func_02010F7C  0x02010F7C  thumb
 *   func_021F0684  0x021F0684  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02012A54(u32 a);
extern u32 func_020275A8(u32 a);
extern u8 func_02165B04(u32 q);
extern u8 func_020275AC(u32 a);
extern u8 func_02012FFC(void);
extern u32 func_02012EBC(u32 a);
extern u32 func_0200BE48(u32 a);
extern u32 func_0200BF10(u32 a);
extern u32 func_02012138(u32 a);
extern u32 func_0201283C(u32 a);
extern u32 func_0201292C(u32 a);
extern u32 func_0200C0E8(u32 a);
extern u32 func_0200C1DC(u32 a);
extern u32 func_02008730(u32 a);
extern u32 func_02008530(u32 a);
extern u32 func_02008550(u32 a);
extern u8 func_02008554(u32 a);
extern u32 func_02165B2C(u32 heap);
extern u32 func_02165B10(u32 heap);
extern u32 func_02010F7C(u32 heap);
extern void func_021F0684(u8 *p, u8 *a, u8 *b);

void func_021F27D4(u8 *p)
{
    u32 sv;
    u32 s2;

    *(u32 *)(p + 0x34) = func_02012A54(*(u32 *)(p + 4));
    *(u32 *)(p + 0x3c) = func_020275A8(*(u32 *)(p + 0x34));
    p[0x7b] = func_02165B04(*(u32 *)(p + 0x3c));
    p[0x7c] = func_020275AC(*(u32 *)(p + 0x34));
    if (p[0x7b] < 4)
        p[0x7d] = p[0x7b];
    else
        p[0x7d] = 4;
    p[0x7f] = 0x30;
    p[0x78] = func_02012FFC();
    sv = func_02012EBC(*(u32 *)(p + 4));
    *(u32 *)(p + 0x28) = func_0200BF10(func_0200BE48(sv));
    *(u32 *)(p + 0x1c) = func_02012138(*(u32 *)p);
    *(u32 *)(p + 0x20) = func_0201283C(*(u32 *)(p + 4));
    *(u32 *)(p + 0x18) = func_0201292C(*(u32 *)(p + 4));
    *(u32 *)(p + 0x14) = func_0200C0E8(sv);
    *(u32 *)(p + 0x2d4) = func_0200C1DC(*(u32 *)(p + 0x14));
    s2 = func_02008730(sv);
    *(u32 *)(p + 0x2c) = (u16)func_02008530(s2);
    p[0x30] = func_02008550(s2);
    p[0x31] = func_02008554(s2);
    p[0x32] = 0x15;
    *(u32 *)(p + 0x38) = func_02165B2C(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x40) = func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x44) = func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x4c) = func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x24) = func_02010F7C(*(u16 *)(p + 0x98));
    func_021F0684(p, p + 0x58, p + 0x59);
}
