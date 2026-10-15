/*
 * function: TH_AWARD_DeleteWindows
 * address: 0x021B9FF0
 * packet: pkt_ov220_021B9FF0
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj01297.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Rec;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 MSGDATA_Delete(struct Rec *rec);
void TH_AWARD_DeleteWindows(u8*p){u8 i;for(i=0;i<4;i++)if(*(struct Descriptor**)(p+96+i*4))BMP_WIN_Delete(*(struct Descriptor**)(p+96+i*4));if(*(struct Rec* *)&((struct Obj01297 *)p)->f5C)MSGDATA_Delete(*(struct Rec* *)&((struct Obj01297 *)p)->f5C);}
