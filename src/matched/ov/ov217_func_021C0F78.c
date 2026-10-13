/*
 * function: func_021C0F78
 * address:  0x021C0F78
 * packet:   pkt_ov217_021C0F78
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * y = p[6] written in both arms of the x if/else: the join value has no known range, so the s16 argument is sign-extended (lsls/asrs) as in the original.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021C1090  0x021C1090  thumb  ov217
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int func_021C1090(u8 *p, void *text);
extern void PRINTSYS_PrintColor(void *w, s16 x, s16 y, void *text, void *font, u16 color);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);

struct U16Vec;

void func_021C0F78(u8 *p, struct U16Vec *text)
{
    u16 color;
    void *w;
    int x;
    int y;
    void *font;
    void *obj;
    color = ((p[8] & 31) << 10) | ((p[9] & 31) << 5) | (p[10] & 31);
    w = func_02045770(*(void **)(p + 0x18));
    BMP_Clear(w, p[10]);
    if (*(int *)(p + 0xC) != 0) {
        x = p[5] + func_021C1090(p, text);
        y = p[6];
    } else {
        x = p[5];
        y = p[6];
    }
    font = *(void **)(p + 0x10);
    PRINTSYS_PrintColor(w, x, y, text, font, color);
    if (*(int *)(p + 0x1C) != 0) {
        obj = *(void **)(p + 0x18);
        BMP_WIN_TransferChars(obj);
        BMP_WIN_MakeScreen(obj);
        func_02041B6C(func_02045730(obj));
    }
}
