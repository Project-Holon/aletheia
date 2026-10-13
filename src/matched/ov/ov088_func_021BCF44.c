/*
 * function: STARTMENU_SaveEraseClearVram
 * address:  0x021BCF44
 * packet:   pkt_ov088_021BCF44
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021BD9B0     0x021BD9B0  data  a4
 */

typedef unsigned int u32;

typedef struct Banks {
    u32 w[12];
} Banks;

extern Banks d_021BD9B0;

extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

void STARTMENU_SaveEraseClearVram(void)
{
    Banks b = d_021BD9B0;

    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)(&b));
}
