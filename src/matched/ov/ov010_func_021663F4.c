/*
 * function: func_021663F4
 * address:  0x021663F4
 * packet:   pkt_ov010_021663F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finds the position of a value in a byte list (func_0216630C) and returns
 * the entry a step away from it: 0 = three back, 1 = three on, 2 = one
 * back, 3 = one on; any other direction returns the default.
 *
 * symbols:
 *   func_0216630C  0x0216630C  thumb  ov010
 */

typedef unsigned char u8;

extern int func_0216630C(u8 *list, int v);

int func_021663F4(u8 *list, int def, unsigned dir)
{
    int i = func_0216630C(list, def);

    switch (dir) {
    case 0:
        return list[i - 3];
    case 1:
        return list[i + 3];
    case 2:
        return list[i - 1];
    case 3:
        return list[i + 1];
    }
    return def;
}
