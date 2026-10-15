/*
 * function: GURU2_RECEIPT_ExitBg
 * address: 0x021DD3B0
 * packet: pkt_ov137_021DD3B0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void BG_SYS_FreeLayerBuf(u32);
extern void BG_SYS_Delete(void);
void GURU2_RECEIPT_ExitBg(u32 a0) {BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(0);BG_SYS_Delete();}
