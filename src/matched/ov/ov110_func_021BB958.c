/*
 * function: PMSIV_CATEGORY_DrawTitle
 * address: 0x021BB958
 * packet: pkt_ov110_021BB958
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMS_INPUT_SetSearchArg 0x021BF7D4 thumb ov110
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short   s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern u32 PMS_INPUT_VIEW_GetFont(u8 *p);
extern void PMS_INPUT_SetSearchArg(u8 *p, void *q);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32);
void PMSIV_CATEGORY_DrawTitle(char *p)
{
    u32 r7 = PMS_INPUT_VIEW_GetFont((u8 *)(*(u32 *)p));
    void *r4 = *(void **)(p + 0x94);
    void *r6 = STRBUF_Create(14, 42);
    PMS_INPUT_SetSearchArg((u8 *)(*(u32 *)(p + 4)), r6);
    BMP_Clear(BMP_WIN_GetBmp(r4), 1);
    GF_FONT_SetTextColor(15, 14, 1);
    PRINTSYS_Print(BMP_WIN_GetBmp(r4), 0, 0, r6, (void *)r7);
    STRBUF_Delete(r6);
    BMP_WIN_MakeScreen(r4);
    BMP_WIN_TransferChars(r4);
    func_02041B6C(1);
}
