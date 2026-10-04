/*
 * function: func_021F3FBC
 * address:  0x021F3FBC
 * packet:   pkt_ov194_021F3FBC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (wD3 lane 15): DIFF, full draft, 748 vs 740 bytes (extra bytes only from the two residues below,
 * everything else matches incl. both jump tables, slots, calls, pool). Residue 1: the original loads the stack
 * argument heap (ldr r5,[sp,#0x94]) before the memset call; here it comes after (tried u32 heap = hp local).
 * Residue 2: mode 0/1 does ldr r0,[sp,#0x14]; b 0x021F404C, a jump into the mode 2 tail (movs r0,#1; str [sp,#0x1c])
 * (tail merge keeps the LATER store in the original, the EARLIER one here: try swapping the source order of the
 * case 2 and case 0/1 blocks or a shared store). Mode 2 test written as if (a2 >= 8) v1c = 1 else 0 (blo target right).
 * Offsets: o+0 Obj, +8 +0xC +0x10 handles, +0x24 +0x28 +0x2C +0x30 +0x34 +0x38 text part, 0x3C bytes cleared.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020276A4  0x020276A4  thumb
 *   func_020276A8  0x020276A8  thumb
 *   func_020276AC  0x020276AC  thumb
 *   func_020276B0  0x020276B0  thumb
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_021F51E4  0x021F51E4  thumb ov194
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_021F5569     0x021F5569  data ov194
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, int v, u32 n);
extern u32  func_020275E4(void);
extern u32  func_020276A4(void);
extern u32  func_020276A8(void);
extern u32  func_020276AC(u32 a);
extern u32  func_020276B0(u32 a);
extern u32  func_0201BC3C(void);
extern u32  func_0201BABC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_0201BC40(void);
extern u32  func_0201BCB4(void);
extern u32  func_0201BB5C(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_0204ACEC(void *h, u32 a, int b, int c, u32 heap);
extern void *func_0204AC18(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern void *func_0204AF28(void *h, u32 a, u32 b, u32 heap);
extern void *func_0204A6C8(void *h, u32 a, u32 b, u32 c, u32 heap);
extern void func_02049238(void *h);
extern void *func_0204B294(void *a, void *b, void *c, void *d, const void *e, u16 f, u32 g);
extern void func_0204B92C(void *o, int v);
extern void func_0204B878(void *o, u16 v);
extern void func_0204B6F4(void *o, u32 a, u32 b);
extern void func_021F51E4(void *dst, u32 arc, u32 member, u32 index, u16 width, u16 height, int pos, int mode, u16 heap);
extern void *func_02043678(u32 a, u32 b, u32 c, u32 heap);
extern void *func_020255A0(u32 a, const void *b);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02043B5C(void *buf, u8 v);
extern void func_0201C724(u32 a, void *b, s16 c, u32 d, void *e, u32 f, u16 g);
extern const u8 d_021F5569[];

typedef struct { u16 w; u16 h; u32 pad; } Dim8;

void func_021F3FBC(u8 *o, int mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u32 hp)
{
    u32 heap = hp;
    u32 flagA = 0;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u32 v2c;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    func_02082BCC(o, 0, 0x3c);
    v2c = 0;
    switch (mode) {
    case 0:
    case 1:
        v40 = func_020275E4();
        v3c = func_020276A4();
        v38 = func_020276A8();
        v34 = func_020276AC(2);
        v30 = func_020276B0(2);
        v1c = a2;
        break;
    case 2:
        v40 = 0x20;
        v3c = flagB;
        v2c = d_021F5569[a2];
        v38 = a2 + 0x31;
        v34 = 0x41;
        v30 = 0x42;
        if (a2 >= 8) {
            v1c = 1;
        } else {
            v1c = 0;
        }
        break;
    case 3:
        flagA = 1;
        v1c = (a3 & 0xFF00) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        v40 = 7;
        v3c = func_0201BC3C();
        v38 = func_0201BABC(a2, (u8)a3, v1c, 0);
        v34 = func_0201BC40();
        v30 = func_0201BCB4();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        v40 = 0x76;
        v3c = 9;
        v38 = 8;
        v34 = 7;
        v30 = 6;
        v2c = 1;
        break;
    }
    h = func_020490F4(v40, heap);
    if (flagB != 0) {
        *(void **)(o + 8) = func_0204ACEC(h, v3c, 0, 0x40, heap);
    } else {
        *(void **)(o + 8) = func_0204AC18(h, v3c, 0, 0x40, v2c, 1, heap);
    }
    *(void **)(o + 0x10) = func_0204AF28(h, v34, v30, heap);
    flagB = 0;
    *(void **)(o + 0xC) = func_0204A6C8(h, v38, 0, 0, heap);
    func_02049238(h);
    {
        Dim8 dim;
        func_02082BCC(&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        *(void **)o = func_0204B294((void *)s0, *(void **)(o + 0xC), *(void **)(o + 8), *(void **)(o + 0x10), &dim, flagB, heap);
    }
    func_0204B92C(*(void **)o, 1);
    switch (mode) {
    case 0:
        if (a2 == 0) {
            func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            func_021F51E4(*(void **)o, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        func_0204B6F4(*(void **)o, 0, 1);
        break;
    case 2:
        func_0204B6F4(*(void **)o, 0, 1);
        break;
    case 3:
        func_0204B878(*(void **)o, 1);
        func_0204B6F4(*(void **)o, func_0201BB5C(a2, (u8)a3, (a3 & 0xFF00) >> 8, flagB), flagB);
        break;
    case 4:
        func_0204B878(*(void **)o, 2);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    case 5:
        func_0204B878(*(void **)o, 5);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u8 st[0x18];
        h2 = func_020490F4(0x17, heap);
        *(void **)(o + 0x30) = func_02043678(2, 2, 0x20, heap);
        *(void **)(o + 0x24) = func_0204ACEC(h2, 5, 0, 0xA0, heap);
        func_02049238(h2);
        func_02082BCC(st, 0, 0x18);
        *(void **)(st + 0) = *(void **)(o + 0x30);
        *(u16 *)(st + 4) = 0x2e;
        *(u16 *)(st + 6) = 0x14;
        *(void **)(st + 8) = *(void **)(o + 0x24);
        *(void **)(o + 0x2C) = func_020255A0(s4, st);
        if (v1c == 1) {
            r = 0x32;
            *(void **)(o + 0x28) = func_02045EC0(s3, 0x11);
        } else {
            r = 0x53;
            *(void **)(o + 0x28) = func_02045EC0(s3, 0x10);
        }
        r = r << 6;
        func_02043B5C(*(void **)(o + 0x30), 0);
        func_0201C724(s2, *(void **)(o + 0x30), 0, 0, *(void **)(o + 0x28), s1, r);
        *(u32 *)(o + 0x38) = s2;
        *(u32 *)(o + 0x34) = 1;
    }
}
