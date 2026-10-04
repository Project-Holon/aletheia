/*
 * function: func_021DD2F4
 * address: 0x021DD2F4
 * packet: pkt_ov119_021DD2F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 */
#include "../include/Obj00001.h"
extern int func_021D8AA8(void *);
int func_021DD2F4(char *p)
{
    int i;
    if (func_021D8AA8(p)) {
        for (i = 0; i < 3; i++) {
            if (*(int *)(p + i * 4 + 0xfa4) != -1 && *(int *)(p + i * 4 + 0xfbc) != -1) return 1;
        }
    } else {
        if (((struct Obj00001 *)p)->fF84 != -1 && ((struct Obj00001 *)p)->fF88 != -1) return 1;
    }
    return 0;
}
