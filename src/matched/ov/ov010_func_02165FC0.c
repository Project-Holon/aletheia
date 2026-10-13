/*
 * function: GAME_BEACON_ACCESSOR_GetActionViewVariant
 * address:  0x02165FC0
 * packet:   pkt_ov010_02165FC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Second byte of the two-byte table row for a record type.
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_ActionTable  0x02171CE8  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Row {
    u8 a;
    u8 b;
} Row;

extern const Row GAME_BEACON_ACCESSOR_ActionTable[];

u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 type)
{
    return GAME_BEACON_ACCESSOR_ActionTable[type].b;
}
