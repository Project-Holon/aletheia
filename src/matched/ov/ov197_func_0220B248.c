/*
 * function: B_BAG_MAIN_DrawLabels
 * address: 0x0220B248
 * packet: pkt_ov197_0220B248
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: unsigned loop bound i<=4 preserves the original cmp4/bls; i<5 differs in two bytes.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   B_BAG_MAIN_PrintLabel 0x0220B1D4 thumb ov197
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_0220DA0D 0x0220DA0D data a1
 *   BMP_WIN_GetWidth  0x02045738  arm  arm9
 *   WORDSET_Callback_EF40  0x0201EF40  thumb  arm9
 */
#include "../include/Obj03905.h"
#include "../include/Obj24992.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void B_BAG_MAIN_PrintLabel(char *,int,int,int,u16);
extern const char d_0220DA0D[];
void B_BAG_MAIN_DrawLabels(char *p)
{
    unsigned i;
    void *text;
    void *font;
    void *surface;
    for(i=0;i<=4;i++)BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*8+0x28)),0);
    B_BAG_MAIN_PrintLabel(p,0,0,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,0,1,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,2,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,3,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,2,7,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,3,6,0,0x3C40);
    if(((struct Obj03905 *)p)->f540!=0){
        text=func_02045EC0(((struct Obj03905 *)p)->fC,8);
        font=((struct Obj03905 *)p)->f18;
        surface=BMP_WIN_GetBmp(((struct Obj03905 *)p)->f48);
        PRINTSYS_PrintQueColor(font,(u32)surface,0,0,(u32)text,((struct Obj24992 *)(*(char * *)&((struct Obj03905 *)p)->f0))->f4,0x3C40);
        p[0x4C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(((struct Obj03905 *)p)->f48);
    }
    *(const char * *)&((struct Obj03905 *)p)->f59C=d_0220DA0D;
}
