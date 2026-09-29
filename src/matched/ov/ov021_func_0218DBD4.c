/*
 * function: func_0218DBD4
 * address:  0x0218DBD4
 * packet:   pkt_ov021_0218DBD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_021697E0  0x021697E0  thumb ov010
 */

extern int func_021694FC(int o);
extern int func_021697E0(int o);

int func_0218DBD4(char *p, int i)
{
    if (*(int *)(p + 0x1c) == 0)
        return 0;
    if (func_021694FC(*(int *)(*(char **)(p + 0x24) + i * 0x28)) == 0)
        return 0;
    return func_021697E0(*(int *)(*(char **)(p + 0x24) + i * 0x28));
}
