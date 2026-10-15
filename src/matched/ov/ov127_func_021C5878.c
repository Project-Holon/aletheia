/*
 * function: WF2DMAP_OBJDRAW_GetDepth
 * address: 0x021C5878
 * packet: pkt_ov127_021C5878
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
int WF2DMAP_OBJDRAW_GetDepth(int a,int b) { if(b==1) return 250-a/4; else return 251-a/4; }
