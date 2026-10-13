/*
 * function: NHTTP_RAP_RecordList_GetRecord
 * address: 0x021B9A14
 * packet: pkt_ov114_021B9A14
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
u8 *NHTTP_RAP_RecordList_GetRecord(u8 *p,u32 i) { return p+1+i*4; }
