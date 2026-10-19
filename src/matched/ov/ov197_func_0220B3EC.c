/*
 * function: B_BAG_MAIN_DrawItemInfo
 * address: 0x0220B3EC
 * packet: pkt_ov197_0220B3EC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original narrows y to signed halfword before printer; corresponding extern keeps s16 despite owner u32.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_0220DA3C 0x0220DA3C data a4
 *   BMP_WIN_GetWidth  0x02045738  arm  arm9
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb  arm9
 */
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
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern const char d_0220DA3C[];
void B_BAG_MAIN_DrawItemInfo(char *p, u32 i, int id, int w, int unused, int y, int unused2)
{
  char *windows = p + 0x28;
  void *handle = *((void **) (windows + (w * 8)));
  void *text;
  void *font;
  void *surface;
  int page;
  char *tmp;
  u16 pad;
  u32 *tmp1;
  char *tmp2;
  BMP_Clear(BMP_WIN_GetBmp(handle), 0);
  page = ((u32) p) + (((u8 *) p)[0x533] * 0x90);
  if (((*((u16 *) ((page + (i * 4)) + 0x152))) != 0) && ((*((int *) ((*((char **) p)) + 8))) != 1))
  {
    text = func_02045EC0(*((void **) (p + 0xC)), *((u32 *) (d_0220DA3C + (id * 8))));
    page = ((u32) p) + (((u8 *) p)[0x533] * 0x90);
    WORDSET_SetSlotNumber(*((void **) (p + 0x10)), 0, *((u16 *) (((u32) (page + (i * 4))) + 0x152)), 3, 0, 1);
    tmp2 = p + 0x14;
    WORDSET_CopyTaggedText(*((void **) (p + 0x10)), *((void **) tmp2), text);
    font = *((void **) (p + 0x18));
    surface = BMP_WIN_GetBmp(*((void **) (windows + (w * 8))));
    tmp = p + 0x14;
    tmp1 = (u32 *) ((*((char **) p)) + 4);
    PRINTSYS_PrintQueColor(font, (u32)surface, (s16)0, (s16)y, (u32)(*((void **) tmp)), *tmp1, 0x3C40);
    (p + (w * 8))[0x2C] = 1;
    STRBUF_Delete(text);
  }
  else
  {
    BMP_WIN_TransferChars(handle);
  }
}
