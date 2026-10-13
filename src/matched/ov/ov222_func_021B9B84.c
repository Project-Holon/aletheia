/*
 * function: func_021B9B84
 * address: 0x021B9B84
 * packet: pkt_ov222_021B9B84
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj02559.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Rec;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 MSGDATA_Delete(struct Rec *rec);
void func_021B9B84(char *p) { u8 i;for(i=0;i<5;i++){struct Descriptor *q=*(struct Descriptor **)((u32)p+(u32)i*4+28);if(q)BMP_WIN_Delete(q);}if(*(struct Rec * *)&((struct Obj02559 *)p)->f18)MSGDATA_Delete(*(struct Rec * *)&((struct Obj02559 *)p)->f18); }
