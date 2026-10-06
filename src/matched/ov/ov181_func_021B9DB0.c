/*
 * function: func_021B9DB0
 * address: 0x021B9DB0
 * packet: pkt_ov181_021B9DB0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 */
#include "../include/Obj14409.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
void func_021B9DB0(char *p){func_020452E8(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2BC);func_020452E8(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2C4);func_020450C8();}
