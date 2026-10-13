/*
 * function: BTL_ACTION_SetRotate
 * address: 0x021D83FC
 * packet: pkt_ov093_021D83FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * follower: Existing pkt_ov093_021D8414 covers 021D8414 and 021D8424.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef enum { ZERO=0 } Bits;
void BTL_ACTION_SetRotate(u32 *p,u32 sub) { Bits t=ZERO; t &=~15; t|=6; t &=~0x70; t|=(sub&7)<<4; *p=t; }
