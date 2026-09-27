/*
 * function: func_021F19E4
 * address:  0x021F19E4
 * packet:   pkt_ov107_021F19E4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201FDA0  0x0201FDA0  thumb
 */

typedef struct {
    unsigned char f00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
} Ov107Win;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0x44];
    Ov107Win win;
    unsigned char pad4E[2];
    void *f50;
} Ov107Ctx;

void *func_0201FDA0(Ov107Win *win, int base, int pal, int pos, int heap);

void func_021F19E4(Ov107Ctx *p)
{
    p->win.f00 = p->f03;
    p->win.f01 = 0x18;
    p->win.f02 = 0xD;
    p->win.f03 = 0xE;
    p->win.f04 = 0;
    p->f50 = func_0201FDA0(&p->win, 1, 0xD, 0, p->f00);
}
