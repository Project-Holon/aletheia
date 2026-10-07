/*
 * file:     unit_021BA7DC.c
 * unit:     yes
 * function: func_021BA7DC, func_021BA820, func_021BA850
 * address:  0x021BA7DC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA874 0x021BA874 arm ov114
 *   func_021BA87C 0x021BA87C arm ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 */
typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
} BgnEnd;

typedef unsigned char  u8;

typedef unsigned int u32;

extern void func_021BA87C(u8 *p, int v);
extern void func_021BA874(u8 *p, int v);
extern u8 *func_021BEF08(void);
void func_021BA7DC(BgnEnd *info_p);
int func_021BA820(int a, int b);
void func_021BA850(int a);


/*
 * sdk:      NHTTPi_InitBgnEndInfo (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 */
void func_021BA7DC(BgnEnd *info_p)
{
    info_p->f0 = 0;
    info_p->f4 = 0;
    info_p->f8 = 0;
    info_p->fc = -1;
    func_021BA87C((u8 *)info_p, 0);
    func_021BA874((u8 *)info_p, 0);
    info_p->f18 = 0;
    info_p->f1c = 0;
    info_p->f20 = 0;
}


int func_021BA820(int a, int b)
{
    int (*g)(int, int) = *(int (**)(int, int))func_021BEF08();
    if (g == 0)
        return 0;
    return g(a, b);
}


/*
 * Calls the +0x04 hook of the module object with one argument.
 */
void func_021BA850(int a)
{
    void (*g)(int) = *(void (**)(int))(func_021BEF08() + 4);
    if (g != 0)
        g(a);
}
