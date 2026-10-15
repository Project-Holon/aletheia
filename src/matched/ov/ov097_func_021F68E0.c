/*
 * function: VS_MULTI_LIST_ExitBgs
 * address: 0x021F68E0
 * packet: pkt_ov097_021F68E0
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020403F4(u32);
extern void BG_SYS_Delete(void);
void VS_MULTI_LIST_ExitBgs(void) { func_020403F4(2); func_020403F4(1); func_020403F4(0); BG_SYS_Delete(); }
