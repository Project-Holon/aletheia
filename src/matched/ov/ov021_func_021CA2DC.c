/*
 * function: BSUBWAY_SCR_SaveRecordParty
 * address:  0x021CA2DC
 * packet:   pkt_ov021_021CA2DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Refreshes the panel for kinds 0 and 4; kind 4 also pushes the kind and the next page number and relinks +0x74 to +0x70.
 *
 * symbols:
 *   BSUBWAY_SCR_SaveMemberParty  0x021CA4C0  thumb
 *   BSUBWAY_PLAYDATA_SetField  0x0200D914  thumb
 *   BSUBWAY_PLAYDATA_GetRound  0x0200DA54  thumb
 *   BSUBWAY_SCOREDATA_CalcRecordScore  0x0200DC94  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BSUBWAY_SCR_SaveMemberParty(u8 *p, u32 unused, int flag);
struct Blk1AC;
struct Blk3C;
struct Src;
extern void BSUBWAY_PLAYDATA_SetField(struct Blk3C *p, u32 id, const void *src);
extern u16 BSUBWAY_PLAYDATA_GetRound(struct Blk3C *p);
extern void BSUBWAY_SCOREDATA_CalcRecordScore(struct Blk1AC *p, const struct Src *q);

void BSUBWAY_SCR_SaveRecordParty(u8 *p, u32 h, int flag, u16 v)
{
    u8 b;

    switch (p[9]) {
    case 0:
        BSUBWAY_SCR_SaveMemberParty(p, h, 0);
        break;
    case 1:
        break;
    case 4:
        BSUBWAY_SCR_SaveMemberParty(p, h, 1);
        b = p[9];
        BSUBWAY_PLAYDATA_SetField((struct Blk3C *)(((struct Obj00116 *)p)->f70), 0, &b);
        b = BSUBWAY_PLAYDATA_GetRound((struct Blk3C *)(((struct Obj00116 *)p)->f70)) + 1;
        BSUBWAY_PLAYDATA_SetField((struct Blk3C *)(((struct Obj00116 *)p)->f70), 1, &b);
        BSUBWAY_SCOREDATA_CalcRecordScore((struct Blk1AC *)(((struct Obj00116 *)p)->f74), (const struct Src *)(((struct Obj00116 *)p)->f70));
        break;
    }
}
