/*
 * function: LIVEBATTLEMATCH_IRC_RecvHandler0
 * address: 0x0217E45C
 * packet: pkt_ov176_0217E45C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm  arm9
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm  arm9
 */
#include "../include/Obj24438.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
void LIVEBATTLEMATCH_IRC_RecvHandler0(u32 a, void *b, void *c, u8 *p, struct Entry *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((struct Obj24438 *)p)->f1008 = 1;
    }
}
