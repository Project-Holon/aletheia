/*
 * function: func_021B9AEC
 * address: 0x021B9AEC
 * packet: pkt_ov221_021B9AEC
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj02557.h"
struct Descriptor;struct Rec;extern void func_020452E8(struct Descriptor *);extern void func_02045C04(struct Rec *);
void func_021B9AEC(char *p){unsigned char i;for(i=0;i<5;i++){struct Descriptor *q=*(struct Descriptor **)((unsigned)p+i*4+28);if(q)func_020452E8(q);}if(*(struct Rec * *)&((struct Obj02557 *)p)->f18)func_02045C04(*(struct Rec * *)&((struct Obj02557 *)p)->f18);}
