/*
 * function: func_021F6AA4
 * address:  0x021F6AA4
 * packet:   pkt_021F6AA4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   D_021F7008  0x021F7008  data
 */

extern unsigned char D_021F7008[];

int func_021F6AA4(int a)
{
    unsigned short i = 0;
    unsigned int v;
    int n = *(int *)(D_021F7008 + 0xc);

    if (n > 0) {
        v = *(unsigned int *)(*(unsigned char **)(D_021F7008 + 4) + (a - 1) * 4 + 0x1e0);
        do {
            if (!(v & (1u << i)))
                return 0;
        } while (++i < n);
    }
    return 1;
}
