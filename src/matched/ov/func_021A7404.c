/*
 * function: FIELD_GROUND_ANIME_GetAnmEntry
 * address:  0x021A7404
 * packet:   pkt_021A74F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards p + 8 to FIELD_GROUND_ANIME_AnmSetGetEntry.
 *
 * symbols:
 *   FIELD_GROUND_ANIME_AnmSetGetEntry  0x021A74F4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_GROUND_ANIME_AnmSetGetEntry(int *p, int i);

int FIELD_GROUND_ANIME_GetAnmEntry(u8 *p, int a1)
{
    return FIELD_GROUND_ANIME_AnmSetGetEntry((int *)(p + 8), a1);
}
