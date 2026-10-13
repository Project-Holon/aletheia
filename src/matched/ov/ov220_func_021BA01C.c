/*
 * function: func_021BA01C
 * address:  0x021BA01C
 * packet:   pkt_ov220_021BA01C
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef struct Obj {
    unsigned char pad00[0x10];
    void *f10;
    unsigned char pad14[0x60 - 0x14];
    void *ptr[4];
    int done[4];
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);

void func_021BA01C(Obj *o)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (o->done[i] == 0) {
            if (func_0201C6C4(o->f10, func_02045770(o->ptr[i])) == 0) {
                void *p = o->ptr[i];
                BMP_WIN_TransferChars(p);
                BMP_WIN_MakeScreen(p);
                func_02041B6C(func_02045730(p));
                o->done[i] = 1;
            }
        }
    }
}
