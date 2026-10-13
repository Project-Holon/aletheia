/*
 * function: FIELD_PLAYER_GetFormObjCode
 * address:  0x021A3190
 * packet:   pkt_ov021_021A3190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Halfword a of entry j in row i of the 10-entry table at 0x021D890C.
 *
 * symbols:
 *   gFieldPlayerFormTable  0x021D890C  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
} Pair;

typedef struct {
    Pair e[10];
} Row;

extern const Row gFieldPlayerFormTable[];

u16 FIELD_PLAYER_GetFormObjCode(int i, int j)
{
    return gFieldPlayerFormTable[i].e[j].a;
}
