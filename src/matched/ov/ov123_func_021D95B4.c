/*
 * function: func_021D95B4
 * address: 0x021D95B4
 * packet: pkt_ov123_021D95B4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
#include "../include/Obj04501.h"
typedef unsigned char  u8;
extern void func_0202F038(u8 *p);
extern unsigned char *func_0202EE8C(unsigned int,void *,unsigned char,unsigned char,unsigned short);
void func_021D95B4(char *p) { if(((struct Obj04501 *)p)->f90) { func_0202F038(((struct Obj04501 *)p)->f90); ((struct Obj04501 *)p)->f90=0; } ((struct Obj04501 *)p)->f90=func_0202EE8C(((struct Obj04501 *)p)->f88,((struct Obj04501 *)p)->f48,15,16,((struct Obj04501 *)p)->fB0); }
