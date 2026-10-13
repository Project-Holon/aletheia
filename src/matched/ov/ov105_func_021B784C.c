/*
 * function: IRC_RESULT_InitScreen
 * address: 0x021B784C
 * packet: pkt_ov105_021B784C
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   IRC_RESULT_InitActorSystem 0x021B7A88 thumb ov105
 *   IRC_RESULT_InitBackgrounds 0x021B78F4 thumb ov105
 *   IRC_RESULT_ScreenVBlankTask 0x021B78E0 thumb ov105
 *   func_020056A0 0x020056A0 thumb
 *   sResultVramBankConfig 0x021B89D8 data a4
 */
#include "../include/Obj22239.h"
typedef unsigned char u8;
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void IRC_RESULT_InitActorSystem(void **p, const void *config, int heap);
extern void IRC_RESULT_InitBackgrounds(void **p, int heap);
extern void IRC_RESULT_ScreenVBlankTask(int a, unsigned char *p);
extern void *func_020056A0(void (*)(void *),void *,int);
extern const u8 sResultVramBankConfig[];
void IRC_RESULT_InitScreen(u8 *p,int a) {
 MI_CpuFill8(p,0,0xb0); BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks((const struct DispVram *)sResultVramBankConfig);
 func_0204363C(0); BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes();
 IRC_RESULT_InitActorSystem((void **)(p+4),sResultVramBankConfig,a); IRC_RESULT_InitBackgrounds((void **)p,a);
 ((struct Obj22239 *)p)->fAC=func_020056A0((void (*)(void *))IRC_RESULT_ScreenVBlankTask,p,0);
}
