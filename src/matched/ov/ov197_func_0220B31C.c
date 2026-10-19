/*
 * function: B_BAG_MAIN_DrawItemName
 * address: 0x0220B31C
 * packet: pkt_ov197_0220B31C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: printer x truncates to signed halfword in original; extern keeps s16 despite owner u32.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   func_0201D304 0x0201D304 thumb
 *   d_0220DA38 0x0220DA38 data a4
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 */
#include "../include/Obj00845.h"
#include "../include/Obj24993.h"
#include "../include/Obj24994.h"
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
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern const char d_0220DA38[];
void B_BAG_MAIN_DrawItemName(char *p,u32 i,int id,int w,int unused,int unused2)
{
    char *windows=p+0x28;
    void *handle=*(void **)(windows+w*8);
    void *text;
    void *font;
    void *surface;
    u32 width;
    int page;
    BMP_Clear(BMP_WIN_GetBmp(handle),0);
    page=(u32)p+((u8 *)p)[0x533]*0x90;
    if(*(u16 *)(page+i*4+0x150)!=0){
        text=func_02045EC0(((struct Obj00845 *)p)->fC,*(u32 *)(d_0220DA38+id*8));
        page=(u32)p+((u8 *)p)[0x533]*0x90;
        WORDSET_SetSlotFromMsg36(((struct Obj00845 *)p)->f10,0,*(u16 *)(page+i*4+0x150));
        WORDSET_CopyTaggedText(((struct Obj00845 *)p)->f10,((struct Obj00845 *)p)->f14,text);
        width=func_0201D304(((struct Obj00845 *)p)->f14,((struct Obj24993 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0);
        width=BMP_WIN_GetWidth(handle)*8-width;
        font=((struct Obj00845 *)p)->f18;
        surface=BMP_WIN_GetBmp(*(void **)(windows+w*8));
        PRINTSYS_PrintQueColor(font,(u32)surface,(s16)(width/2),(s16)7,(u32)(((struct Obj00845 *)p)->f14),((struct Obj24994 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0x3C40);
        (p+w*8)[0x2C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(handle);
    }
}
