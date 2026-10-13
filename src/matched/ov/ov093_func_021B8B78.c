/*
 * function: BTL_MAIN_CountClientTrainers
 * address: 0x021B8B78
 * packet: pkt_ov093_021B8B78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
unsigned int BTL_MAIN_CountClientTrainers(unsigned char *p, int k) { unsigned int n,i; i=0; n=0; for(;i<6;i++) { if(k==p[i+0x428]) n++; } return n; }
