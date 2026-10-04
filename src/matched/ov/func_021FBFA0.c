/*
 * function: func_021FBFA0
 * address:  0x021FBFA0
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FBFA0   0x021FBFA0  thumb
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_02200140 0x02200140 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj09236.h"

extern int  func_021F8694(void);
extern void func_02200140(int a, int b, int c);

int func_021FBFA0(int a, char *b)
{
    func_02200140(func_021F8694(), ((struct Obj09236 *)b)->fE0, ((struct Obj09236 *)b)->fDC);
    return ((struct Obj09236 *)b)->f23C;
}

