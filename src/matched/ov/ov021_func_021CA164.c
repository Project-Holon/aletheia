/*
 * function: BSUBWAY_SCR_UpdateStageRank
 * address:  0x021CA164
 * packet:   pkt_ov021_021CA164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Steps an arm9 object by mode (0, 3, 4) and reports whether it advanced.
 *
 * symbols:
 *   GDS_PROFILE_GetScoreRecLevel  0x0200DC08  thumb
 *   GDS_PROFILE_ScoreRecFlag  0x0200DBA0  thumb
 *   GDS_PROFILE_IncScoreRecLevel  0x0200DBF0  thumb
 *   GDS_PROFILE_UpdateScoreRecStreak  0x0200DC0C  thumb
 *   GDS_PROFILE_DecScoreRecLevel  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk1AC;
extern u8 GDS_PROFILE_GetScoreRecLevel(struct Blk1AC *p);
typedef signed int     s32;
struct Blk1AC;
extern u32 GDS_PROFILE_ScoreRecFlag(struct Blk1AC *p, s32 i, u32 op);
extern void GDS_PROFILE_IncScoreRecLevel(struct Blk1AC *p);
extern u8 GDS_PROFILE_UpdateScoreRecStreak(struct Blk1AC *p, u32 kind);
extern void GDS_PROFILE_DecScoreRecLevel(struct Blk1AC *p);
extern const u8 data_021DACD0[];

int BSUBWAY_SCR_UpdateStageRank(void *a, int unused, int mode)
{
    u8 state = (int)GDS_PROFILE_GetScoreRecLevel(a);
    u32 v;

    switch (mode) {
    case 0:
        return state;
    case 3:
        GDS_PROFILE_ScoreRecFlag(a, 0, 2);
        if (state == 10)
            return 0;
        GDS_PROFILE_IncScoreRecLevel(a);
        return 1;
    case 4:
        v = GDS_PROFILE_UpdateScoreRecStreak(a, 3);
        if (state == 1)
            return 0;
        if (v >= data_021DACD0[state - 1]) {
            GDS_PROFILE_DecScoreRecLevel(a);
            GDS_PROFILE_UpdateScoreRecStreak(a, 2);
            GDS_PROFILE_ScoreRecFlag(a, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}
