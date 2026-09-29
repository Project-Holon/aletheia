/*
 * function: func_021F1484
 * address:  0x021F1484
 * packet:   pkt_ov032_021F1484
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F1484 0x021F1484 thumb
 *   func_021F1218 0x021F1218 thumb
 *   func_021F0EA4 0x021F0EA4 thumb
 *   func_021F155C 0x021F155C thumb
 */

typedef unsigned char u8;

extern void func_021F1218(u8 *e, short x, short y);
extern void func_021F0EA4(u8 *e, int a);
extern void func_021F155C(char *this, u8 *e, int a, int b, void *s);

void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s)
{
    int i;
    u8 *e;

    if (b != 0) {
        if (a == 0)
            b[2] = 5;
        else
            b[2] = 0;
        func_021F1218(b, -13 * (1 - b[2]), -40 * (1 - b[2]));
        func_021F0EA4(b, 1);
    }
    for (i = 0; i < 5; i++) {
        e = (u8 *)(this + 0x1b8) + i * 0x34;
        if (e[1] != 0xff) {
            if (c == 0 || e[0] != c[0])
                func_021F155C(this, e, a, 0, s);
        }
    }
}
