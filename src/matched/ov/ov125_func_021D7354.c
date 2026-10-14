/*
 * function: GDS_RAP_CheckDownloadEntriesReply
 * address: 0x021D7354
 * packet: pkt_ov125_021D7354
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
int GDS_RAP_CheckDownloadEntriesReply(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }
