/*
 * file:     unit_021DF7FC.c
 * unit:     yes
 * function: func_021DF7FC, func_021DF884, func_021DF8D4, func_021DF928, func_021DF948, func_021DF968
 * address:  0x021DF7FC
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
 *   d_021ACEF8     0x021ACEF8  data  a4
 *   d_021ACEFC     0x021ACEFC  data  a4
 *   d_021E52B4     0x021E52B4  data  a1
 *   d_021E412C     0x021E412C  data  a4
 *   func_02084F80  0x02084F80  arm
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_021E06DC  0x021E06DC  arm
 *   func_021E0730  0x021E0730  arm
 *   func_02094798  0x02094798  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   g_021E52B4  0x021E52B4  data
 *   g_021E412C  0x021E412C  data
 *   g_021E4184  0x021E4184  data
 */
typedef unsigned int u32;

typedef int s32;

typedef unsigned char u8;

void func_02084F80(void *p, int a, void *b, void *c);
void *func_0217EAB0(int size);
void func_020923B0(void *dst, int c, int n);
extern s32 func_021E06DC(char *p, u32 v);
extern void func_021E0730(char *p);
extern char *func_02094798(char *dst, const char *src);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
int func_021DF7FC(void **out);
s32 func_021DF884(char *p);
void func_021DF8D4(char *p);
void func_021DF928(char *obj, int v);
void func_021DF948(char *obj, int v);
char *func_021DF968(void);
extern int d_021ACEF8;
extern int d_021ACEFC;
extern signed char d_021E52B4;
extern int d_021E412C;
extern int g_021ACEF8;
extern char g_021ACEFC[];
extern char g_021E52B4[128];
extern char g_021E412C[];
extern char g_021E4184[];


int func_021DF7FC(void **out)
{
    void *p;

    if (d_021ACEF8 == 1) {
        if (d_021E52B4 == 0)
            func_02084F80(&d_021E52B4, 0x80, &d_021E412C, &d_021ACEFC);
    } else {
        return 1;
    }
    p = func_0217EAB0(0xac);
    *out = p;
    if (p == 0)
        return 5;
    func_020923B0(p, 0, 0xac);
    return 0;
}




/*
 * Activation probe: func_021E06DC reports on the owner, and a report is
 * returned as-is.  Otherwise clear the two 0x28-byte parameter blocks and
 * mark the owner live at +0x50.
 */
s32 func_021DF884(char *p)
{
    s32 e = func_021E06DC(p, (u32)p);

    if (e != 0)
        return e;
    func_020923B0(p + 0x5c, 0, 0x28);
    func_020923B0(p + 0x84, 0, 0x28);
    *(u32 *)(p + 0x50) = 1;
    return 0;
}




/*
 * Reset the owner: release it, blank the two 0x28-byte parameter blocks, put
 * the 0xadde signature on the front of each and clear the live flag.
 */
void func_021DF8D4(char *p)
{
    u32 z = 0;
    u32 n = 0x28;

    func_021E0730(p);
    func_020923B0(p + 0x5c, z, n);
    func_020923B0(p + 0x84, z, n);
    *(u8 *)(p + 0x5c) = 0xde;
    *(u8 *)(p + 0x5d) = 0xad;
    *(u8 *)(p + 0x84) = 0xde;
    *(u8 *)(p + 0x85) = 0xad;
    *(u32 *)(p + 0x50) = z;
}




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
