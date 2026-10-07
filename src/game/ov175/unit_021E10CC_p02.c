/*
 * file:     unit_021E10CC_p02.c
 * unit:     yes
 * function: func_021E1414, func_021E1434
 * address:  0x021E1414
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
 *   func_0217CE1C  0x0217CE1C  arm  ov009
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_021BF5B8  0x021BF5B8  arm  ov114
 *   g_021E5334  0x021E5334  data
 */
typedef unsigned long u32;

extern int  func_0217CE1C(void);
extern void func_0217CCCC(unsigned int theMS);
extern int func_021BF5B8(void);
extern int func_02059F38(void);
void func_021E1414(void);
int func_021E1434(void);
extern u32 g_021E5334[];


/*
 * Runs the ov009 status query 0x0217CE1C; unless it reports 2 it releases
 *  *  the ov009 object through 0x0217CCCC(0), then always finishes with the
 *  *  0x021BF5B8 (ov114) step.
 */
void func_021E1414(void)
{
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
    func_021BF5B8();
}


int func_021E1434(void)
{
    if (func_02059F38())
        return 4;
    return g_021E5334[2];
}
