/*
 * function: MONOLITH_TOOL_SLOT_SELECT_HideMessage
 * address:  0x021B7A14
 * packet:   pkt_ov071_021B7A14
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   func_02034714  0x02034714  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02040588  0x02040588  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   d_021BABF4     0x021BABF4  data  a1
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern char d_021BABF4[];

void MONOLITH_TOOL_SLOT_SELECT_HideMessage(void **p)
{
    void *h;

    h = BMP_WIN_GetBmp(p[0]);
    if (p[2] == 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    PRINTSYS_PrintStreamDelete(p[2]);
    p[2] = 0;
    STRBUF_Delete(p[1]);
    p[1] = 0;
    func_02040588(5, 0);
    BMP_Clear(h, 0xff);
    BMP_WIN_TransferChars(p[0]);
    GF_FONT_SetTextColor(15, 2, 0);
}
