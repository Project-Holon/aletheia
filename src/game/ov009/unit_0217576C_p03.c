/*
 * file:     unit_0217576C_p03.c
 * unit:     yes
 * function: func_02175EFC, func_02175F1C, func_02175F3C
 * address:  0x02175EFC
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
 *   g_021AAA20  0x021AAA20  data
 */
#include "../../matched/include/G_NNThinkGlobal.h"

extern unsigned long long func_020870D0(int a);
int func_02175EFC(void);
void func_02175F1C(int a);
int func_02175F3C(void);
extern struct NNThinkGlobal g_021AAA20;


int func_02175EFC(void)
{
    unsigned int v = *(unsigned int *)(func_02175F3C() + 0x61c) - 9;

    return v <= 2;
}


/*
 * Stores the argument, calls the pair-returning helper and keeps both words.
 */
void func_02175F1C(int a)
{
    unsigned long long v;

    *(int *)(((char *)&g_021AAA20) + 4) = a;
    v = func_020870D0(a);
    *(int *)(((char *)&g_021AAA20) + 0x18) = (int)v;
    *(int *)(((char *)&g_021AAA20) + 0x1c) = (int)(v >> 32);
}


/*
 * The word at +4 of the module state block.
 */
int func_02175F3C(void)
{
    return *(int *)(((char *)&g_021AAA20) + 4);
}
