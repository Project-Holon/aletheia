/*
 * function: PSEL_UpdateB18C
 * address: 0x021BB18C
 * packet: pkt_ov223_021BB18C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * note: 2026-10-05 (wD8 lane03): EXACT. The 0x24C slot is a pointer local `flag = (u32 *)(p + 0x24C)`
 *   set right after the desc load and written at the end (`*flag = 0`). mwcc keeps the 0x240 base from
 *   the desc load in r4, derives 0x24C from it at the top, spills only the offset and uses [r5,r0] at the
 *   store. The k/off locals and the enum type of earlier drafts are gone.
 *
 * symbols:
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_Callback 0x0201EE60 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   PSEL_CheckAF48 0x021BAF48 thumb ov223
 *   d_021BC730 0x021BC730 data a4
 *   d_021BC710 0x021BC710 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u32 d_021BC730[];
extern const u16 d_021BC710[];
struct MsgBank;
struct StrObj;
struct Descriptor;
struct U16Vec;
struct Bmp;
struct CharBuf;
struct WordSet;
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern int PSEL_CheckAF48(char *);
void PSEL_UpdateB18C(char *p, int idx)
{
    struct Descriptor *desc;
    u16 x;
    void *words;
    void *text;
    u32 *flag;
    struct StrObj *buf;
    u16 height;
    unsigned h;
    desc = *(struct Descriptor **)(p + 0x240);
    flag = (u32 *)(p + 0x24C);
    x = 0;
    words = GF_FONT_Create_EC64(*(u16 *)p);
    text = func_02045EC0(*(struct MsgBank **)(p + 0x234), d_021BC730[idx]);
    buf = (struct StrObj *)STRBUF_Create(0x40, *(u16 *)p);
    WORDSET_Callback(words, 1, d_021BC710[idx]);
    WORDSET_CopyTaggedText(words, buf, text);
    STRBUF_Delete((struct U16Vec *)text);
    WORDSET_DeleteStrbufED04(words);
    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp(desc), 0);
    func_0201D304(buf, *(unsigned *)(p + 0x18), 0);
    height = func_0201D42C(buf, *(void **)(p + 0x18));
    BMP_GetWidth(BMP_WIN_GetBmp(desc));
    h = BMP_GetHeight(BMP_WIN_GetBmp(desc));
    if (h > height)
        x = ((int)h - height) / 2;
    PRINTSYS_PrintQueColor(*(void **)(p + 0x1C), (unsigned)BMP_WIN_GetBmp(desc), 0, (s16)x, (unsigned)buf, *(unsigned *)(p + 0x18), 0x3C40);
    STRBUF_Delete((struct U16Vec *)buf);
    *flag = 0;
    PSEL_CheckAF48(p);
}
