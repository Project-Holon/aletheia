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
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   sRhythmBackgroundLayers 0x021B8F5C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02040DA8(u32,u32,u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern const int sRhythmBackgroundLayers[];
void IRC_RHYTHM_ExitBackgrounds(u32 *p) { int i; func_02040DA8(2,1,0); func_0203FB44(5,(u16)(*p),(u16)(*p>>16)); func_02040DA8(5,1,0); for(i=0;i<7;i++) func_020403F4((u8)sRhythmBackgroundLayers[i]); BMP_WIN_Exit(); func_0203F9B4(); }
