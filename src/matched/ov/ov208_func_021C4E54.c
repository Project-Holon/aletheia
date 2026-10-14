/*
 * function: ZUKAN_DETAIL_FORM_DrawFormLabelMain
 * address:  0x021C4E54
 * packet:   pkt_ov208_021C4E54
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Clear        0x0201C6EC  thumb
 *   BMP_WIN_GetBmp        0x02045770  arm
 *   BMP_Clear        0x02043B5C  arm
 *   BMP_WIN_TransferChars        0x02045334  arm
 *   ZUKAN_DETAIL_FORM_DrawFormLabel  0x021C4D68  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u32 f0;
    u32 font;
    u8  pad8[0x540];
    u16 count;
    u16 pad54a[2];
    u16 sel;
    u16 sel2;
    u16 pad552;
    u32 win[5];
    u32 active[5];
    u32 print[5];
    u8  pad590[0x128];
    u32 state;
};

struct CharBuf;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void ZUKAN_DETAIL_FORM_DrawFormLabel(u16 *heap, struct Ov208Menu *p, int key, int i, u32 print, u32 win,
                                u32 *active, u16 idx);

void ZUKAN_DETAIL_FORM_DrawFormLabelMain(u16 *heap, struct Ov208Menu *p, int key)
{
    p->active[3] = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)p->print[3]);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[3])), 0);
    ZUKAN_DETAIL_FORM_DrawFormLabel(heap, p, key, 3, p->print[3], p->win[3], &p->active[3], p->sel);
}
