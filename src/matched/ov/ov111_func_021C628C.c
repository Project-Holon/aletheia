/*
 * function: func_021C628C
 * address:  0x021C628C
 * packet:   pkt_ov111_021C628C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
} Sub24;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[7];
    u8 pad20[4];
    Sub24 *f24;
    u8 pad28[0x31FC - 0x28];
    void *f31FC;
    void *f3200;
    u8 pad3204[0x3234 - 0x3204];
    void *f3234;
} Work;

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32 bit);

void func_021C628C(Work *p, int k, int flush)
{
    void *str;
    u32 w;

    str = func_02045EC0(p->f3200, k + 0x1F);
    w = func_0201D304(str, (u32)p->f31FC, 0);
    BMP_Clear(func_02045770(p->bg[2]), 0);
    PRINTSYS_Print(func_02045770(p->bg[2]), 0, 0, p->f3234, p->f31FC);
    PRINTSYS_Print(func_02045770(p->bg[2]), 0x80 - w, 0, str, p->f31FC);
    STRBUF_Delete(str);
    if (flush) {
        BMP_WIN_MakeScreen(p->bg[2]);
        BMP_WIN_TransferChars(p->bg[2]);
        func_02041B6C(7);
    }
}
