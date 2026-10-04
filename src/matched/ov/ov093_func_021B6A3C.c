/*
 * function: func_021B6A3C
 * address: 0x021B6A3C
 * packet: pkt_ov093_021B6A3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 */
#include "../include/Obj00661.h"
#include "../include/Obj13267.h"
extern void func_021EE644(void *, int, int);
typedef unsigned char  u8;
extern void func_021CD938(u8 *p, void *a);
void func_021B6A3C(unsigned char *p, unsigned char *q) { if(q[0x23]) { func_021EE644(p+0x2c8, ((struct Obj00661 *)q)->f94, ((struct Obj00661 *)q)->f98); func_021CD938(((struct Obj13267 *)p)->f10,p+0x2c8); func_021CD938(((struct Obj13267 *)p)->f14,p+0x2c8); } }
