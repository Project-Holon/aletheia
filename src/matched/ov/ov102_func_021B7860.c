/*
 * function: IRC_COMPATIBLE_MENU_InitDisplay
 * address: 0x021B7860
 * packet: pkt_ov102_021B7860
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021B787A and 0x021B7884 read display registers for update.
 * symbols:
 * MI_CpuFill8 0x02082BCC arm
 * BG_SYS_ClearGraphicsMemory 0x0204335C arm
 * BG_SYS_SetLcdSwap 0x0204363C arm
 * BG_SYS_ResetSubDisplay 0x0204361C arm
 * BG_SYS_SetVramBanks 0x020433E0 arm
 * IRC_COMPATIBLE_MENU_InitSprites 0x021B7AB4 thumb ov102
 * IRC_COMPATIBLE_MENU_VBlankTask 0x021B78FC thumb ov102
 * func_020056A0 0x020056A0 thumb
 * IRC_COMPATIBLE_MENU_VramBankConfig 0x021B8B2C data a4
 */
#include "../include/Obj22140.h"
extern void MI_CpuFill8(void *,int,unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetLcdSwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void IRC_COMPATIBLE_MENU_InitSprites(void *,const void *,unsigned);
extern void IRC_COMPATIBLE_MENU_VBlankTask(unsigned,void *);
extern unsigned func_020056A0(void (*)(unsigned,void *),void *,unsigned);
extern unsigned IRC_COMPATIBLE_MENU_VramBankConfig[];
void IRC_COMPATIBLE_MENU_InitDisplay(char *p,unsigned b) {
 MI_CpuFill8(p,0,0x94);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 BG_SYS_ClearGraphicsMemory(0);
 BG_SYS_SetLcdSwap(0);
 BG_SYS_ResetSubDisplay();
 BG_SYS_SetVramBanks((const struct DispVram *)IRC_COMPATIBLE_MENU_VramBankConfig);
 IRC_COMPATIBLE_MENU_InitSprites(p,IRC_COMPATIBLE_MENU_VramBankConfig,b);
 ((struct Obj22140 *)p)->f90=func_020056A0(IRC_COMPATIBLE_MENU_VBlankTask,p,0);
}
