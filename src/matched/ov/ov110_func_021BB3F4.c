/*
 * function: PMSIV_CATEGORY_MakeCategoryButtons
 * address: 0x021BB3F4
 * packet: pkt_ov110_021BB3F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare x,y before bank,font to place the four spilled locals.
 * symbols:
 *   sPmsivCategoryLabelIds 0x021C38C4 data ov110 a1
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordCount 0x021B999C thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj03240.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern const u8 sPmsivCategoryLabelIds[];
extern u32 PMS_INPUT_VIEW_GetFont(u8 *);
extern u32 PMS_INPUT_DATA_GetCategoryWordCount(u8 *, int);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
u8 *PMSIV_CATEGORY_MakeCategoryButtons(u8 *p, u8 *q)
{
    int x, y;
    void *bank;
    u32 font;
    int i;
    void *str, *win;
    u32 width;
    font = PMS_INPUT_VIEW_GetFont(*(u8 * *)&((struct Obj03240 *)p)->f0);
    bank = func_02045B38(0, 2, 145, 42);
    x = 1;
    y = 9;
    for (i = 0; i < 12; i++) {
        if (i != 0 && i % 3 == 0) { x = 1; y += 3; }
        if (PMS_INPUT_DATA_GetCategoryWordCount(*(u8 * *)&((struct Obj03240 *)p)->f8, i)) {
            str = func_02045EC0(bank, sPmsivCategoryLabelIds[i]);
            GF_FONT_SetTextColor(1, 2, 15);
        } else {
            str = func_02045EC0(bank, 13);
            GF_FONT_SetTextColor(3, 4, 15);
        }
        win = (void *)BMP_WIN_Create(1, (u8)x, (u8)y, 9, 2, 12, 1);
        BMP_Clear(BMP_WIN_GetBmp(win), 15);
        width = 72 - func_0201D304(str, font, 0);
        PRINTSYS_Print(BMP_WIN_GetBmp(win), width >> 1, 0, str, (void *)font);
        BMP_WIN_MakeScreen(win);
        BMP_WIN_TransferChars(win);
        STRBUF_Delete(str);
        *(void **)(p + i * 4 + 0x60) = win;
        q += 18;
        x += 10;
    }
    MSGDATA_Delete(bank);
    return q;
}
