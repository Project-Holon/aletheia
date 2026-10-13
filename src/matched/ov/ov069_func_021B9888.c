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
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   sRecordListBgIds 0x021BA60C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32 layer);
extern void func_0203F9B4(void);
extern const u32 sRecordListBgIds[];
void BSUBWAY_RECORD_LIST_ReleaseBgLayers(void *p) { u32 i; for(i=0;i<5;i++) func_020403F4((u8)sRecordListBgIds[i]); func_0203F9B4(); }
