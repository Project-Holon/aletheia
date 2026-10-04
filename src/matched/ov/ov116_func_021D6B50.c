/*
 * function: func_021D6B50
 * address: 0x021D6B50
 * packet: pkt_ov116_021D6B50
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two bytes zero alignment padding follow the compiled function.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0200846C 0x0200846C thumb
 */
#include "../include/Obj22619.h"
extern void func_02082BCC(void *,int,unsigned int);
extern void *func_0200846C(int);
void func_021D6B50(unsigned char *a,int b) { func_02082BCC(a,0,0x21c); ((struct Obj22619 *)a)->f218=func_0200846C(b); }
