/*
 * function: func_0203B2D0
 * address:  0x0203B2D0
 * packet:   pkt_0203B2FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203B258  0x0203B258  arm
 */

#include "../include/G_Sys.h"

typedef unsigned int u32;

struct Sys;

extern struct Sys *g_021469DC;
extern void func_0203B258(void);

typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);

void func_0203B2D0(u32 val)
{
    func_0203AD80((struct NetState *)((struct Sys *)g_021469DC), func_0203B258, 0, 0x222);
}
