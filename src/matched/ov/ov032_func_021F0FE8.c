/*
 * function: BEACON_VIEW_GetPmVersion
 * address: 0x021F0FE8
 * packet: pkt_ov032_021F0FE8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetPmVersion 0x02165C48 thumb ov010
 */

typedef unsigned int u32;
typedef struct S S;
extern u32 GAME_BEACON_ACCESSOR_GetPmVersion(S *p);
int BEACON_VIEW_GetPmVersion(S *p)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion(p)) {
    case 21: return 0;
    case 20: return 1;
    default: return 2;
    }
}
