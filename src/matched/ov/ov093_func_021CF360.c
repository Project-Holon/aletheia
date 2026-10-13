/*
 * function: BTL_CLIENT_ClearSlotLinkWords
 * address: 0x021CF360
 * packet: pkt_ov093_021CF360
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_CLIENT_ClearSlotLinkWords(u8 *p) { u32 i; for(i=0;i<3;i++) *(u16 *)(p+0x1a0+i*2)=0; }
