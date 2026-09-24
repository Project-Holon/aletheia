/*
 * function: func_0216BB6C
 * address:  0x0216BB6C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the index of the first null word in the 0x20-entry word table, or
 * -1 when the whole table is occupied.
 *
 * symbols:
 *   g_021AA8A0  0x021AA8A0  data

 */

extern char g_021AA8A0[];

int func_0216BB6C(void)
{
    int i;

    for (i = 0; i < 0x20; i++)
        if (*(int *)(g_021AA8A0 + i * 4) == 0) return i;
    return -1;
}


