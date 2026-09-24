/*
 * function: func_021772B8
 * address:  0x021772B8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the word at +0x724 of the state block when both are present.
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 */

extern char g_021AB180[];

int func_021772B8(int v)
{
    char *p = *(char **)g_021AB180;

    if (p == 0 || v == 0) {
        return 0;
    }

    *(int *)(p + 0x724) = v;

    return 1;
}

