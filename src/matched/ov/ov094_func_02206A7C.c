/*
 * function: func_02206A7C
 * address:  0x02206A7C
 * packet:   pkt_ov094_02206A7C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F88A8  0x021F88A8  thumb  ov094
 */
#include "../include/Obj06328.h"
typedef struct {
    unsigned int lo : 4;
    unsigned int b4 : 1;
} Bf;

extern int func_021F88A8(void);

int func_02206A7C(char *p)
{
    if (!((Bf *)(p + 0x68))->b4) {
        if (((struct Obj06328 *)p)->f50 == 2) {
            if (func_021F88A8() == 1) {
                if (((struct Obj06328 *)p)->f278 == 4)
                    return 0x65;
                return 0x5f;
            }
            if (((struct Obj06328 *)p)->f278 == 4)
                return 0x5d;
            return 0x5e;
        }
        if (func_021F88A8() == 1)
            return 0x65;
        return 0x5d;
    }
    if (((struct Obj06328 *)p)->f50 == 2 && ((struct Obj06328 *)p)->f278 != 4) {
        if (func_021F88A8() == 1)
            return 0x67;
        return 0x61;
    }
    if (func_021F88A8() == 1)
        return 0x66;
    return 0x60;
}
