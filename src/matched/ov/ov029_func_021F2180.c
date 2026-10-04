/*
 * function: func_021F2180
 * address: 0x021F2180
 * packet: pkt_ov029_021F2180
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F0D48 0x021F0D48 thumb ov029
 *   func_021F2130 0x021F2130 thumb ov029
 */
#include "../include/Obj00042.h"
extern int func_021F0D48(char *p);
extern void func_021F2130(char *p);
void func_021F2180(char *p)
{
    if (*(void (**)(void *))(p + 0x1fc) != 0)
        (*(void (**)(void *))(p + 0x1fc))(((struct Obj00042 *)p)->f200);
    *(void (**)(void *))(p + 0x1fc) = 0;
    ((struct Obj00042 *)p)->f200 = 0;
    if (func_021F0D48(p))
        func_021F2130(p);
}
