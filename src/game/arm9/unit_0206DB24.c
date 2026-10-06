/*
 * file:     unit_0206DB24.c
 * unit:     yes
 * function: func_0206DB24, func_0206DB40, func_0206DB60
 * address:  0x0206DB24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0214BAB4      0x0214BAB4  data  a4
 *   g_0214BAB4       0x0214BAB4  data
 */
typedef unsigned int u32;

extern void   func_0206DB80(void);
int CTRDGi_IsTaskAvailable(void);
void func_0206DB40(u32 *p);
void *func_0206DB60(void);
extern char d_0214BAB4;
extern char *g_0214BAB4;


int CTRDGi_IsTaskAvailable(void)
{
    return *(void **)&d_0214BAB4 != 0;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DB40.c \
 *       --func func_0206DB40 --addr 0x0206DB40 --cc 1.1p1 --arm
 */
void func_0206DB40(u32 *p)
{
    if (g_0214BAB4 == 0) {
        *p = 0;
        g_0214BAB4 = (char *)p;
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DB60.c \
 *       --func func_0206DB60 --addr 0x0206DB60 --cc 1.1p1 --arm
 */
void *func_0206DB60(void)
{
    void *r;

    func_0206DB80();
    r = g_0214BAB4;
    g_0214BAB4 = 0;
    return r;
}
