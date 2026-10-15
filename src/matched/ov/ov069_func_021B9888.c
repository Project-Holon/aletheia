/*
 * function: BSUBWAY_RECORD_LIST_ReleaseBgLayers
 * address: 0x021B9888
 * packet: pkt_ov069_021B9888
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   sRecordListBgIds 0x021BA60C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_FreeLayerBuf(u32 layer);
extern void BG_SYS_Delete(void);
extern const u32 sRecordListBgIds[];
void BSUBWAY_RECORD_LIST_ReleaseBgLayers(void *p) { u32 i; for(i=0;i<5;i++) BG_SYS_FreeLayerBuf((u8)sRecordListBgIds[i]); BG_SYS_Delete(); }
