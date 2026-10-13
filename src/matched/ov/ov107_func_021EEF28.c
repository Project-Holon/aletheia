/*
 * function: func_021EEF28
 * address: 0x021EEF28
 * packet: pkt_ov107_021EEF28
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Hardware MMIO read/write at 021EEF3A..021EEF78; display and power registers.
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   func_021EF0D0 0x021EF0D0 thumb ov107
 *   d_021F6C10 0x021F6C10 data a4
 *   d_021F6B00 0x021F6B00 data a4
 *   d_021F6B50 0x021F6B50 data a4
 *   d_021F6B70 0x021F6B70 data a4
 *   d_021F6B90 0x021F6B90 data a4
 *   d_021F6BB0 0x021F6BB0 data a4
 *   d_021F6BD0 0x021F6BD0 data a4
 *   d_021F6BF0 0x021F6BF0 data a4
 *   d_021F6B10 0x021F6B10 data a4
 *   d_021F6B30 0x021F6B30 data a4
 *   gClActorInitParam 0x020A1448 data a4
 */
#include "../include/Obj00057.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispVram; struct DispConfig; struct BgTemplate; struct Bank;
struct Cfg { u32 prefix[4];u16 dimensions[6]; };
extern const struct Cfg gClActorInitParam;
extern const struct DispVram d_021F6C10;
extern struct DispConfig d_021F6B00;
extern const struct BgTemplate d_021F6B50,d_021F6B70,d_021F6B90,d_021F6BB0,d_021F6BD0,d_021F6BF0,d_021F6B10,d_021F6B30;
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0203F8F4(u16),BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_021EF0D0(u32 a, u32 b, u32 c);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void CLACT_InitSystem(const struct Cfg *,u32,u32);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
void func_021EEF28(u8 *p) {
 struct Cfg cfg;
 BG_SYS_ClearMainPlanes();BG_SYS_ClearSubPlanes();
 *(volatile u32 *)0x04000000 &= 0xffffe0ff;
 *(volatile u32 *)0x04001000 &= 0xffffe0ff;
 WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);
 WIPE_ResetWndMask((void *)0);WIPE_ResetWndMask((void *)1);
 *(volatile u16 *)0x04000050=0;
 *(volatile u16 *)0x04001050=0;
 *(volatile u16 *)0x04000304 |= 0x8000;
 BG_SYS_SetVramBanks(&d_021F6C10);
 func_0203F8F4(((struct Obj00057 *)p)->f0);BMP_WIN_Init(((struct Obj00057 *)p)->f0);
 func_0203FC28(&d_021F6B00);
 func_021EF0D0((u32)(&d_021F6B50),0,0);func_021EF0D0((u32)(&d_021F6B70),1,0);
 func_021EF0D0((u32)(&d_021F6B90),2,0);func_021EF0D0((u32)(&d_021F6BB0),3,0);
 func_021EF0D0((u32)(&d_021F6BD0),4,0);func_021EF0D0((u32)(&d_021F6BF0),5,0);
 func_021EF0D0((u32)(&d_021F6B10),6,0);func_021EF0D0((u32)(&d_021F6B30),7,0);
 if(!p[0x28])func_02040588(6,1);else func_02040588(6,0);
 cfg=gClActorInitParam;cfg.dimensions[0]=64;
 CLACT_InitSystem(&cfg,(u32)&d_021F6C10,((struct Obj00057 *)p)->f0);
 *(struct Bank * *)&((struct Obj00057 *)p)->f6C=CLACT_CreateUnit(8,0,((struct Obj00057 *)p)->f0);
 CLACT_SetUnitDefaultRenderer(*(struct Bank * *)&((struct Obj00057 *)p)->f6C);
 BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);
}
