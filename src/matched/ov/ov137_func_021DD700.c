/*
 * function: GURU2_RECEIPT_PrintTitle
 * address: 0x021DD700
 * packet: pkt_ov137_021DD700
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font) {
    int width;
    width = func_0201D304(text, (u32)font, 0);
    BMP_Clear(BMP_WIN_GetBmp(p), 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p), (208-width)/2, 1, text, font, 0x480);
    BMP_WIN_TransferChars(p);
    BMP_WIN_MakeScreen(p);
    BG_SYS_PushTile((u32)BMP_WIN_GetBgLayer(p));
}
