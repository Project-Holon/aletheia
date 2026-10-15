/*
 * function: DENDOU_VIEW_DrawPageCounter
 * address: 0x021DDAF0
 * packet: pkt_ov171_021DDAF0
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj00210.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct CharBuf;
struct MsgBank;
struct Obj;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void BMP_OAM_UploadChars(struct Obj *o);
void DENDOU_VIEW_DrawPageCounter(u8 *p)
{
    void *s1,*s2,*font,*text;
    u8 width,x;
    u32 w;
    if(p[0xc5f]==1) return;
    BMP_Clear(((struct Obj00210 *)p)->fC58,0);
    s1=func_02045EC0(((struct Obj00210 *)p)->fB60,3);
    width=func_0201D304(s1,*(u32 *)&((struct Obj00210 *)p)->fB58,0);
    x=(40-width)/2;
    PRINTSYS_PrintColor(((struct Obj00210 *)p)->fC58,x,4,s1,((struct Obj00210 *)p)->fB58,0x1900);
    STRBUF_Delete(s1);
    s2=func_02045EC0(((struct Obj00210 *)p)->fB60,4);
    WORDSET_SetSlotNumber(((struct Obj00210 *)p)->fB64,0,((struct Obj00210 *)p)->fC5E + 1,2,0,1);
    WORDSET_CopyTaggedText(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    font=((struct Obj00210 *)p)->fB58;
    text=((struct Obj00210 *)p)->fB68;
    w=func_0201D304(text,(u32)font,0);
    PRINTSYS_PrintColor(((struct Obj00210 *)p)->fC58,x-w,4,text,font,0x1900);
    WORDSET_SetSlotNumber(((struct Obj00210 *)p)->fB64,0,p[0xc5f],2,0,1);
    WORDSET_CopyTaggedText(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    PRINTSYS_PrintColor(((struct Obj00210 *)p)->fC58,x+width,4,((struct Obj00210 *)p)->fB68,((struct Obj00210 *)p)->fB58,0x1900);
    STRBUF_Delete(s2);
    BMP_OAM_UploadChars(((struct Obj00210 *)p)->fC54);
}
