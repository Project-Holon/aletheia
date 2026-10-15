/*
 * function: WF2DMAP_TOUCH_PrintItem
 * address: 0x021C9FC8
 * packet: pkt_ov128_021C9FC8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 */
#include "../include/Obj00329.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct WordSet;
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
void WF2DMAP_TOUCH_PrintItem(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color)
{
    MSGDATA_ReadString(((struct Obj00329 *)q)->f4,item,((struct Obj00329 *)q)->f20);
    WORDSET_CopyTaggedText(((struct Obj00329 *)q)->f0,(void *)(((struct Obj00329 *)q)->f1C),((struct Obj00329 *)q)->f20);
    TOUCHBAR_PrintAligned(p,(void *)(*(u32 *)&((struct Obj00329 *)q)->f34),x,y,((struct Obj00329 *)q)->f1C,*(u32 *)&((struct Obj00329 *)q)->f17C,color,0);
}
