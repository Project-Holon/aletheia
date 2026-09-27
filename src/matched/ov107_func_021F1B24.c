/*
 * function: func_021F1B24
 * address:  0x021F1B24
 * packet:   pkt_ov107_021F1B24
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0xC];
    void *f10;
    unsigned char pad14[0x24];
    int f38;
} Ov107Ctx;

void func_02045374(void *);
void func_020409B4(int);

void func_021F1B24(Ov107Ctx *p, int x)
{
    p->f38 = x;
    func_02045374(p->f10);
    func_020409B4(p->f02);
}
