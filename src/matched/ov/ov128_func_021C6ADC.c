/*
 * function: func_021C6ADC
 * address: 0x021C6ADC
 * packet: pkt_ov128_021C6ADC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   WF2DMAP_TOUCH_TransferScreen 0x021CA4B4 thumb ov128
 */
#include "../include/Obj00329.h"
#include "../include/Obj05378.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void WF2DMAP_TOUCH_TransferScreen(char *p);
void func_021C6ADC(u8 *p,u8 *q,unsigned v)
{
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj05378 *)q)->f0),0);
    BMP_WIN_TransferChars(((struct Obj05378 *)q)->f0);
    MSGDATA_ReadString(((struct Obj00329 *)p)->f4,v,((struct Obj00329 *)p)->f18);
    WORDSET_CopyTaggedText(((struct Obj00329 *)p)->f0,((struct Obj00329 *)p)->f14,((struct Obj00329 *)p)->f18);
    TOUCHBAR_PrintAligned(q,(void *)(((struct Obj00329 *)p)->f34),0,4,(u32)(((struct Obj00329 *)p)->f14),(u32)(((struct Obj00329 *)p)->f17C),0x3c40,0);
    WF2DMAP_TOUCH_TransferScreen(((struct Obj05378 *)q)->f0);
}
