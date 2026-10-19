/*
 * function: HIDDEN_ITEM_GetIndex
 * address: 0x021646E8
 * packet: pkt_ov010_021646E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u16 HIDDEN_ITEM_GetIndex(u32 n){if(n<8000 || n>8799)return 0;return n-8000;}
