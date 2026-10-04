/*
 * function: func_021BA218
 * address:  0x021BA218
 * packet:   pkt_ov088_021BA218
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 */
#include "../include/Obj20813.h"

typedef unsigned int   u32;
extern u32 func_020221A4(void);

int func_021BA218(char *p)
{
    if (func_020221A4() == 1) {
        return ((struct Obj20813 *)p)->f144;
    }
    return 2;
}
