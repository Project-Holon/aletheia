/*
 * unit:     no
 * function: func_02028CB0
 * address:  0x02028CB0
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02028C30, 02028C50 has no witness outside this range
 */

extern int func_02028C30(void *p);
extern int func_02028C50(void *p);
int func_02028CB0(void *p)
{
    if (func_02028C30(p) == 0)
        return 0;
    return func_02028C50(p) != 0;
}
