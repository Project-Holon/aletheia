/*
 * unit:     no
 * function: GFL_NET_COMMAND_Exit
 * address:  0x0203A53C
 * packet:   pkt_02039CD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _pCommandWork      0x021469D8  data
 *   MI_CpuFill8  0x02082BCC  arm
 */

#include "../include/G_Entry.h"

extern void MI_CpuFill8(int a, int b, int c);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern struct Entry *_pCommandWork;
void GFL_NET_COMMAND_Exit(void)
{
    if (((int *)_pCommandWork) == 0)
        return;
    MI_CpuFill8((int)((int *)_pCommandWork), 0, 0x22c);
    func_020307B0(((int *)_pCommandWork));
    _pCommandWork = 0;
}
