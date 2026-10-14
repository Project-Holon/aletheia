/*
 * function: BR_BTN_DATA_GetMaxSectionCount
 * address: 0x021FB788
 * packet: pkt_ov186_021FB788
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DATA_GetSectionCount 0x021FB760 thumb ov186
 */
extern unsigned short BR_BTN_DATA_GetSectionCount(void *,int);
unsigned BR_BTN_DATA_GetMaxSectionCount(void *p) { unsigned best=0;int i;for(i=0;i<12;i++){if(best<BR_BTN_DATA_GetSectionCount(p,i)) best=BR_BTN_DATA_GetSectionCount(p,i);}return best; }
