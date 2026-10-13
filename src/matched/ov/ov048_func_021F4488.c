/*
 * function: GIMMICK_OBJ_ELBOARD_CountHighlights
 * address: 0x021F4488
 * packet: pkt_ov048_021F4488
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
int GIMMICK_OBJ_ELBOARD_CountHighlights(unsigned char *p) { int i; int n; n=0; for(i=0;i<4;i++) if(((unsigned short *)p)[i]!=0x1ab && p[8+i]!=0xffff) n++; return n; }
