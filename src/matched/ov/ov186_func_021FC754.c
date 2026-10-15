/*
 * function: BR_UTIL_SetTextFromMessage
 * address: 0x021FC754
 * packet: pkt_ov186_021FC754
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BR_UTIL_AlignText 0x021FC870 thumb ov186
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj02902.h"
typedef struct Pair {int x,y;} Pair;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BR_UTIL_AlignText(int,Pair *,const void *,void *,void *,Pair *);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void BR_UTIL_SetTextFromMessage(char *p,void *a,void *b,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f14);
    MSGDATA_ReadString(a,(u32)b,((struct Obj02902 *)p)->f10);
    BR_UTIL_AlignText(((struct Obj02902 *)p)->f18,(Pair *)(p+28),BMP_WIN_GetBmp(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f10,font,&xy);
    owner=((struct Obj02902 *)p)->f8;
    PRINTSYS_PrintQueColor(owner,(u32)BMP_WIN_GetBmp(((struct Obj02902 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02902 *)p)->f10),(u32)font,value);
    p[4]=1;
}
