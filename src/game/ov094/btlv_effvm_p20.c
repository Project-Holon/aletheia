/*
 * file:     btlv_effvm_p20.c
 * unit:     yes
 * function: func_021F86B4, func_021F86C4, func_021F86D4, func_021F86E0
 * address:  0x021F86B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   g_0220AF20  0x0220AF20  data
 */
#include "../../matched/include/G_0220AF20.h"

int func_021F86B4(void);
int func_021F86C4(void);
void *func_021F86D4(void);
int func_021F86E0(void);
extern char *d_0220AF20;
extern struct G_0220AF20 *g_0220AF20;


/*
 * Returns the word at 0x1a4 of the global work block.
 */
int func_021F86B4(void)
{
    return *(int *)(d_0220AF20 + 0x1a4);
}


/*
 * Returns the word at 0x188 of the global work block.
 */
int func_021F86C4(void)
{
    return *(int *)(d_0220AF20 + 0x188);
}


void *func_021F86D4(void)
{
    return *(void **)g_0220AF20;
}


/*
 * Returns the word at 0x18c of the global work block.
 */
int func_021F86E0(void)
{
    return *(int *)(d_0220AF20 + 0x18c);
}
