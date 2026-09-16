/*
 * function: func_02028CB0
 * address:  0x02028CB0
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  label, func_02028C30 and func_02028C50 have no branch
 *           reference outside this range (only caller is this function)
 * symbols:
 *   func_02028C30  0x02028C30  thumb
 *   func_02028C50  0x02028C50  thumb
 */

extern int func_02028C30(void *arg);
extern int func_02028C50(void *arg);

int func_02028CB0(void *arg)
{
    if (func_02028C30(arg) == 0) {
        return 0;
    }
    if (func_02028C50(arg) != 0) {
        return 1;
    }
    return 0;
}
