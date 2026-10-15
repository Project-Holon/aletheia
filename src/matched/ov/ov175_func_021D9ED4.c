/*
 * function: WIFIBATTLEMATCH_NET_SetTimingSyncRange
 * address:  0x021D9ED4
 * packet:   pkt_021D9ED4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *
 * Stores the caller's word at +0x14 and forwards its low byte to
 *     0x02039C68 with the tick/state from 0x020399A8 and line 0x24.  The byte
 *     is re-read from the field after the first call, which is why the listing
 *     reloads +0x14.  WIFIBATTLEMATCH_NET_IsTimingSyncRange is the same shape for the flush path.
 */
#include "../include/Obj14331.h"

typedef unsigned long u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);

void WIFIBATTLEMATCH_NET_SetTimingSyncRange(char *obj, u32 v)
{
    ((struct Obj14331 *)obj)->f14 = v;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)((struct Obj14331 *)obj)->f14, 0x24);
}

