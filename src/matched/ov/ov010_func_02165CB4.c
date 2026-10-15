/*
 * function: GAME_BEACON_ACCESSOR_GetResearchTeamRank
 * address:  0x02165CB4
 * packet:   pkt_ov010_02165CB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov032 BEACON_VIEW_PrintEntryRank +000A: returns the three-bit field at bit 9 of the
 * fourth word of its argument.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 lo : 9;
    u32 f : 3;
    u32 hi : 20;
} S;

u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(S *a0)
{
    return a0->f;
}
