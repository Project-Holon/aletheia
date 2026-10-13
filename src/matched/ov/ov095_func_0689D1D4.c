/*
 * function: BTL_DEADREC_GetLastPokeId
 * address: 0x0689D1D4
 * packet: pkt_ov095_0689D1D4
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

u8 BTL_DEADREC_GetLastPokeId(Slot *s)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (s[i].n != 0)
            return s[i].b[s[i].n - 1];
    }
    return 0x1f;
}
