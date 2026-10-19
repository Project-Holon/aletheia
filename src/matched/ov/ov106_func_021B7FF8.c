/*
 * function: IRC_RANKING_DisplayInit
 * address: 0x021B7FF8
 * packet: pkt_ov106_021B7FF8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   IRC_RANKING_GfxInit 0x021B7D14 thumb ov106
 *   IRC_RANKING_ClactInit 0x021B7F88 thumb ov106
 *   IRC_RANKING_DisplayVBlankTask 0x021B80BC thumb ov106
 *   func_020056A0 0x020056A0 thumb
 *   gIrcRankingVramConfig 0x021B94F4 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void IRC_RANKING_GfxInit(u32 *, void *, u32);
extern void IRC_RANKING_ClactInit(void **, int, int);
extern void IRC_RANKING_DisplayVBlankTask(void *, u8 *);
extern void *func_020056A0(void (*)(void *, u8 *), void *, int);
extern const u8 gIrcRankingVramConfig[];
void IRC_RANKING_DisplayInit(u8 *p, void *a, u32 b) {
 MI_CpuFill8(p,0,0x28);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 BG_SYS_ClearGraphicsMemory(0);
 BG_SYS_SetVramBanks((const struct DispVram *)gIrcRankingVramConfig);
 BG_SYS_SetLcdSwap(1);
 BG_SYS_ResetSubDisplay();
 BG_SYS_ClearMainPlanes();
 GF_FONT_InitTextColor();
 IRC_RANKING_GfxInit((u32 *)p,a,b);
 IRC_RANKING_ClactInit((void **)(p+0x10),(int)gIrcRankingVramConfig,b);
 *(void **)(p+0x24)=func_020056A0(IRC_RANKING_DisplayVBlankTask,p,0);
}
