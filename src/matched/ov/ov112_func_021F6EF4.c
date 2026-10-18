/*
 * function: STA_ACT_LIGHT_CopyElemA
 * address: 0x021F6EF4
 * packet: pkt_ov112_021F6EF4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes then existing STA_ACT_LIGHT_GetElemPos, 021F6F14, 021F6F1C sources and shards.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void STA_ACT_LIGHT_CopyElemA(void *unused,u32 *p,const u32 *q) { p[2]=q[0]; p[3]=q[1]; p[4]=q[2]; }
