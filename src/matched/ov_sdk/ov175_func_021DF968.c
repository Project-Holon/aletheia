/*
 * function: func_021DF968
 * address:  0x021DF968
 * packet:   pkt_ov175_021DF968
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciGetServiceUrl (libdwcgssc.TWL.HYB.a(sciinterface.o))
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   g_021E52B4  0x021E52B4  data
 *   g_021E412C  0x021E412C  data
 *   g_021E4184  0x021E4184  data
 */

extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int g_021ACEF8;
extern char g_021ACEFC[];
extern char g_021E52B4[128];
extern char g_021E412C[];
extern char g_021E4184[];

char *func_021DF968(void)
{
    if (g_021ACEF8 == 1) {
        if (g_021E52B4[0] == 0)
            func_02084F80(g_021E52B4, 128, g_021E412C, g_021ACEFC);
        return g_021E52B4;
    }
    func_0217D254(0, (char *)3, 1, g_021E4184);
    return 0;
}
