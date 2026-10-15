/*
 * function: SCRCMD_PROC_FLD_GetShopCurrency
 * address:  0x021B3350
 * packet:   pkt_ov021_021B3350
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_GetPoints  0x0200C274  thumb
 *   GDS_PROFILE_GetScoreRecTotal  0x0200DABC  thumb
 */
#include "../include/Obj09614.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Blk1AC;
struct Blk34;
extern u32 BEACON_GetPoints(struct Blk34 *p);
extern u16 GDS_PROFILE_GetScoreRecTotal(struct Blk1AC *p);

void SCRCMD_PROC_FLD_GetShopCurrency(u8 *w)
{
    if (w[0x163] == 0) {
        BEACON_GetPoints((struct Blk34 *)(((struct Obj09614 *)w)->fC));
    } else {
        GDS_PROFILE_GetScoreRecTotal((struct Blk1AC *)(((struct Obj09614 *)w)->f18));
    }
}
