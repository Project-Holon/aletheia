/*
 * function: IRC_RHYTHM_InitScreen
 * address: 0x021B78EC
 * packet: pkt_ov104_021B78EC
 * region: ov104
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
 *   IRC_RHYTHM_InitActorSystem 0x021B7B2C thumb ov104
 *   IRC_RHYTHM_InitBackgrounds 0x021B7994 thumb ov104
 *   IRC_RHYTHM_ScreenVBlankTask 0x021B7980 thumb ov104
 *   func_020056A0 0x020056A0 thumb
 *   sRhythmVramBankConfig 0x021B8F78 data a4
 */
#include "../include/Obj22215.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void IRC_RHYTHM_InitActorSystem(void *,const void *,int);
extern void IRC_RHYTHM_InitBackgrounds(void *,int);
extern void IRC_RHYTHM_ScreenVBlankTask(u32 unused, u8 *p);
extern void *func_020056A0(void (*)(void *),void *,int);
extern const u8 sRhythmVramBankConfig[];
void IRC_RHYTHM_InitScreen(u8 *p,int a) { MI_CpuFill8(p,0,0xbc); BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks((const struct DispVram *)sRhythmVramBankConfig); func_0204363C(0); BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); IRC_RHYTHM_InitActorSystem(p+4,sRhythmVramBankConfig,a); IRC_RHYTHM_InitBackgrounds(p,a); ((struct Obj22215 *)p)->fB8=func_020056A0((void (*)(void *))IRC_RHYTHM_ScreenVBlankTask,p,0); }
