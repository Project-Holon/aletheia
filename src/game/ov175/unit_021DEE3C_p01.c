/*
 * file:     unit_021DEE3C_p01.c
 * unit:     yes
 * function: func_021DEF58, func_021DEFC4
 * address:  0x021DEF58
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
 *   g_021E4D08     0x021E4D08  data
 *   func_021DF5E4  0x021DF5E4  arm  ov175
 *   func_021E22E4  0x021E22E4  arm  ov175
 *   func_021DFE20  0x021DFE20  arm  ov175
 *   func_021BF540  0x021BF540  arm  ov114
 */
typedef unsigned int u32;

typedef signed int     s32;

extern int func_021DFA3C(void *);
extern int func_021DF5E4(void);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);
extern void func_0217CD94(void);
extern void func_0217CCCC(int);
extern int func_0217CE1C(void);
extern s32 func_021E22E4(void);
extern int func_021BF540(void);
extern void func_021DFE20(void);
int func_021DEF58(void);
void func_021DEFC4(void);
extern u32 g_021E4D08[];


int func_021DEF58(void)
{
    int r;

    r = func_021DFA3C((void *)g_021E4D08[1]);
    if (r != 0)
        func_02059F54(func_021DF5E4(), func_021DF644(3, r));
    func_021DEFC4();
    func_0217CD94();
    func_0217CCCC(0);
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
    return r;
}


void func_021DEFC4(void)
{
    func_021E22E4();
    func_021BF540();
    func_021DFE20();
    func_021BF540();
}
