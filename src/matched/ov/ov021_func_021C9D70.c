/*
 * function: BSUBWAY_SCR_SetLoseScore
 * address:  0x021C9D70
 * packet:   pkt_ov021_021C9D70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Commits the +0xe counter for the current kind and redraws.
 *
 * symbols:
 *   GDS_PROFILE_SetScoreRecCountA  0x0200DB08  thumb
 *   GDS_PROFILE_MaxScoreRecCountB  0x0200DAEC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BSUBWAY_SCR_SaveRecordParty  0x021CA2DC  thumb
 *   GDS_PROFILE_ClearScoreRecCountC  0x0200DB1C  thumb
 *   GDS_PROFILE_ClearFieldRecCount03  0x0200DA14  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct Blk1AC;
struct Blk3C;
extern void GDS_PROFILE_SetScoreRecCountA(struct Blk1AC *p, u32 i, u16 v);
extern void GDS_PROFILE_MaxScoreRecCountB(struct Blk1AC *p, u32 i, u16 v);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void BSUBWAY_SCR_SaveRecordParty(u8 *p, u32 h, int flag, u16 v);
extern void GDS_PROFILE_ClearScoreRecCountC(struct Blk1AC *p, u32 i);
extern void GDS_PROFILE_ClearFieldRecCount03(struct Blk3C *p);

void BSUBWAY_SCR_SetLoseScore(u32 unused, u8 *p)
{
    u16 v = ((struct Obj00116 *)p)->fE;
    u8 kind = p[9];
    u32 h = ((struct Obj00116 *)p)->f74;

    GDS_PROFILE_SetScoreRecCountA((struct Blk1AC *)h, kind, v);
    GDS_PROFILE_MaxScoreRecCountB((struct Blk1AC *)h, kind, v);
    BSUBWAY_SCR_SaveRecordParty(p, (u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)&((struct Obj00116 *)p)->f6C)), 1, v);
    GDS_PROFILE_ClearScoreRecCountC((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind);
    GDS_PROFILE_ClearFieldRecCount03((struct Blk3C *)(((struct Obj00116 *)p)->f70));
}
