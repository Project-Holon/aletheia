/*
 * function: WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait
 * address:  0x021D97D0
 * packet:   pkt_021D97D0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_SetupCompStatusWindow  0x021D965C  thumb
 *   WIFIBATTLEMATCH_NET_IsCompStatusWindowReady  0x021D97B8  thumb
 *
 * Start-op for the ov175 object's +0x1c stream: WIFIBATTLEMATCH_NET_SetupCompStatusWindow, then spin
 *     on WIFIBATTLEMATCH_NET_IsCompStatusWindowReady until it reports ready.  Mirrors WIFIBATTLEMATCH_NET_SetupBoxAndWait.
 */

typedef unsigned long u32;

struct Obj;
extern void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct Obj *obj);
extern u32 WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(char *obj);

void WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(char *obj)
{
    WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct Obj *)obj);
    while (WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(obj) == 0)
        ;
}

