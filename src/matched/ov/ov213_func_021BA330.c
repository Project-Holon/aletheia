/*
 * function: func_021BA330
 * address:  0x021BA330
 * packet:   pkt_ov213_021BA330
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note:     2026-10-05: the zero is passed in each arm's call of GF_FONT_SetTextColor
 *           (call written per arm), and PRINTSYS_Print takes a fifth argument
 *           (stack word); 8 byte gap closed. EXACT* (trailing alignment).
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021BA330(void *p, int a)
{
    int z = 0;
    int q;

    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(int *)((char *)p + 0x1c))), z);
    if (*(int *)((char *)p + 0x14) == 0)
        GF_FONT_SetTextColor(5, 6, z);
    else
        GF_FONT_SetTextColor(3, 4, z);
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)(*(int *)((char *)p + 0x1c))), 1, 1, (void *)(*(int *)((char *)p + 0x18)), (void *)a);
    q = *(int *)((char *)p + 0x1c);
    BMP_WIN_TransferChars((struct Descriptor *)q);
    BMP_WIN_MakeScreen((struct Cfg *)q);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)q));
}
