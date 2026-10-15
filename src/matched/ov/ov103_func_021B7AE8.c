/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds
 * address: 0x021B7AE8
 * packet: pkt_ov103_021B7AE8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: The packed word passes its low and high halfwords to BG_SYS_DeleteHalf; data hint omitted for sole-ref.
 * volatile: hardware register at 0x04000050 written at 021B7AEE.
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds 0x021B927C data a4
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int   u32;
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size); extern void BG_SYS_SetTileUnit(int,int,int); extern void func_020403F4(u8); extern void BMP_WIN_Exit(void); extern void BG_SYS_Delete(void); extern const int IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds[];
void IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds(unsigned *p) {int i; *(volatile u16 *)0x04000050=0; BG_SYS_DeleteHalf((int)5,(u16)(*p),(u16)(*p>>16)); BG_SYS_SetTileUnit(5,1,0); for(i=0;i<7;i++)func_020403F4(IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds[i]); BMP_WIN_Exit(); BG_SYS_Delete(); }
