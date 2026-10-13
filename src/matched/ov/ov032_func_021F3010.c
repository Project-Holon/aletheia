/*
 * function: func_021F3010
 * address:  0x021F3010
 * packet:   pkt_ov032_021F3010
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */

extern void *BMP_WIN_Create(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
struct Cfg;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    unsigned char fc;
} T;

void func_021F3010(T *p, unsigned a, unsigned b, unsigned c, unsigned char d, unsigned char e, unsigned char f)
{
    void *w;
    p->f0 = BMP_WIN_Create((void *)a, c, d, e, f, b, 1);
    p->f4 = func_02045770(p->f0);
    w = p->f0;
    p->fc = 0;
    p->f8 = w;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));
}
