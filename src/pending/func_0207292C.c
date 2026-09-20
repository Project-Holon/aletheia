/*
 * function: func_0207292C
 * address:  0x0207292C
 * packet:   pkt_0207292C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020895D8  0x020895D8  arm
 *   g_0214DEC0     0x0214DEC0  data
 */

struct Global0214DEC0 {
    char pad[8];
    int flags8;
};

extern struct Global0214DEC0 g_0214DEC0;
extern void func_020895D8(int, int);

int func_0207292C(int mask)
{
    if (mask == 0) return 1;
    if ((mask & g_0214DEC0.flags8) != 0) return 0;
    func_020895D8(mask, 0);
    g_0214DEC0.flags8 |= mask;
    return 1;
}
