/*
 * function: NET_WHPIPE_GetChildBitmap
 * address: 0x02177ACC
 * packet: pkt_ov014_02177ACC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   WIH_GetBitmap 0x02178E38 thumb ov014
 */

extern unsigned char *g_pWhPipeWork;
typedef unsigned short u16;
extern u16 WIH_GetBitmap(void);
unsigned int NET_WHPIPE_GetChildBitmap(void) { if (g_pWhPipeWork != 0) return WIH_GetBitmap() & 0xFFFE; return 0; }
