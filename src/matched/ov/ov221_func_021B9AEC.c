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
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj02557.h"
struct Descriptor;struct Rec;extern void BMP_WIN_Delete(struct Descriptor *);extern void MSGDATA_Delete(struct Rec *);
void func_021B9AEC(char *p){unsigned char i;for(i=0;i<5;i++){struct Descriptor *q=*(struct Descriptor **)((unsigned)p+i*4+28);if(q)BMP_WIN_Delete(q);}if(*(struct Rec * *)&((struct Obj02557 *)p)->f18)MSGDATA_Delete(*(struct Rec * *)&((struct Obj02557 *)p)->f18);}
