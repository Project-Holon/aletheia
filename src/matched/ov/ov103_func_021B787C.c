/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitScene
 * address: 0x021B787C
 * packet: pkt_ov103_021B787C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Verified against the ov103 Thumb image.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   IRC_COMPATIBLE_TOUCH_TEST_InitSprites 0x021B7B3C thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds 0x021B7970 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_Init3D 0x021B7C68 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_InitMarkers 0x021B8C14 thumb ov103
 *   func_020056A0 0x020056A0 thumb
 *   IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig 0x021B92D4 data ov103 a4
 *   IRC_COMPATIBLE_TOUCH_TEST_VBlankTask 0x021B795C thumb ov103
 */
#include "../include/Obj22176.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void MI_CpuFill8(void *,int,int); extern void BG_SYS_ClearGraphicsMemory(int); extern void BG_SYS_SetVramBanks(void *); extern int func_0204363C(int); extern int BG_SYS_ResetSubDisplay(int); extern void BG_SYS_ClearMainPlanes(int); extern void IRC_COMPATIBLE_TOUCH_TEST_InitSprites(void *,void *,int); extern void IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds(void *,int); extern void IRC_COMPATIBLE_TOUCH_TEST_Init3D(void *,int); extern void IRC_COMPATIBLE_TOUCH_TEST_InitMarkers(void *,void *,int); extern int func_020056A0(void *,void *,int); extern u8 IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig[]; extern void IRC_COMPATIBLE_TOUCH_TEST_VBlankTask(void);
void IRC_COMPATIBLE_TOUCH_TEST_InitScene(u8 *p,int x) {MI_CpuFill8(p,0,0x174); BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks(IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig); BG_SYS_ClearMainPlanes(BG_SYS_ResetSubDisplay(func_0204363C(0))); IRC_COMPATIBLE_TOUCH_TEST_InitSprites(p+0xcc,IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig,x); IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds(p,x); IRC_COMPATIBLE_TOUCH_TEST_Init3D(p+4,x); IRC_COMPATIBLE_TOUCH_TEST_InitMarkers(p+0x160,p+4,x); ((struct Obj22176 *)p)->f170=func_020056A0(IRC_COMPATIBLE_TOUCH_TEST_VBlankTask,p,0); }
