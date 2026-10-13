/*
 * function: BTL_DEADREC_SetReported
 * address: 0x0689D1BC
 * packet: pkt_ov095_0689D1BC
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

void BTL_DEADREC_SetReported(Slot *s, u32 i, u32 j)
{
    if (i < 4 && j < s[i].n)
        s[i].a[j] = 1;
}
