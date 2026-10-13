/*
 * function: INTRUDE_SUBDISP_BmpWinSetup
 * address:  0x0217D890
 * packet:   pkt_ov018_0217D890
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned int);

typedef struct {
    char pad[0x44];
    int a;
    char b;
    char pad2[3];
    int c;
    char d;
} S;

void INTRUDE_SUBDISP_BmpWinSetup(S *p)
{
    int r;
    int r2;
    char z;

    z = 0;
    r = BMP_WIN_Create(6, 0, 0, 0x20, 2, 14, 1);
    p->a = r;
    p->b = z;
    BMP_WIN_TransferChars((struct Descriptor *)r);
    BMP_WIN_MakeScreen((struct Cfg *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    r2 = BMP_WIN_Create(6, 1, 0x12, 0x1e, 4, 14, 1);
    p->c = r2;
    p->d = z;
    BMP_WIN_TransferChars((struct Descriptor *)r2);
    BMP_WIN_MakeScreen((struct Cfg *)r2);
    func_020409B4(func_02045730((struct Descriptor *)r2));
}
