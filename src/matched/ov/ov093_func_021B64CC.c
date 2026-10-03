/*
 * function: func_021B64CC
 * address: 0x021B64CC
 * packet: pkt_ov093_021B64CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021EE894 0x021EE894 thumb ov093
 */
typedef unsigned char u8;
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern int func_021EE894(void *,u8);
int func_021B64CC(u8 *p) { unsigned int i; for(i=0;i<4;i++) { if(func_021B8B9C(p,i)) { if(!func_021EE894(p+0x2c8,i)) return 0; } } return 1; }
