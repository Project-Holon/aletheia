/*
 * function: WIFIBATTLEMATCH_NET_IsTimingSyncRange
 * address:  0x021D9EEC
 * packet:   pkt_021D9EEC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *
 * Flush partner of WIFIBATTLEMATCH_NET_SetTimingSyncRange: sends the byte the object kept at
 *     +0x14 to 0x02039CB4 with the tick/state and line 0x24.
 */
#include "../include/Obj24327.h"

typedef unsigned long u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *tick, unsigned int value, unsigned int line);

int WIFIBATTLEMATCH_NET_IsTimingSyncRange(char *obj)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)((struct Obj24327 *)obj)->f14, 0x24);
}

