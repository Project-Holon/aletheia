/*
 * function: INTRUDE_COMM_ConsumeAreaNoticeSeen
 * address:  0x0217689C
 * packet:   pkt_ov011_0217689C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Flags;

typedef unsigned int   u32;
extern u32 ZONEDATA_IsZoneGroup118To120(u32 id);

int INTRUDE_COMM_ConsumeAreaNoticeSeen(u8 *ctx, int arg)
{
    Flags *f = (Flags *)(ctx + 0x8f8);
    int b = f->b2;
    f->b2 = 0;
    if (b == 1) {
        if (ZONEDATA_IsZoneGroup118To120(arg) == 1)
            return 1;
    }
    return 0;
}
