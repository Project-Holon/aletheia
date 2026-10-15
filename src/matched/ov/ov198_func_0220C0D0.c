/*
 * function: B_PLIST_DRAW_PrintSlotValue
 * address: 0x0220C0D0
 * packet: pkt_ov198_0220C0D0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 value and a seven-bit unsigned field preserve spill and load widths.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 */
#include "../include/Obj04598.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned char low:7; unsigned char high:1; } Bits;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void WORDSET_SetSlotFromMsgB6(struct WordSet *p, u32 i, u32 v);
void B_PLIST_DRAW_PrintSlotValue(u8 *p,int slot,int index,u16 value,u8 extra)
{
    char *elem=(char *)(p+4)+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    void *text=func_02045EC0(((struct Obj04598 *)p)->f1EA0,11);
    u32 context;
    u32 surface;
    WORDSET_SetSlotNumber(((struct Obj04598 *)p)->f1EA4,0,((Bits *)(elem+0x16))->low,3,0,1);
    WORDSET_CopyTaggedText(((struct Obj04598 *)p)->f1EA4,(void *)(((struct Obj04598 *)p)->f1EA8),text);
    context=((struct Obj04598 *)p)->f1EAC;
    surface=(u32)BMP_WIN_GetBmp(*(void **)(p+slot*8+0x1F70));
    PRINTSYS_PrintQueColor((void *)context,surface,value,extra,((struct Obj04598 *)p)->f1EA8,((struct Obj04598 *)p)->f1E9C,0x3DC0);
    (p+slot*8)[0x1F74]=1;
    STRBUF_Delete(text);
}
