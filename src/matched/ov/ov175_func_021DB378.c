/*
 * function: func_021DB378
 * address:  0x021DB378
 * packet:   pkt_021DB378
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *
 * Same guard as func_021DB300 but it moves the word the third argument
 *     points at into the +0x150 slot of the fourth argument and sets +0x14c.
 */
#include "../include/Obj14340.h"

typedef unsigned long u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);

void func_021DB378(u32 a, u32 b, u32 *c, char *d, u32 e)
{
    u32 v = *c;

    if (e != (u32)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct Obj14340 *)d)->f150 = v;
    ((struct Obj14340 *)d)->f14C = 1;
}

