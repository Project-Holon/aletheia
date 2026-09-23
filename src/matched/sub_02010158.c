/*
 * function: sub_02010158
 * address:  0x02010158
 * packet:   pkt_02010068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   g_0214617C     0x0214617C  data
 *   tbl_0209DEB0   0x0209DEB0  data  a2
 *   tbl_0209DED0   0x0209DED0  data  a2
 *
 * The error-code mapper of net_err.c: a reason code at obj+0xc (obj is the
 * 16-byte block the module keeps at 0x0214617C+0x48) in 0x3EE..0x3F7 maps to
 * a fixed message id; anything else indexes one of two sixteen-entry u16
 * tables by the module's +0x60 error number, picked by func_0202EB0C().
 * Wave 13: the earlier DIFF note read the pools as 0x0202617C / 0x020109B0 /
 * 0x020109D0; the words are 0x0214617C / 0x0209DEB0 / 0x0209DED0, and the
 * case 0x3F7 arm shares case 0x3EE's block (both table slots 0x12).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0202EB0C(void);
extern u8  g_0214617C[];
extern const u16 tbl_0209DEB0[];
extern const u16 tbl_0209DED0[];

u32 sub_02010158(u8 *obj)
{
    u32 v;

    switch (*(u32 *)(obj + 0xc)) {
    case 0x3ee:
    case 0x3f7:
        return 0xd;
    case 0x3f1:
        return 0x28;
    case 0x3f2:
    case 0x3f3:
    case 0x3f4:
    case 0x3f5:
    case 0x3f6:
        return 0xe;
    case 0x3f0:
        return 0x28;
    }
    if (func_0202EB0C() != 0) {
        v = *(u32 *)(g_0214617C + 0x60);
        if (v >= 0x10) {
            return 0xb;
        }
        return tbl_0209DED0[v];
    }
    v = *(u32 *)(g_0214617C + 0x60);
    if (v >= 0x10) {
        return 0xb;
    }
    return tbl_0209DEB0[v];
}
