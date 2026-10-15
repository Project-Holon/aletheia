/*
 * function: IRC_RHYTHM_ExitBackgrounds
 * address: 0x021B7AD4
 * packet: pkt_ov104_021B7AD4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   sRhythmBackgroundLayers 0x021B8F5C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void BG_SYS_SetTileUnit(u32,u32,u32);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern const int sRhythmBackgroundLayers[];
void IRC_RHYTHM_ExitBackgrounds(u32 *p) { int i; BG_SYS_SetTileUnit(2,1,0); BG_SYS_DeleteHalf(5,(u16)(*p),(u16)(*p>>16)); BG_SYS_SetTileUnit(5,1,0); for(i=0;i<7;i++) BG_SYS_FreeLayerBuf((u8)sRhythmBackgroundLayers[i]); BMP_WIN_Exit(); BG_SYS_Delete(); }
