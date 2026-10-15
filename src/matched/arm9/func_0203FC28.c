/*
 * unit:     no
 * function: BG_SYS_SetGraphicsMode
 * address:  0x0203FC28
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   func_0207D518  0x0207D518  arm
 *   BG_SYS_ClearMainBgPlanes  0x0204349C  arm
 *   BG_SYS_ClearSubBgPlanes  0x02043558  arm
 *
 * TU: bg_sys.c (the initialiser at 0x0203FCA0 is the next function up).
 *
 * Bring the display back up from a saved four-word config block, then clear
 * REG_DISPCNT's two mode fields.  The two clears are separate read-modify-
 * writes in the original, each reloading through the base kept in r1, so
 * they are two statements in the source and not one masked store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetGraphicsMode.c \
 *       --func BG_SYS_SetGraphicsMode --addr 0x0203FC28 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D518(u32 a);
extern void BG_SYS_ClearMainBgPlanes(void);
extern void BG_SYS_ClearSubBgPlanes(void);

void BG_SYS_SetGraphicsMode(struct DispConfig *cfg)
{
    GX_SetGraphicsMode(cfg->unk_00, cfg->unk_04, cfg->unk_0c);
    func_0207D518(cfg->unk_08);
    REG_DISPCNT &= ~0x38000000;
    REG_DISPCNT &= ~0x07000000;
    BG_SYS_ClearMainBgPlanes();
    BG_SYS_ClearSubBgPlanes();
}
