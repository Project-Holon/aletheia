/*
 * function: func_021F8324
 * address:  0x021F8324
 * packet:   pkt_ov094_021F8324
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_021F6A18  0x021F6A18  thumb  ov094
 *   func_021F6E1C  0x021F6E1C  thumb  ov094
 *   func_02021ED8  0x02021ED8  thumb
 */
typedef unsigned int u32;

extern char *d_0220AF20;
extern int func_021F6A18(u32 obj);
extern int func_021F6E1C(u32 obj);
extern int func_02021ED8(int);

int func_021F8324(u32 a)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (a == 0 || a == 2 || a == 4)
        x = func_021F6A18(*(u32 *)(d_0220AF20 + 0x194));
    if (a == 1 || a == 2 || a == 4)
        y = func_021F6E1C(*(u32 *)(d_0220AF20 + 0x198));
    if (a - 3 <= 1) {
        z = func_02021ED8(*(int *)(d_0220AF20 + 0x18C)) != 0;
    }
    if (x == 1 || y == 1 || z == 1)
        return 1;
    return 0;
}
