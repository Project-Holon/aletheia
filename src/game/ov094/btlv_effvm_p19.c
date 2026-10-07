/*
 * file:     btlv_effvm_p19.c
 * unit:     yes
 * function: func_021F8678, func_021F8684
 * address:  0x021F8678
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
 *   g_0220AF20  0x0220AF20  data
 *   d_0220AF20  0x0220AF20  data  ov094
 */
#include "../../matched/include/G_0220AF20.h"

void *func_021F8678(void);
int func_021F8684(void);
extern struct G_0220AF20 *g_0220AF20;
extern char *d_0220AF20;


void *func_021F8678(void)
{
    return g_0220AF20;
}


int func_021F8684(void)
{
    return *(int *)(d_0220AF20 + 0x19c);
}
