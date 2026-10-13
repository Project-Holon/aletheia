/*
 * function: GAME_BEACON_SetResearchTeamRank
 * address:  0x02027138
 * packet:   pkt_02027138
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (9..11) into
 * the word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * The inner-object pointer is what pins the two-step `adds r0, r1, #4` /
 * `adds r0, #0x5e` address form (see GAME_BEACON_SetPms).
 *
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Inner {
    u8  pad00[0x0c];
    u32 f0c;
    u8  pad10[0x4e];
    u8  f5e;
};

struct Outer {
    u32 f00;
    struct Inner in;
};

extern struct Outer *GAME_BEACON_Work;

void GAME_BEACON_SetResearchTeamRank(u32 x)
{
    struct Inner *in = &GAME_BEACON_Work->in;

    in->f0c = (in->f0c & 0xFFFFF1FFu) | ((x << 29) >> 20);
    in->f5e = 1;
}
