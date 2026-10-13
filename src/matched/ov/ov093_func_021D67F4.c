/*
 * function: BTL_POKEPARAM_ClearHitHistory
 * address: 0x021D67F4
 * packet: pkt_ov093_021D67F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,u8,u32);
void BTL_POKEPARAM_ClearHitHistory(u8 *p) { func_02082BCC(p+0x15c,0,0x90); func_02082BCC(p+0x1ec,0,3); p[0x1ef]=0; p[0x1f0]=0; }
