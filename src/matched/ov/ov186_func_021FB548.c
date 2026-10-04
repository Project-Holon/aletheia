/*
 * function: func_021FB548
 * address: 0x021FB548
 * packet: pkt_ov186_021FB548
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 */
struct Actor; struct PtS { short x,y; };
extern void func_0204B454(struct Actor *,struct PtS *,unsigned int);
void func_021FB548(char *p,short *x,short *y) { struct PtS v;func_0204B454(*(struct Actor **)p,&v,(unsigned short)*(unsigned *)(p+0x10));if(x)*x=v.x;if(y)*y=v.y; }
