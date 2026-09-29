/*
 * function: func_021D19F4
 * address:  0x021D19F4
 * packet:   pkt_ov016_021D19F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispCell (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   func_021D4FEC  0x021D4FEC  arm  ov016
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D4FF4  0x021D4FF4  arm  ov016
 */

typedef enum {
    EFF_NONE = 0,
    EFF_HIDE = 0x200
} Eff;

extern int func_021D4FEC();
extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021D4FF4(void *cell, int idx, Eff eff, int affine);

void func_021D19F4(void *cell, int y)
{
    Eff eff;
    int num;
    int x;
    int cy;
    int i;

    num = func_021D4FEC(cell);
    for (i = 0; i < num; i++) {
        func_021D5250(cell, i, &x, &cy);
        if (cy >= y && cy < 192)
            eff = EFF_NONE;
        else
            eff = EFF_HIDE;
        func_021D4FF4(cell, i, eff, 0);
    }
}
