/*
 * function: ZUKAN_DETAIL_FORM_DrawFormLabel
 * address:  0x021C4D68
 * packet:   pkt_ov208_021C4D68
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The second print's y (0x11) is converted to s16 at run time (movs r3,#0x11;
 * lsls; asrs). An int or narrow local folds that conversion; a second y local
 * of enum type, set to 0x11 beside y = 1, keeps it (enum values stay out of
 * the early folding).
 *
 * symbols:
 *   BMP_WIN_GetBmp        0x02045770  arm
 *   BMP_GetWidth        0x020437DC  arm
 *   ZUKAN_DETAIL_FORM_BuildFormLabelText  0x021C47C4  thumb
 *   func_0201D304        0x0201D304  thumb
 *   PRINTSYS_PrintQueColor        0x0201C724  thumb
 *   STRBUF_Delete        0x02045808  arm
 *   ZUKAN_DETAIL_FORM_FlushPrintWindow  0x021C4B60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef enum { YP_0 = 0, YP_MAX = 0x7fffffff } YPos;

struct Ov208Menu {
    u32 f0;
    u32 font;
};

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct Bmp;
struct StrObj;
struct U16Vec;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void ZUKAN_DETAIL_FORM_BuildFormLabelText(u16 *heap, struct Ov208Menu *p, int key, u32 *outStr, u32 *outB,
                                int *outC, int *outD, u16 idx);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void ZUKAN_DETAIL_FORM_FlushPrintWindow(u16 *heap, struct Ov208Menu *p, int key, int i);

void ZUKAN_DETAIL_FORM_DrawFormLabel(u16 *heap, struct Ov208Menu *p, int key, int i, u32 print, u32 win,
                         u32 *active, u16 idx)
{
    u32 bmp;
    u16 width;
    u32 strA;
    u32 strB;
    int freeA;
    int freeB;
    int y;
    YPos y2;
    u16 w;

    bmp = (u32)BMP_WIN_GetBmp((struct Descriptor *)win);
    width = BMP_GetWidth((const struct Bmp *)bmp);
    ZUKAN_DETAIL_FORM_BuildFormLabelText(heap, p, key, &strA, &strB, &freeA, &freeB, idx);
    y = 1;
    y2 = 0x11;
    if (strB == 0)
        y = 9;
    w = func_0201D304((struct StrObj *)strA, p->font, 0);
    PRINTSYS_PrintQueColor((void *)print, bmp, (s16)((u16)((width - w) / 2)), (s16)y, strA, p->font, 0x3c40);
    if (strB != 0) {
        w = func_0201D304((struct StrObj *)strB, p->font, 0);
        PRINTSYS_PrintQueColor((void *)print, bmp, (s16)((u16)((width - w) / 2)), (s16)y2, strB, p->font, 0x3c40);
    }
    if (strA != 0 && freeA != 0)
        STRBUF_Delete((struct U16Vec *)strA);
    if (strB != 0 && freeB != 0)
        STRBUF_Delete((struct U16Vec *)strB);
    *active = 1;
    ZUKAN_DETAIL_FORM_FlushPrintWindow(heap, p, key, i);
}
