/*
 * function: APP_TASKMENU_WIN_ChangePalette
 * address:  0x020282AC
 * packet:   pkt_0202824C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_SetPalette  0x02045798  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct T {
    u32 f00;
    u8  pad04[0x18];
    u16 f1c;
    u16 f1e;
};

struct Cfg;
struct Descriptor;
extern void BMP_WIN_SetPalette(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void APP_TASKMENU_WIN_ChangePalette(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4)
{
    a1[1] = a2;
    p->f1c = a3;
    p->f1e = a4;
    BMP_WIN_SetPalette((void *)p->f00, (u8)(a2 + 1));
    func_02045374((void *)p->f00);
    func_02041B6C(func_02045730((void *)p->f00));
}
