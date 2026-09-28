/*
 * unit:     no
 * function: func_0204BD3C
 * address:  0x0204BD3C
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  02063138 has no witness outside this range
 */

extern void func_02063138(void *p, int a, int b);
void func_0204BD3C(char *p, int a, int b)
{
    if (b == 0) {
        *(int *)(p + 0x1c) = 0;
        return;
    }
    func_02063138(p, a, b);
    *(int *)(p + 0x1c) = 1;
}
