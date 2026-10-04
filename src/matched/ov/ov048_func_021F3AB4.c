/*
 * function: func_021F3AB4
 * address:  0x021F3AB4
 * packet:   pkt_021F3AB4
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 */
#include "../include/Obj20532.h"

typedef unsigned int u32;

typedef signed int     s32;
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);

int func_021F3AB4(void *p)
{
    return func_020142E8((void *)func_0201296C((const struct BigObj *)(((struct Obj20532 *)p)->f8)), 0x97b) == 1;
}
