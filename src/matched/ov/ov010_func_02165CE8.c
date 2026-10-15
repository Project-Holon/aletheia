/*
 * function: GAME_BEACON_ACCESSOR_GetTrainerAppearance
 * address:  0x02165CE8
 * packet:   pkt_ov010_02165CE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the only blocker of ov032 BEACON_VIEW_LoadEntryPanel.
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetTrainerAppearance  0x02165CE8  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S {
    u8 pad0[3];
    u8 : 7;
    u8 f3 : 1;
    u8 pad4[8];
    u32 : 6;
    u32 f : 3;
};

u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(struct S *p)
{
    if (p->f3 == 0) {
        return p->f;
    }
    return p->f + 8;
}
