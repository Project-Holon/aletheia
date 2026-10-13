/*
 * function: INTRUDE_COMM_StoreResultRecord
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
 *   INTRUDE_COMM_FindFreeResultSlot  0x02175C78  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Rec {
    u32 w[13];
} Rec;

typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int INTRUDE_COMM_FindFreeResultSlot(u8 *p, void *b, int c);

int INTRUDE_COMM_StoreResultRecord(u8 *a, Rec *b, int c)
{
    Rec *dst;
    int r;

    dst = (Rec *)(a + 0xac);
    if (func_0203EFC8(a + 0x78, (const u8 *)b, 0x30) != 0) {
        (a + c)[0x197] = 2;
        return 0;
    }
    r = INTRUDE_COMM_FindFreeResultSlot(a, b, c);
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
