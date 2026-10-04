/*
 * function: func_021DBDB4
 * address: 0x021DBDB4
 * packet: pkt_ov119_021DBDB4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_021DBD70 0x021DBD70 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB9B4 0x021DB9B4 thumb ov119
 *   func_021DF708 0x021DF708 thumb ov119
 *   func_021DA640 0x021DA640 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021D8C84 0x021D8C84 thumb ov119
 */
#include "../include/Obj03774.h"
extern void *func_021D8DD0(void *a, int b, int c, char *p);extern int func_021DBD70(void *,int,int);extern void func_020061E4(int);extern int func_021D8AA8(void *);extern void func_021D8E84(void *,int);extern void func_021DB9B4(void);extern void func_021DF708(void);extern void func_021DA640(void);extern int func_02017E88(int,int,int);extern void func_021B6558(int,int,int);extern void func_021E12F8(void *);extern void func_021D8C84(void *);
int func_021DBDB4(char *p) {int e=(int)func_021D8DD0((void *)(((struct Obj03774 *)p)->f828),((struct Obj03774 *)p)->fF98,((struct Obj03774 *)p)->fF94,p);if(func_021DBD70(p,((struct Obj03774 *)p)->fF98,((struct Obj03774 *)p)->fF94)) {func_020061E4(0x626);if(func_021D8AA8(p)==0){func_021D8E84(p,(int)func_021DB9B4);return 1;}func_021D8E84(p,(int)func_021DF708);return 1;}if(e && func_02017E88(e,0xa9,0)) {func_020061E4(0x54b);func_021B6558(((struct Obj03774 *)p)->f9C0,8,0);func_021E12F8(p);func_021D8E84(p,(int)func_021DA640);return 1;}func_021D8C84(p);((struct Obj03774 *)p)->fF98=-1;((struct Obj03774 *)p)->fF94=-1;return 0;}
