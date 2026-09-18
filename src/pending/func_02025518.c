/*
 * function: func_02025518
 * address:  0x02025518
 * packet:   pkt_02025518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  020253D4
 */

extern int func_02025508(int a, int b, int c);
extern void func_020253D4(int a0, int a1, int a2);
extern void func_0204ADA4(int a1);
void func_02025518(int a0, int a1, int a2)
{
    int v = func_02025508(a0, a1, a2);
    func_020253D4(a0, v, a2);
    func_0204ADA4(a1);
}
