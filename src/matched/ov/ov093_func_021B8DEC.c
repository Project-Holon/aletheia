/*
 * function: BTL_MAIN_GetSlotNthOfClient
 * address: 0x021B8DEC
 * packet: pkt_ov093_021B8DEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetSlotClientId 0x021B8CFC thumb ov093
 */
extern unsigned char BTL_MAIN_GetSlotClientId(char *,int);
unsigned char BTL_MAIN_GetSlotNthOfClient(char *p,unsigned char k) { unsigned char i,v,n; i=k; v=BTL_MAIN_GetSlotClientId(p,k); n=0; while(i--!=0) { if(v==(unsigned char)p[i+0x428]) n++; } return n; }
