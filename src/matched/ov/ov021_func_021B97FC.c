/*
 * function: FIELD_RAIL_SETTING_GetLineIndex
 * address:  0x021B97FC
 * packet:   pkt_ov021_021B97FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: the per-iteration reload of the count (ldrh in the loop) that
 * kept the earlier draft at DIFF comes from a volatile count field; every
 * non-volatile spelling hoists it like FIELD_RAIL_SETTING_GetPointIndex.
 */

typedef unsigned short u16;

typedef struct {
    char b[0x48];
} E48;

typedef struct {
    u16 h0;
    volatile u16 h2;
    char pad[0x10];
    E48 *f14;
} Obj;

int FIELD_RAIL_SETTING_GetLineIndex(Obj *p, E48 *e)
{
    int i;

    for (i = 0; i < p->h2; i++) {
        if (e == &p->f14[i]) {
            return i;
        }
    }
    return 0;
}
