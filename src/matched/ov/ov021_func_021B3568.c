/*
 * function: SCRCMD_PROC_FLD_PayPrice
 * address:  0x021B3568
 * packet:   pkt_ov021_021B3568
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   BEACON_SubPoints  0x0200C29C  thumb
 *   GDS_PROFILE_SubScoreRecTotal  0x0200DA98  thumb
 */
#include "../include/Obj05049.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Blk34;
struct Sub02008C20Obj;
extern u32 BEACON_SubPoints(struct Blk34 *p, u32 v);
struct Blk1AC;
extern void GDS_PROFILE_SubScoreRecTotal(struct Blk1AC *p, u16 v);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

void SCRCMD_PROC_FLD_PayPrice(u8 *w, u32 b)
{
    if (w[0x163] == 0) {
        BEACON_SubPoints((struct Blk34 *)(((struct Obj05049 *)w)->fC), b);
        func_02008DAC((struct Sub02008C20Obj *)(((struct Obj05049 *)w)->f14), 0x16, b);
    } else {
        GDS_PROFILE_SubScoreRecTotal((struct Blk1AC *)(((struct Obj05049 *)w)->f18), b);
        func_02008DAC((struct Sub02008C20Obj *)(((struct Obj05049 *)w)->f14), 0x22, b);
    }
    func_02008DF0((struct Sub02008C20Obj *)(((struct Obj05049 *)w)->f14), 0x15);
}
