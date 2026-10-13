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
 *   DWCi_CELLlGetState  0x021D4FEC  arm  ov016
 *   DWCi_CELLlGetPosition  0x021D5250  arm  ov016
 *   DWCi_CELLlSetEffect  0x021D4FF4  arm  ov016
 */

typedef enum {
    EFF_NONE = 0,
    EFF_HIDE = 0x200
} Eff;

extern unsigned char DWCi_CELLlGetState(char *p);
extern void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
extern void DWCi_CELLlSetEffect(void *cell, int idx, Eff eff, int affine);

void func_021D19F4(void *cell, int y)
{
    Eff eff;
    int num;
    int x;
    int cy;
    int i;

    num = DWCi_CELLlGetState(cell);
    for (i = 0; i < num; i++) {
        DWCi_CELLlGetPosition(cell, i, &x, &cy);
        if (cy >= y && cy < 192)
            eff = EFF_NONE;
        else
            eff = EFF_HIDE;
        DWCi_CELLlSetEffect(cell, i, eff, 0);
    }
}
