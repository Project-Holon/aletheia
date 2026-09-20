/*
 * function: func_02010DCC
 * address:  0x02010DCC
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146954  0x02146954  data
 *
 * function: func_02010DF4
 * address:  0x02010DF4
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010F50  0x02010F50  thumb
 */

extern int g_02146954[];
extern void func_02010F50(int);

void func_02010DCC(void)
{
    int i;
    for (i = 0; i < 13; i++) {
        if (g_02146954[i] > 1) {
            g_02146954[i]--;
        }
    }
}

void func_02010DF4(void)
{
    int i;
    for (i = 0; i < 13; i++) {
        func_02010F50(i);
    }
}
