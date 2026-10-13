/*
 * function: func_021B9C30
 * address: 0x021B9C30
 * packet: pkt_ov181_021B9C30
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_Delete 0x020437AC arm
 */
#include "../include/Obj24502.h"
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *);
void func_021B9C30(char *p){unsigned i;for(i=0;i<((struct Obj24502 *)p)->f2B8;i++)BMP_Delete(*(struct Obj020437AC **)((unsigned)p+i*8+0xb8));}
