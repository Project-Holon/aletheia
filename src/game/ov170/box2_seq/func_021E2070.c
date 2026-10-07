/*
 * function: func_021E2070
 * address:  0x021E2070
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Run the p+0x2c+0x58 callback; when it returns 0 clear it and
 *   hand back the 0x68 word, else 5.
 */
#include "../../../matched/include/Obj09224.h"


int func_021E2070(char *p)
{
    int (*f)(char *) = *(int (**)(char *))(((struct Obj09224 *)p)->f2C + 0x58);
    if (f != 0 && f(p) == 0) {
        *(int *)(((struct Obj09224 *)p)->f2C + 0x58) = 0;
        return *(int *)(((struct Obj09224 *)p)->f2C + 0x68);
    }
    return 5;
}
