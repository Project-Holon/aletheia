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
 *   BSUBWAY_SCOREDATA_GetLevel  0x0200DC08  thumb
 *   BSUBWAY_SCOREDATA_AccessFlag  0x0200DBA0  thumb
 *   BSUBWAY_SCOREDATA_IncLevel  0x0200DBF0  thumb
 *   BSUBWAY_SCOREDATA_UpdateStreak  0x0200DC0C  thumb
 *   BSUBWAY_SCOREDATA_DecLevel  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk1AC;
extern u8 BSUBWAY_SCOREDATA_GetLevel(struct Blk1AC *p);
typedef signed int     s32;
struct Blk1AC;
extern u32 BSUBWAY_SCOREDATA_AccessFlag(struct Blk1AC *p, s32 i, u32 op);
extern void BSUBWAY_SCOREDATA_IncLevel(struct Blk1AC *p);
extern u8 BSUBWAY_SCOREDATA_UpdateStreak(struct Blk1AC *p, u32 kind);
extern void BSUBWAY_SCOREDATA_DecLevel(struct Blk1AC *p);
extern const u8 data_021DACD0[];

int BSUBWAY_SCR_UpdateStageRank(void *a, int unused, int mode)
{
    u8 state = (int)BSUBWAY_SCOREDATA_GetLevel(a);
    u32 v;

    switch (mode) {
    case 0:
        return state;
    case 3:
        BSUBWAY_SCOREDATA_AccessFlag(a, 0, 2);
        if (state == 10)
            return 0;
        BSUBWAY_SCOREDATA_IncLevel(a);
        return 1;
    case 4:
        v = BSUBWAY_SCOREDATA_UpdateStreak(a, 3);
        if (state == 1)
            return 0;
        if (v >= data_021DACD0[state - 1]) {
            BSUBWAY_SCOREDATA_DecLevel(a);
            BSUBWAY_SCOREDATA_UpdateStreak(a, 2);
            BSUBWAY_SCOREDATA_AccessFlag(a, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}
