/*
 * function: WcmInitOption
 * address:  0x021658F8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the constant 0xaaa082 at +0x12d4 of the block the state object holds.
 *
 * symbols:
 *   g_021AA7D4  0x021AA7D4  data
 */

extern char g_021AA7D4[];

void WcmInitOption(void)
{
    char *p = *(char **)(g_021AA7D4 + 4);

    *(int *)(p + 0x1000 + 0x2d4) = 0xaaa082;
}

