/*
 * function: func_021657C8
 * address:  0x021657C8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word at +4 of the module state block.
 *
 * symbols:
 *   g_021AA7D4  0x021AA7D4  data
 */

extern char g_021AA7D4[];

int func_021657C8(void)
{
    return *(int *)(g_021AA7D4 + 4);
}

