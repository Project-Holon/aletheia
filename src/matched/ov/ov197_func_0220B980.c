/*
 * function: func_0220B980
 * address:  0x0220B980
 * packet:   pkt_0220B980
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_APP_TOOL_Update 0x0220B0B0 thumb
 */
#include "../include/Obj25009.h"

extern int B_APP_TOOL_Update(void *, int, int);

int func_0220B980(char *a)
{
    return B_APP_TOOL_Update(a + 0x28, ((struct Obj25009 *)a)->f18, 0x23);
}
