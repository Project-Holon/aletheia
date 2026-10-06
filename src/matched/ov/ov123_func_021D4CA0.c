/*
 * function: func_021D4CA0
 * address:  0x021D4CA0
 * packet:   pkt_021D4CA0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_02051C88  0x02051C88  arm
 *   func_021D4C4C  0x021D4C4C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05360.h"

typedef unsigned int u32;

extern u32 func_020221A4(void);
typedef signed int     s32;
struct Ctx;
extern s32 func_02051C88(struct Ctx *c);
extern void func_021D4C4C(char *);

void func_021D4CA0(char *p)
{
    if (func_020221A4() != 0)
        func_02051C88(((struct Obj05360 *)p)->f20);
    func_021D4C4C(p);
}
