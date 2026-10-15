/*
 * function: FIELD_GROUND_ANIME_GetEntryPos
 * address:  0x021A7B08
 * packet:   pkt_021A7B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_GROUND_ANIME_GetEntryPosByMapKind with no argument change.
 *
 * symbols:
 *   FIELD_GROUND_ANIME_GetEntryPosByMapKind  0x021A811C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_GROUND_ANIME_GetEntryPosByMapKind(u32 a, u32 b);

struct V3;

void FIELD_GROUND_ANIME_GetEntryPos(int a, struct V3 *b)
{
    FIELD_GROUND_ANIME_GetEntryPosByMapKind(a, (u32)b);
}
