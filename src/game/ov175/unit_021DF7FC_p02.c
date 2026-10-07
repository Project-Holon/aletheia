/*
 * file:     unit_021DF7FC_p02.c
 * unit:     yes
 * function: func_021DF928, func_021DF948, func_021DF968
 * address:  0x021DF928
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02094798  0x02094798  arm
 *   func_02084F80  0x02084F80  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   g_021E52B4  0x021E52B4  data
 *   g_021E412C  0x021E412C  data
 *   g_021E4184  0x021E4184  data
 */
extern char *func_02094798(char *dst, const char *src);
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
void func_021DF928(char *obj, int v);
void func_021DF948(char *obj, int v);
char *func_021DF968(void);
extern int g_021ACEF8;
extern char g_021ACEFC[];
extern char g_021E52B4[128];
extern char g_021E412C[];
extern char g_021E4184[];


/*
 * Clears the byte at +0x5c when the second argument is zero and returns
 *  *  right away; otherwise forwards the address of that same byte to 0x02094798
 *  *  (arm9).  Written as an early-return `if` so MWCC predicates the store, the
 *  *  register clear and the epilogue with moveq/strbeq/popeq.
 */
void func_021DF928(char *obj, int v)
{
    if (v == 0) {
        obj[0x5c] = 0;
        return;
    }
    func_02094798(obj + 0x5c, (const char *)v);
}


/*
 * Clears the byte at +0x84 when the second argument is zero and returns
 *  *  right away; otherwise forwards the address of that same byte to 0x02094798
 *  *  (arm9).  Written as an early-return `if` so MWCC predicates the store, the
 *  *  register clear and the epilogue with moveq/strbeq/popeq.
 */
void func_021DF948(char *obj, int v)
{
    if (v == 0) {
        obj[0x84] = 0;
        return;
    }
    func_02094798(obj + 0x84, (const char *)v);
}


/*
 * sdk:      sciGetServiceUrl (libdwcgssc.TWL.HYB.a(sciinterface.o))
 */
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
