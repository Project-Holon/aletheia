/*
 * function: func_0220C6C0
 * address:  0x0220C6C0
 * packet:   pkt_0220C6C0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_APP_TOOL_DeleteActors 0x0220AFC4 thumb ov196
 */
#include "../include/Obj25044.h"

typedef unsigned char  u8;
extern void B_APP_TOOL_DeleteActors(u8 *p);

void func_0220C6C0(char *a)
{
    B_APP_TOOL_DeleteActors((u8 *)(((struct Obj25044 *)a)->f148));
}
