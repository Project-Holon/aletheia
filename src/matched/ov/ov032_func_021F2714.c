/*
 * function: func_021F2714
 * address:  0x021F2714
 * packet:   pkt_ov032_021F2714
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     func_021F05E8 takes three arguments (its own matched file); the
 *           cleared zero is shared with its third argument, which is what
 *           puts the zero in r2 for the three stores.
 *
 * symbols:
 *   func_021F2714 0x021F2714 thumb
 *   func_021F0050 0x021F0050 thumb ov032
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_021F067C 0x021F067C thumb ov032
 *   func_021F029C 0x021F029C thumb ov032
 *   func_021F028C 0x021F028C thumb ov032
 */

extern int func_021F0050(char *);
extern void func_021F05E8(char *, int, unsigned);
extern void func_021F067C(char *);
extern void func_021F029C(char *, int);
extern void func_021F028C(char *);

int func_021F2714(char *p)
{
    int r;

    if (*(unsigned char *)(p + 0x82) == 0) {
        r = func_021F0050(p);
        if (r != *(int *)(p + 0x84) || r == -1) {
            *(unsigned char *)(p + 0x82) = 1;
        }
        *(int *)(p + 0x88) = *(int *)(p + 0x88) + 1;
    }
    if (*(unsigned char *)(p + 0x82) != 0) {
        if (*(int *)(p + 0xa8) > 0) {
            return 3;
        }
        *(unsigned char *)(p + 0x82) = 0;
        *(int *)(p + 0x88) = 0;
        *(unsigned char *)(p + 0x81) = 0;
        if (*(unsigned char *)(p + 0x83) == 0) {
            func_021F05E8(p, 4, 0);
        }
        func_021F067C(p);
        func_021F029C(p, 0);
        return *(unsigned char *)(p + 0x83);
    }
    if (*(int *)(p + 0xa8) == 0) {
        func_021F028C(p);
    }
    return 3;
}
