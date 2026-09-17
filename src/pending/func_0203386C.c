/*
 * unit:     no
 * function: func_0203386C
 * address:  0x0203386C
 * packet:   pkt_0203331C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  02076B98 has no witness outside this range
 */

extern int func_02076B8C(void);
extern void func_02076B98(void);
extern void func_02076B80(void);
extern void func_02075EAC(int a);
extern void func_02084F10(int a);
extern int g_02146998;
void func_0203386C(int a)
{
    if (func_02076B8C() == 0) {
        func_02076B98();
        func_02076B80();
    }
    if (g_02146998 != 1)
        return;
    func_02075EAC(a);
    func_02084F10(a);
    g_02146998 = 0;
}
