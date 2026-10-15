/*
 * function: BSUBWAY_SCR_ChangeCommMultiMode
 * address:  0x021C9B78
 * packet:   pkt_ov021_021C9B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Remaps kind 2/7 to 3/8, pushes it to the +0x70 object and refreshes the +0xe counter from +0x74.
 *
 * symbols:
 *   GDS_PROFILE_SetFieldRecField  0x0200D914  thumb
 *   GDS_PROFILE_GetScoreRecCountC  0x0200DB44  thumb
 *   GDS_PROFILE_GetScoreRecCountA  0x0200DAC4  thumb
 *   BSUBWAY_SCR_SetWinCount  0x021CA238  thumb
 *   BSUBWAY_SCR_ClearWinCount  0x021CA250  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03617.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk1AC;
struct Blk3C;
extern void GDS_PROFILE_SetFieldRecField(struct Blk3C *p, u32 id, const void *src);
extern u32 GDS_PROFILE_GetScoreRecCountC(struct Blk1AC *p, u32 i);
extern u16 GDS_PROFILE_GetScoreRecCountA(struct Blk1AC *p, u32 i);
extern void BSUBWAY_SCR_SetWinCount(u8 *p, u16 v);
extern int BSUBWAY_SCR_ClearWinCount(u32 a);

void BSUBWAY_SCR_ChangeCommMultiMode(u8 *p)
{
    u8 v;

    if (p[9] == 2)
        v = 3;
    else if (p[9] == 7)
        v = 8;
    p[9] = v;
    GDS_PROFILE_SetFieldRecField((struct Blk3C *)(((struct Obj03617 *)p)->f70), 0, &v);
    if (GDS_PROFILE_GetScoreRecCountC((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]) == 1)
        BSUBWAY_SCR_SetWinCount(p, GDS_PROFILE_GetScoreRecCountA((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]));
    else
        BSUBWAY_SCR_ClearWinCount((u32)p);
}
