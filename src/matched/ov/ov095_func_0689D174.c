/*
 * function: BTL_DEADREC_GetCount
 * address: 0x0689D174
 * packet: pkt_ov095_0689D174
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov095/unit_0689D0FC.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;

/* One 0x31-byte slot: a count, 24 flag bytes, 24 value bytes (31 = unset). */
typedef struct {
    u8 n;
    u8 a[24];
    u8 b[24];
} Slot;

u8 BTL_DEADREC_GetCount(Slot *s, u32 i)
{
    if (i < 4)
        return s[i].n;
    return 0;
}
