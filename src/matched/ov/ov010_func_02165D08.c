/*
 * function: GAME_BEACON_ACCESSOR_GetSex
 * address:  0x02165D08
 * packet:   pkt_ov010_02165D08
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Top bit of byte 3.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Rec {
    u8 pad00[3];
    u8 lo : 7;
    u8 hi : 1;
} Rec;

u8 GAME_BEACON_ACCESSOR_GetSex(Rec *r)
{
    return r->hi;
}
