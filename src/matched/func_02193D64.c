/*
 * function: func_02193D64
 * address:  0x02193D64
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set while the word at +4 of the state object is not -1.
 *
 * symbols:
 *   g_021A57C8  0x021A57C8  data
 */

extern char g_021A57C8[];

int func_02193D64(void)
{
    return *(int *)(g_021A57C8 + 4) != -1;
}

