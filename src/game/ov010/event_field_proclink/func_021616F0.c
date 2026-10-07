/*
 * function: func_021616F0
 * address:  0x021616F0
 * packet:   pkt_021616F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02169AB8  0x02169AB8  thumb  ov010
 */
#include "../../../matched/include/Obj00029.h"
#include "../../../matched/include/Obj00654.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Work;
extern int func_02169AB8(struct Work *w, u32 *state);

int func_021616F0(int a0, int a1, int a2)
{
    int t4;

t4 = a2 + 0;
a0 = t4 + 0;
    a0 = func_02169AB8((struct Work *)a0, (u32 *)a1);
loc_021616FA:
    if (a0 == 0) goto loc_02161704;
loc_021616FE:
    if (a0 == 1) goto loc_0216170C;
loc_02161702:
    goto loc_02161716;
loc_02161704:
a1 = ((struct Obj00029 *)t4)->f14;
a0 = 1;
*(int *)&((struct Obj00654 *)((char *)a1))->f0 = a0;
    return a0;
loc_0216170C:
a0 = ((struct Obj00029 *)t4)->f14;
a1 = 0;
*(int *)&((struct Obj00029 *)((char *)a0))->f0 = a1;
a0 = 1;
    return a0;
loc_02161716:
a0 = 0;
    return a0;}
