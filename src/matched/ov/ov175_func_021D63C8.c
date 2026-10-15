/*
 * function: WIFIBATTLEMATCH_NET_SetupBoxAndWait
 * address:  0x021D63C8
 * packet:   pkt_021D63C8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_SetupBoxRecord  0x021D62A4  thumb
 *   WIFIBATTLEMATCH_NET_IsBoxReady  0x021D63B0  thumb
 *
 * Runs WIFIBATTLEMATCH_NET_SetupBoxRecord once (the object's start-op) and then spins on
 *     WIFIBATTLEMATCH_NET_IsBoxReady until it reports the object ready.
 */

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_NET_SetupBoxRecord(u32 *p, u32 mode);
extern u32 WIFIBATTLEMATCH_NET_IsBoxReady(char *obj);

void WIFIBATTLEMATCH_NET_SetupBoxAndWait(char *obj, u32 arg)
{
    WIFIBATTLEMATCH_NET_SetupBoxRecord((u32 *)obj, arg);
    while (WIFIBATTLEMATCH_NET_IsBoxReady(obj) == 0)
        ;
}

