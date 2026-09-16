/*
 * function: func_02028C30
 * address:  0x02028C30
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  literal, g_idTable_0209FDD0 has no reference outside this
 *           function's own literal pool
 * symbols:
 *   g_idTable_0209FDD0  0x0209FDD0  data
 */

typedef unsigned short u16;

extern const u16 g_idTable_0209FDD0[0x26];

int func_02028C30(u16 val)
{
    unsigned int i;

    for (i = 0; i < 0x26; i++) {
        if (val == g_idTable_0209FDD0[i]) {
            return 1;
        }
    }
    return 0;
}
