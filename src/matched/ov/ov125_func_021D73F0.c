/*
 * function: GDS_RAP_CheckSearchVideosReply
 * address: 0x021D73F0
 * packet: pkt_ov125_021D73F0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
int GDS_RAP_CheckSearchVideosReply(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }
