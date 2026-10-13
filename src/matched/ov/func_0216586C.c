/*
 * function: GAME_BEACON_SEARCH_SetInfoFreeText
 * address:  0x0216586C
 * packet:   pkt_0216586C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_ToChars  0x02045A38  arm
 *   GAME_BEACON_ResetDetails  0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int STRBUF_ToChars();
extern int GAME_BEACON_ResetDetails();

int GAME_BEACON_SEARCH_SetInfoFreeText(int a0, int a1)
{
    int a2;
    int t4;

t4 = a0 + 0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
a2 = 9;
    a0 = STRBUF_ToChars(a0, a1, a2);
loc_0216587C:
a0 = 0x31;
((struct Obj00121 *)t4)->f30 = a0;
a0 = t4 + 0;
    a0 = GAME_BEACON_ResetDetails(a0);
loc_02165886:
    return a0;}
