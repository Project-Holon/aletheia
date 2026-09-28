/*
 * function: func_02193D00
 * address:  0x02193D00
 * packet:   pkt_ov009_02193D00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CloseStatsConnection (gstats.o)
 *
 * symbols:
 *   func_0217EB9C 0x0217EB9C  arm
 *   func_0217EB2C 0x0217EB2C  arm
 *   func_02194614 0x02194614  arm
 *   func_0217EAE0 0x0217EAE0  arm
 *   g_021A57C8   0x021A57C8  data
 *   g_021ADFE0   0x021ADFE0  data
 */

extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern void func_02194614(void);
extern void func_0217EAE0(void *ptr);
extern int g_021A57C8[];
extern int g_021ADFE0[];

void func_02193D00(void)
{
    if (g_021A57C8[1] != -1) {
        func_0217EB9C(g_021A57C8[1], 2);
        func_0217EB2C(g_021A57C8[1]);
    }
    g_021A57C8[1] = -1;
    func_02194614();
    if (g_021ADFE0[10] != 0) {
        func_0217EAE0((void *)g_021ADFE0[10]);
        g_021ADFE0[10] = 0;
        g_021ADFE0[6] = 0;
        g_021ADFE0[2] = 0;
    }
}
