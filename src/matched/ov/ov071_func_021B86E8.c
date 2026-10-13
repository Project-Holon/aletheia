/*
 * function: func_021B86E8
 * address:  0x021B86E8
 * packet:   pkt_ov071_021B86E8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    int h[2];
    struct {
        int h;
        unsigned char on;
    } e[2];
} P;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Cfg;
void func_021B86E8(int unused, P *p)
{
    extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern void BMP_WIN_TransferChars(struct Descriptor *d);
    extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
    extern void func_020409B4(unsigned int index);
    int i;

    p->h[0] = BMP_WIN_Create(0, 2, 0, 0x1c, 3, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[0]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[0]);
    p->h[1] = BMP_WIN_Create(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[1]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[1]);
    for (i = 0; i < 2; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}
