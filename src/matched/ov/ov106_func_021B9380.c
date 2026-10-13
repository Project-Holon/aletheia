/*
 * function: IRC_RANKING_LabelSetText
 * address: 0x021B9380
 * packet: pkt_ov106_021B9380
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding after the return.
 * symbols:
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   IRC_RANKING_LabelCalcTextPos 0x021B9414 thumb ov106
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj03746.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void IRC_RANKING_LabelCalcTextPos(void *,int,int *);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void IRC_RANKING_LabelSetText(u8 *p,void *a,void *b,int c) {
 int xy[2];
 BMP_Clear(((struct Obj03746 *)p)->f0,((struct Obj03746 *)p)->f4&31);
 MSGDATA_ReadString(a,(u32)b,((struct Obj03746 *)p)->f18);
 IRC_RANKING_LabelCalcTextPos(p,c,xy);
 PRINTSYS_PrintQueColor(((struct Obj03746 *)p)->f20,(u32)(((struct Obj03746 *)p)->f0),(short)xy[0],(short)xy[1],(u32)(((struct Obj03746 *)p)->f18),c,((struct Obj03746 *)p)->f4);
 ((struct Obj03746 *)p)->f8=1;
}
