/*
 * function: INTRUDE_COMM_VIEW_SetCallback
 * address: 0x021D4244
 * packet: pkt_ov122_021D4244
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_VIEW_StoreCallback 0x021D4240 thumb ov122
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void INTRUDE_COMM_VIEW_StoreCallback(u32 *p, u32 a);
void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2) {INTRUDE_COMM_VIEW_StoreCallback(p,a);}
