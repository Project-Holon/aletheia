/*
 * function: func_021DEC98
 * address:  0x021DEC98
 * packet:   pkt_ov170_021DEC98
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEC64 0x021DEC64 thumb
 *   func_021EB7E8 0x021EB7E8 thumb
 *   func_021EE224 0x021EE224 thumb
 *   func_021EE234 0x021EE234 thumb
 *   func_021EE244 0x021EE244 thumb
 */

extern void func_021DEC64(int a, int b, int c, int d, int e);
extern void func_021EB7E8(char *p, unsigned box, int i);
extern void func_021EE224(char *p, int i, int v);
extern int func_021EE234(char *p, int i);
extern void func_021EE244(char *p, int i, int flag);

void func_021DEC98(char *p, int a, int dir)
{
    int d, e, i;
    char *q;
    if (dir == 0) {
        *(signed char *)(*(char **)(p + 0x2C) + 0xA178) -= 0x17;
        if (*(signed char *)(*(char **)(p + 0x2C) + 0xA178) < 0)
            *(signed char *)(*(char **)(p + 0x2C) + 0xA178) += 0x40;
    } else if (dir == 1) {
        *(signed char *)(*(char **)(p + 0x2C) + 0xA178) += 0x17;
        if (*(signed char *)(*(char **)(p + 0x2C) + 0xA178) >= 0x40)
            *(signed char *)(*(char **)(p + 0x2C) + 0xA178) -= 0x40;
    }
    q = *(char **)(p + 0x2C);
    if (*(unsigned char *)(q + 0xA179) == 0) {
        d = 0x25C;
        e = 0xE;
    } else {
        d = 0xB8;
        e = 0xF;
    }
    *(unsigned char *)(q + 0xA179) ^= 1;
    func_021DEC64((int)p, a, *(signed char *)(*(char **)(p + 0x2C) + 0xA178), d, e);
    if (dir == 2) {
        func_021EB7E8(p, (unsigned char)p[0x14], 7);
        func_021EE224(*(char **)(p + 0x2C), 8, 0);
        return;
    }
    i = 7;
    if (func_021EE234(*(char **)(p + 0x2C), 7) == 1)
        i = 8;
    func_021EB7E8(p, (unsigned char)p[0x14], i);
    func_021EE244(*(char **)(p + 0x2C), i, dir);
    func_021EE224(*(char **)(p + 0x2C), i, 1);
}
