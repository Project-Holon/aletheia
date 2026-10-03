/*
 * function: func_021FB788
 * address: 0x021FB788
 * packet: pkt_ov186_021FB788
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB760 0x021FB760 thumb ov186
 */
extern unsigned short func_021FB760(void *,int);
unsigned func_021FB788(void *p) { unsigned best=0;int i;for(i=0;i<12;i++){if(best<func_021FB760(p,i)) best=func_021FB760(p,i);}return best; }
