/*
 * function: TOWNMAP_GRH_ResetDisplay
 * address:  0x021BB7BC
 * packet:   pkt_ov072_021BB7BC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb
 *   sTownMapGrhVramBanks     0x021BBBDC  data  ov072
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern char sTownMapGrhVramBanks[];

extern void BG_SYS_ClearGraphicsMemory(u32 a);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32 a);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void GF_FONT_ResetTextColor(void);

void TOWNMAP_GRH_ResetDisplay(void)
{
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)sTownMapGrhVramBanks);
    BG_SYS_SetLcdSwap(0);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    GF_FONT_ResetTextColor();
}
