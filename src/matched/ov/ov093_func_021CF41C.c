/*
 * function: BTL_CLIENT_ClearSlotFlags
 * address: 0x021CF41C
 * packet: pkt_ov093_021CF41C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,u32);
void BTL_CLIENT_ClearSlotFlags(u8 *p) { func_02082BCC(p+0x130,0,3); }
