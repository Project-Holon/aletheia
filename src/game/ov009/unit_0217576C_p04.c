/*
 * file:     unit_0217576C_p04.c
 * unit:     yes
 * function: func_02175EFC, func_02175F1C, func_02175F3C, func_02175F4C
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
 *   func_02176A8C  0x02176A8C  arm  ov009
 */
#include "../../matched/include/G_NNThinkGlobal.h"
#include "../../matched/include/G_NNThinkGlobal.h"

extern unsigned long long func_020870D0(int a);
extern void func_02176A8C(int a, int b);
int func_02175EFC(void);
/* * Stores the argument, calls the pair-returning helper and keeps both words. */ void func_02175F1C(int a);
/* * The word at +4 of the module state block. */ int func_02175F3C(void);
void func_02175F4C(int state);
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


/*
 * DWCi_SetMatchStatus: records the new match state, logging a change first.
 */
void func_02175F4C(int state)
{
    if (*(int *)(*(char **)(((char *)&g_021AAA20) + 4) + 0x61c) != state) {
        func_02176A8C(*(int *)(*(char **)(((char *)&g_021AAA20) + 4) + 0x61c), state);
    }
    *(int *)(*(char **)(((char *)&g_021AAA20) + 4) + 0x61c) = state;
}
