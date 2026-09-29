/*
 * function: func_021F2624
 * address:  0x021F2624
 * packet:   pkt_ov032_021F2624
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2624 0x021F2624 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028178 0x02028178 thumb
 *   func_02028230 0x02028230 thumb
 *   func_020282A4 0x020282A4 thumb
 */

extern void func_0202822C(int, int);
extern void func_02028178(int);
extern int func_02028230(int);
extern void func_020282A4(int);

int func_021F2624(int a0, int *st)
{
    int h = st[6];

    switch (st[0]) {
    case 0:
        func_0202822C(h, 1);
        st[0]++;
        break;
    case 1:
        func_02028178(h);
        if (func_02028230(h)) {
            func_020282A4(h);
            return 1;
        }
        break;
    }
    return 0;
}
