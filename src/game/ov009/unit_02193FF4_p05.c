/*
 * file:     unit_02193FF4_p05.c
 * unit:     yes
 * function: func_02194890, func_021948F0, func_02194954, func_021949B4, func_02194A14, func_02194A78
 * address:  0x02194890
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021946F4  0x021946F4  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   func_02194754  0x02194754  arm  ov009
 *   d_021A590C     0x021A590C  data  a4
 *   OS_SPrintf   0x02084F40  arm
 *   func_021947C0 0x021947C0  arm
 *   g_021A590C   0x021A590C  data
 *   func_02194834  0x02194834  arm  ov009
 *   func_02194724  0x02194724  arm  ov009
 *   d_021A5914     0x021A5914  data  a4
 *   g_021A5914   0x021A5914  data
 */
extern int func_021946F4(int *game, int tnum);
extern void func_02084F40(char *buf, const char *fmt, int b, int n);
extern void func_02194754(int a, char *buf, int c, int d, int e);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern double func_021947C0(void *game, char *name, void *func, double value, int index);
extern void func_02194834(int a, char *buf, int c, int d, int e);
extern int func_02194724(int *game, int pnum);
void func_02194890(int a, int b, int c, int d, int e);
double func_021948F0(void *game, char *name, void *func, double value, int index);
void func_02194954(int a, int b, int c, int d, int e);
void func_021949B4(int a, int b, int c, int d, int e);
double func_02194A14(void *game, char *name, void *func, double value, int index);
void func_02194A78(int a, int b, int c, int d, int e);
extern char d_021A590C[];
extern char g_021A590C[];
extern char d_021A5914[];
extern char g_021A5914[];


/*
 * sdk:      TeamOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_02194890(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    func_02084F40(buf, d_021A590C, b, func_021946F4((int *)a, e));
    func_02194754(a, buf, c, d, e);
}


/*
 * sdk:      TeamOpFloat (gstats.o)
 */
double func_021948F0(void *game, char *name, void *func, double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, g_021A590C, name, func_021946F4(game, index));
    return func_021947C0(game, fullname, func, value, index);
}


/*
 * sdk:      TeamOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_02194954(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    func_02084F40(buf, d_021A590C, b, func_021946F4((int *)a, e));
    func_02194834(a, buf, c, d, e);
}


/*
 * sdk:      PlayerOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_021949B4(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    func_02084F40(buf, d_021A5914, b, func_02194724((int *)a, e));
    func_02194754(a, buf, c, d, e);
}


double func_02194A14(void *game, char *name, void *func, double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, g_021A5914, name, func_02194724(game, index));
    return func_021947C0(game, fullname, func, value, index);
}


/*
 * sdk:      PlayerOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_02194A78(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    func_02084F40(buf, d_021A5914, b, func_02194724((int *)a, e));
    func_02194834(a, buf, c, d, e);
}
