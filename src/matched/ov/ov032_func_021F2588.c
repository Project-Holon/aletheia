/*
 * function: func_021F2588
 * address:  0x021F2588
 * packet:   pkt_ov032_021F2588
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2588 0x021F2588 thumb
 *   func_021F25D4 0x021F25D4 thumb ov032
 *   func_021F2608 0x021F2608 thumb ov032
 *   func_021F2624 0x021F2624 thumb ov032
 *   func_0201235C 0x0201235C thumb
 */

extern int func_021F25D4(char *, int *);
extern int func_021F2608(char *, int *);
extern int func_021F2624(int, int *);
extern void func_0201235C(int, int);

int func_021F2588(int a0, int a1, int *st)
{
    int r;
    char *o;

    r = 0;
    o = (char *)st[3];
    switch (st[5]) {
    case 0:
        r = func_021F25D4(o, st);
        break;
    case 1:
        r = func_021F2608(o, st);
        break;
    case 2:
        r = func_021F2624((int)o, st);
        break;
    }
    if (r) {
        *(unsigned short *)(o + 0x72) = 0;
        func_0201235C(a0, st[4]);
    }
    return 0;
}
