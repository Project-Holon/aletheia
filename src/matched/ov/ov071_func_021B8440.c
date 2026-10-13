/*
 * function: func_021B8440
 * address:  0x021B8440
 * packet:   pkt_ov071_021B8440
 * region:   ov071
 * compiler: 1.1p1
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
 *   d_021BABF8     0x021BABF8  data  a1
 */

extern char d_021BABF8[];

typedef struct {
    char pad[0x3c];
    void *f3c;
    void *f40;
    void *f44;
} W;

typedef unsigned int   u32;
struct Descriptor;
struct Rec3;
struct U16Vec;
typedef unsigned char  u8;
struct CharBuf;
void func_021B8440(W *w)
{
    extern void *BMP_WIN_GetBmp(struct Descriptor *p);
    extern void func_02034714(const char *expr, u32 line, const char *file);
    extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
    extern void STRBUF_Delete(struct U16Vec *vec);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void BMP_Clear(struct CharBuf *buf, u8 value);
    extern void BMP_WIN_TransferChars(struct Descriptor *d);
    extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
    unsigned r = (unsigned)BMP_WIN_GetBmp(w->f3c);

    if (w->f40 == 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    PRINTSYS_PrintStreamDelete(w->f40);
    w->f40 = 0;
    STRBUF_Delete(w->f44);
    w->f44 = 0;
    func_02040588(5, 0);
    BMP_Clear((struct CharBuf *)r, 0xff);
    BMP_WIN_TransferChars(w->f3c);
    GF_FONT_SetTextColor(0xf, 2, 0);
}
