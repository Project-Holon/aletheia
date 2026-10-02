/*
 * function: func_021B8DEC
 * address: 0x021B8DEC
 * packet: pkt_ov093_021B8DEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8CFC 0x021B8CFC thumb ov093
 */
extern unsigned char func_021B8CFC(char *,int);
unsigned char func_021B8DEC(char *p,unsigned char k) { unsigned char i,v,n; i=k; v=func_021B8CFC(p,k); n=0; while(i--!=0) { if(v==(unsigned char)p[i+0x428]) n++; } return n; }
