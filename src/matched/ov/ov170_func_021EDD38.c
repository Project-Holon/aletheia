/*
 * function: func_021EDD38
 * address:  0x021EDD38
 * packet:   pkt_ov170_021EDD38
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_020258E8 0x020258E8 thumb
 *   func_0202590C 0x0202590C thumb
 *   func_021DEB14 0x021DEB14 thumb
 *   func_021EDB64 0x021EDB64 thumb
 *   func_021EB874 0x021EB874 thumb
 *   func_021EC01C 0x021EC01C thumb
 */

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
typedef signed short   s16;
struct Grid;
struct Obj02025774;
extern void func_020258E8(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern unsigned char func_021DEB14(char *p, signed char a);
extern void func_021EDB64(char *p, int a, int i);
extern void func_021EB874(char *p, unsigned a, int i);
extern int func_021EC01C(char *p, int i);

void func_021EDD38(char *p, int d)
{
    short t[4];
    int step;
    int i;
    short x, y;
    int k;
    step = ((d < 0 ? -d : d) == 5) ? 2 : 8;
    if (d < 0)
        step *= -1;
    for (i = 0; i < 6u; i++) {
        func_021EC0B0(*(char **)(p + 0x2C), i + 0x2D, &t[3], &t[2], 0);
        x = t[2] + step;
        func_021EC08C(*(char **)(p + 0x2C), i + 0x2D, t[3], x, 0);
        func_020258E8(*(void **)(*(char **)(p + 0x2C) + i * 8 + 0xC), &t[1], &t[0]);
        y = t[0] + step;
        func_0202590C(*(void **)(*(char **)(p + 0x2C) + i * 8 + 0xC), t[1], y);
        if (x < -0x10) {
            k = func_021DEB14(p, 4);
            func_021EDB64(p, k, i + 0x2D);
            func_021EC08C(*(char **)(p + 0x2C), i + 0x2D, t[3], x + 0xCC, 0);
            func_021EB874(p, k, i + 1);
            func_0202590C(*(void **)(*(char **)(p + 0x2C) + i * 8 + 0xC), t[1], y + 0xCC);
        } else if (x >= 0xBA) {
            k = func_021DEB14(p, -1);
            func_021EDB64(p, k, i + 0x2D);
            func_021EC08C(*(char **)(p + 0x2C), i + 0x2D, t[3], x - 0xCC, 0);
            func_021EB874(p, k, i + 1);
            func_0202590C(*(void **)(*(char **)(p + 0x2C) + i * 8 + 0xC), t[1], y - 0xCC);
        }
    }
    if (func_021EC01C(*(char **)(p + 0x2C), 2) == 1) {
        func_021EC0B0(*(char **)(p + 0x2C), 2, &t[3], &t[2], 0);
        func_021EC08C(*(char **)(p + 0x2C), 2, t[3], t[2] + step, 0);
    }
}
