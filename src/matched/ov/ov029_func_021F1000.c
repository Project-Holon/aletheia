/*
 * function: func_021F1000
 * address:  0x021F1000
 * packet:   pkt_ov029_021F1000
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021ED8  0x02021ED8  thumb
 */
#include "../include/Obj20391.h"

typedef unsigned int   u32;
extern u32 func_02021ED8(const char *ptr);

int func_021F1000(char *p)
{
    return func_02021ED8((const char *)(((struct Obj20391 *)p)->f210));
}
