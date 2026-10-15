/*
 * function: BG_SYS_Update
 * address:  0x020419E4
 * packet:   pkt_020416D4
 * isa:      arm
 * status:   EXACT
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * symbols:
 *   g_BgConfig     0x02146A44  data
 *   BG_SYS_CommitScroll  0x02041B94  arm
 *   BG_SYS_CommitLayers  0x02041A1C  arm
 */

typedef unsigned short u16;

struct BgConfigRecord {
    char pad_00[4];
    u16 unk04;
    u16 unk06;
};

extern struct BgConfigRecord *g_BgConfig;

extern void BG_SYS_CommitScroll(void);
extern void BG_SYS_CommitLayers(void);

void BG_SYS_Update(void)
{
    if (g_BgConfig == 0) {
        return;
    }

    BG_SYS_CommitScroll();
    BG_SYS_CommitLayers();

    g_BgConfig->unk04 = 0;
    g_BgConfig->unk06 = 0;
}
