/*
 * function: func_02165794
 * address:  0x02165794
 * packet:   pkt_02165794
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_BEACON_CopyStrbufCodes  0x020270AC  thumb
 *   GAME_BEACON_ResetDetails  0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GAME_BEACON_CopyStrbufCodes();
extern int GAME_BEACON_ResetDetails();

int func_02165794(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x2f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = GAME_BEACON_CopyStrbufCodes(a0, a1);
loc_021657A6:
a0 = t4 + 0;
    a0 = GAME_BEACON_ResetDetails(a0);
loc_021657AC:
    return a0;}
