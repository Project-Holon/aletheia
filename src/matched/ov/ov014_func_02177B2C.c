/*
 * function: NET_WHPIPE_GetEntryBeaconData
 * address: 0x02177B2C
 * packet: pkt_ov014_02177B2C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: integer address sum preserves base+0x58 and the final pointer+8;
 * plain pointer additions fold these into base+0x60 (r1 DIFF, r2 EXACT).
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_pWhPipeWork;
u8 *NET_WHPIPE_GetEntryBeaconData(int i) { u8 *base = g_pWhPipeWork; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return (u8 *)((unsigned int)(base + 0x58) + i * 0xC0) + 8; return 0; }
