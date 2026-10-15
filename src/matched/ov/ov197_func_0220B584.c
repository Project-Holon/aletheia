/*
 * function: B_BAG_MAIN_DrawHeader
 * address: 0x0220B584
 * packet: pkt_ov197_0220B584
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: parenthesised byte-pointer plus page keeps the page load before the far-field add; a flat offset sum differs in two bytes.
 * Width: original narrows x to signed 16 bits before each 0201C724 call; s16 extern preserves those caller truncations despite owner u32 x.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   WORDSET_Callback_EF40  0x0201EF40  thumb  arm9
 */
#include "../include/Obj00314.h"
#include "../include/Obj24999.h"
#include "../include/Obj25000.h"
#include "../include/Obj25001.h"
#include "../include/Obj25002.h"
#include "../include/Obj25003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void B_BAG_MAIN_DrawHeader(char *p)
{
    void *handle=((struct Obj00314 *)p)->f118;
    void *surface=BMP_WIN_GetBmp(handle);
    void *text;
    u32 width;
    u32 x;
    void *font;
    void *lastSurface;
    BMP_Clear(surface,0);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,28);
    width=func_0201D304(text,((struct Obj24999 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    x=(BMP_WIN_GetWidth(handle)*8-width)/2;
    PRINTSYS_PrintQueColor(((struct Obj00314 *)p)->f18,(u32)surface,(s16)x,(s16)4,(u32)text,((struct Obj25000 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,29);
    WORDSET_SetSlotNumber(((struct Obj00314 *)p)->f10,0,((u8 *)p+((u8 *)p)[0x533])[0x539]+1,2,0,1);
    WORDSET_CopyTaggedText(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    PRINTSYS_PrintQueColor(((struct Obj00314 *)p)->f18,(u32)surface,(s16)(x+width),(s16)4,(u32)(((struct Obj00314 *)p)->f14),((struct Obj25001 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,30);
    WORDSET_SetSlotNumber(((struct Obj00314 *)p)->f10,0,*(s16 *)(*(char * *)&((struct Obj00314 *)p)->f0+((u8 *)p)[0x533]*2+0x38)+1,2,0,1);
    WORDSET_CopyTaggedText(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    width=func_0201D304(((struct Obj00314 *)p)->f14,((struct Obj25002 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    font=((struct Obj00314 *)p)->f18;
    lastSurface=BMP_WIN_GetBmp(((struct Obj00314 *)p)->f118);
    PRINTSYS_PrintQueColor(font,(u32)lastSurface,(s16)(x-width),(s16)4,(u32)(((struct Obj00314 *)p)->f14),((struct Obj25003 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    ((u8 *)p)[0x11C]=1;
    STRBUF_Delete(text);
}
