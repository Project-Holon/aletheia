/*
 * function: GDS_RAP_CheckUploadVideoReply
 * address: 0x021D73B8
 * packet: pkt_ov125_021D73B8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
int GDS_RAP_CheckUploadVideoReply(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: case 7: break; default: break; } return r; }
