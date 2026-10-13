/*
 * function: func_02025FC8
 * address:  0x02025FC8
 * packet:   pkt_02025FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg   0x020362DC  arm
 *   func_02025FA4   0x02025FA4  thumb
 *
 * Poll the pending-interrupt word and answer with the slot a matching mask
 * selects: mode 1 (a0[8] == 1) tests 0xf3, the other path tests 0xf1 and
 * then bit 1; a hit runs func_02025FA4 and returns its value, a miss in the
 * bit-1 case answers -2 and a miss anywhere else answers -1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025FC8.c \
 *       --func func_02025FC8 --addr 0x02025FC8 --cc 1.1p1 --thumb
 */
#include "../include/Obj04105.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 KEY_GetTrg(void);
struct Struct_02025CD0;
extern int func_02025FA4(struct Struct_02025CD0 *obj);

int func_02025FC8(u8 *a0)
{
    if (((struct Obj04105 *)a0)->f8 == 1) {
        if (KEY_GetTrg() & 0xf3) {
            return func_02025FA4((struct Struct_02025CD0 *)a0);
        }
    } else if (KEY_GetTrg() & 0xf1) {
        return func_02025FA4((struct Struct_02025CD0 *)a0);
    } else if (KEY_GetTrg() & 2) {
        func_02025FA4((struct Struct_02025CD0 *)a0);
        return -2;
    }
    return -1;
}
