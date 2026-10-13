/*
 * function: FIELD_GROUND_ANIME_UnbindAnm
 * address:  0x021A7418
 * packet:   pkt_021A7418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_GROUND_ANIME_AnmEntryUnbind with no argument change.
 *
 * symbols:
 *   FIELD_GROUND_ANIME_AnmEntryUnbind  0x021A75B0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_GROUND_ANIME_AnmEntryUnbind(u32 *p);

void FIELD_GROUND_ANIME_UnbindAnm(void *p)
{
    FIELD_GROUND_ANIME_AnmEntryUnbind(p);
}
