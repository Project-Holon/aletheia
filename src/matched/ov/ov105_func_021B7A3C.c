/*
 * function: IRC_RESULT_ExitBackgrounds
 * address: 0x021B7A3C
 * packet: pkt_ov105_021B7A3C
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   sResultBackgroundLayers 0x021B89B8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32,u32,u32);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern const int sResultBackgroundLayers[];
void IRC_RESULT_ExitBackgrounds(u32 *p) {
 int i;
 BG_SYS_DeleteHalf(5,(u16)(*p),(u16)(*p>>16));
 func_02040DA8(5,1,0);
 for(i=0;i<8;i++) func_020403F4((u8)sResultBackgroundLayers[i]);
 BMP_WIN_Exit(); BG_SYS_Delete();
}
