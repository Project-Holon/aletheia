/*
 * function: func_021B667C
 * address: 0x021B667C
 * packet: pkt_ov101_021B667C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_02082D44 0x02082D44 arm
 */
extern int func_0203D378(void);
extern void func_02082D44(void *,const void *,unsigned);
void func_021B667C(unsigned a,int b,void *c,unsigned char *d) { unsigned v; if(func_0203D378()) { func_02082D44(c,&v,4); *(unsigned *)(d+0x68+a*4)=v; } }
