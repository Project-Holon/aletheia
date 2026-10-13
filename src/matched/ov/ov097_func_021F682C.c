/*
 * function: VS_MULTI_LIST_SetVramBanks
 * address: 0x021F682C
 * packet: pkt_ov097_021F682C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gVsMultiListDispVram 0x021F761C data a4
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 gVsMultiListDispVram;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
void VS_MULTI_LIST_SetVramBanks(void) { BG_SYS_SetVramBanks((const struct DispVram *)(&gVsMultiListDispVram)); }
