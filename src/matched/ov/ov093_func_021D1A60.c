/*
 * function: BTL_CLIENT_StepRunServerCommandsIfView
 * address: 0x021D1A60
 * packet: pkt_ov093_021D1A60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 * symbols:
 *   BTL_CLIENT_StepRunServerCommands 0x021D1A74 thumb ov093
 */
#include "../include/Obj01237.h"
typedef unsigned char u8;
extern int BTL_CLIENT_StepRunServerCommands(u8 *, int *, void *);
int BTL_CLIENT_StepRunServerCommandsIfView(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj01237 *)p)->f54;
    if (q != 0) return BTL_CLIENT_StepRunServerCommands(p, state, q);
    return 1;
}
