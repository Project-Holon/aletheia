/*
 * function: ZUKAN_DETAIL_FORM_DrawSpeciesLabels
 * address: 0x021C4BB4
 * packet: pkt_ov208_021C4BB4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   ov208_func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   ZUKAN_DETAIL_FORM_FlushPrintWindow 0x021C4B60 thumb ov208
 *   data_020A7370 0x020A7370 data a4
 */
#include "../include/Obj01179.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Descriptor; struct MsgBank; struct StrObj; struct Bmp; struct U16Vec; struct WordSet;

struct Ov208Menu {
    u8  pad0[4];
    u32 font;
    u8  pad8[0x554 - 8];
    struct Descriptor *win[5];
    u32 active[5];
    u32 print[5];
};

struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *d);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u16 ov208_func_021BC3C0(int key);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *s);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 size, u32 heap);
extern void func_0201EFA4(struct WordSet *ws, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void ZUKAN_DETAIL_FORM_FlushPrintWindow(u16 *heap, struct Ov208Menu *p, int key, int i);
extern struct MsgBank *data_020A7370;

void ZUKAN_DETAIL_FORM_DrawSpeciesLabels(u16 *heap, struct Ov208Menu *p, int key)
{
    u8 i;
    u16 species;
    u16 width;
    struct Bmp *bmp;
    struct Bmp *bmp2;
    struct StrObj *text;
    struct WordSet *ws;
    struct WordSet *ws2;
    struct U16Vec *str;
    void *src;
    void *src2;
    for (i = 0; i <= 1; i++) {
        p->active[i] = 0;
        PRINTSYS_QUE_Clear((struct PrintSys *)p->print[i]);
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
    }
    species = ov208_func_021BC3C0(key);
    bmp = BMP_WIN_GetBmp(p->win[0]);
    text = func_02045EC0(data_020A7370, species);
    width = func_0201D304(text, p->font, 0);
    PRINTSYS_PrintQueColor((void *)p->print[0], (u32)bmp, (s16)((u16)((BMP_GetWidth(bmp) - width) / 2)), (s16)1, (u32)text, p->font, 0x3c40);
    p->active[0] = 1;
    STRBUF_Delete((struct U16Vec *)text);
    bmp2 = BMP_WIN_GetBmp(p->win[1]);
    ws = func_0201EC64(*heap);
    src = ((struct Obj01179 *)p)->f59C;
    str = STRBUF_Create(8, *heap);
    func_0201EFA4(ws, 0, ((struct Obj01179 *)p)->f54A, 2, 1, 1);
    func_0201F250(ws, str, src);
    PRINTSYS_PrintQueColor((void *)p->print[1], (u32)bmp2, (s16)0, (s16)1, (u32)str, p->font, 0x3c40);
    STRBUF_Delete(str);
    func_0201ED04(ws);
    ws2 = func_0201EC64(*heap);
    src2 = ((struct Obj01179 *)p)->f5A0;
    str = STRBUF_Create(8, *heap);
    func_0201EFA4(ws2, 0, ((struct Obj01179 *)p)->f54C, 2, 1, 1);
    func_0201F250(ws2, str, src2);
    PRINTSYS_PrintQueColor((void *)p->print[1], (u32)bmp2, (s16)0, (s16)0x11, (u32)str, p->font, 0x3c40);
    STRBUF_Delete(str);
    func_0201ED04(ws2);
    p->active[1] = 1;
    for (i = 0; i <= 1; i++)
        ZUKAN_DETAIL_FORM_FlushPrintWindow(heap, p, key, i);
}
