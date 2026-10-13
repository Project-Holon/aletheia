/*
 * function: NET_WHPIPE_SelectEntry
 * address: 0x021780C4
 * packet: pkt_ov014_021780C4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 * symbols:
 *   d_021797A4 0x021797A4 data ov014 a4
 *   WIH_SetScanTarget 0x02178714 thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *d_021797A4;
extern void WIH_SetScanTarget(u16, void *);
void NET_WHPIPE_SelectEntry(u32 i)
{
    u8 *p;
    u32 off;
    off = i * 0xC0;
    p = d_021797A4;
    WIH_SetScanTarget(*(u16 *)(p + off + 0x3E), p + 0xC + off);
}
