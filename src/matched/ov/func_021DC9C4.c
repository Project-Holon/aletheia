/*
 * function: BOX2_MAIN_ResetGraphics
 * address:  0x021DC9C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *
 * Two calls after setting the first argument.
 */

typedef unsigned int   u32;
struct DispVram;
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

void BOX2_MAIN_ResetGraphics(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((void *)0x021EF7CC);
}

