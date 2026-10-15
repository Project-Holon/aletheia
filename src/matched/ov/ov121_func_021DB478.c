/*
 * function: MYSTERY_ALBUM_SetCursor
 * address: 0x021DB478
 * packet: pkt_ov121_021DB478
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_ALBUM_SetupSlot 0x021DB54C thumb ov121
 *   MYSTERY_ALBUM_GetColumnCount 0x021DBDB8 thumb ov121
 *   MYSTERY_UTIL_SetColor 0x021D9B28 thumb ov121
 *   MYSTERY_UTIL_SetPosition 0x021D9B2C thumb ov121
 *   MYSTERY_UTIL_ShowString 0x021D9AC8 thumb ov121
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../include/Obj00828.h"
typedef unsigned short u16;
extern void MYSTERY_ALBUM_SetupSlot(char *,int,int,int,u16,u16);
extern int MYSTERY_ALBUM_GetColumnCount(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void MYSTERY_UTIL_SetColor(u8 *p, unsigned v);
extern void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);
extern void MYSTERY_UTIL_ShowString(u8 *p, int a, int b);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BG_SYS_PushTile(u32 index);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
void MYSTERY_ALBUM_SetCursor(char *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) MYSTERY_ALBUM_SetupSlot(p,a,b,c,(u16)i,heap);
    text=STRBUF_Create(128,heap);
    other=func_02045EC0(((struct Obj00828 *)p)->f1C,150);
    WORDSET_SetSlotNumber(((struct Obj00828 *)p)->f18,0,c+1,1,1,1);
    WORDSET_SetSlotNumber(((struct Obj00828 *)p)->f18,1,MYSTERY_ALBUM_GetColumnCount(p),1,1,1);
    WORDSET_CopyTaggedText(((struct Obj00828 *)p)->f18,text,other);
    MYSTERY_UTIL_SetColor(((struct Obj00828 *)p)->fAB4,0x39ea);
    MYSTERY_UTIL_SetPosition(((struct Obj00828 *)p)->fAB4,0,0,1);
    MYSTERY_UTIL_ShowString(((struct Obj00828 *)p)->fAB4,(int)text,((struct Obj00828 *)p)->f10);
    STRBUF_Delete(text);
    STRBUF_Delete(other);
    BG_SYS_PushTile(3);
}
