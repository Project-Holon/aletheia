/*
 * function: MUSICAL_SHOT_SYS_InitGraphics
 * address: 0x021F3A54
 * packet: pkt_ov112_021F3A54
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware read-modify-writes at 0x021F3A64, 0x021F3A6E,
 *   0x021F3A94 (0x04000000, 0x04001000, 0x04000304).
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021F816C 0x021F816C data a4
 *   d_021F815C 0x021F815C data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 */
#include "../include/Obj10296.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
typedef unsigned int   u32;
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
struct Cfg;
extern u32 WIPE_ResetWndMask(void *win);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern char d_021F816C[],d_021F815C[],gClActorInitParam[];
void MUSICAL_SHOT_SYS_InitGraphics(u8 *p)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile unsigned *)0x04000000 &= 0xffffe0ff;
    *(volatile unsigned *)0x04001000 &= 0xffffe0ff;
    WIPE_SetBrightnessFadeOut(0,0);
    WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021F816C);
    BG_SYS_Create(((struct Obj10296 *)p)->f0);
    BMP_WIN_Init(((struct Obj10296 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021F815C);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021F816C,((struct Obj10296 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(16,1);
}
