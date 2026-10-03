/*
 * function: func_021B9C58
 * address: 0x021B9C58
 * packet: pkt_ov181_021B9C58
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA4AC 0x021BA4AC thumb ov181
 */
extern void func_021BA4AC(char *,unsigned char *,void *,int);
void func_021B9C58(char *p,void *s,unsigned i){unsigned char *q=*(unsigned char **)(p+0x2d4)+i*16;if(q[9]==0)func_021BA4AC(p,q,s,0);else func_021BA4AC(p,q,s,2);}
