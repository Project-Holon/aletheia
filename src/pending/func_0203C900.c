/*
 * unit:     no
 * function: func_0203C900
 * address:  0x0203C900
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  021469C0 has no witness outside this range
 */

extern int *func_0203D788(void);
extern unsigned char *g_021469C0;
void func_0203C900(int a)
{
    int *r = func_0203D788();
    void (*fn)(int);
    if (g_021469C0 != 0)
        g_021469C0[0x50] = (unsigned char)a;
    fn = *(void (**)(int))(*(int *)((char *)r + 0x340) + 0x8c);
    fn(a);
}
