/*
 * function: func_021EC8E4
 * address:  0x021EC8E4
 * packet:   pkt_ov170_021EC8E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   d_021EFCE0 0x021EFCE0 data a1
 */

typedef struct { unsigned char a; unsigned char b; } Off;
extern void func_0202CF98(int, int, signed char *, signed char *);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern const Off d_021EFCE0[];

void func_021EC8E4(char *p)
{
    signed char buf[2];
    unsigned short i;
    short x, y;
    func_0202CF98(*(int *)(*(char **)(p + 0x2C) + 0x74), 8, &buf[1], &buf[0]);
    x = buf[0] * 8;
    y = buf[1] * 8;
    for (i = 0; i < 6; i++)
        func_021EC08C(*(char **)(p + 0x2C), *(unsigned char *)(*(char **)(p + 0x2C) + i + 0x3DF0),
                      y + d_021EFCE0[i].a, x + d_021EFCE0[i].b, 0);
}
