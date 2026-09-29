/*
 * function: func_02175C88
 * address:  0x02175C88
 * packet:   pkt_ov011_02175C88
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02175C78  0x02175C78  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Rec {
    u32 w[13];
} Rec;

extern int func_0203EFC8(const void *a, const void *b, u32 n);
extern int func_02175C78(void *a, void *b, int c);

int func_02175C88(u8 *a, Rec *b, int c)
{
    Rec *dst;
    int r;

    dst = (Rec *)(a + 0xac);
    if (func_0203EFC8(a + 0x78, b, 0x30) != 0) {
        (a + c)[0x197] = 2;
        return 0;
    }
    r = func_02175C78(a, b, c);
    if (r == 3) {
        (a + c)[0x197] = 2;
        return 0;
    }
    *dst = *b;
    ((u8 *)dst + r)[0x34] = c;
    (a + c)[0x197] = 1;
    a[0x19b] = 1;
    return 1;
}
