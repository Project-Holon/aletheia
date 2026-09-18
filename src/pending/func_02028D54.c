/*
 * function: func_02028D54
 * address:  0x02028D54
 * packet:   pkt_02028D54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02028E80; 02028EAC
 */

extern int *func_02028D7C(int v);
extern int func_02028FD0(int a, int b);
extern void func_02028EAC(int a, int b);
extern void func_02028E80(int v);
void func_02028D54(int a0)
{
    int *p = func_02028D7C(a0);
    if (func_02028FD0(a0, *p)) {
        func_02028EAC(a0, (int)p);
        func_02028E80(a0);
    }
}
