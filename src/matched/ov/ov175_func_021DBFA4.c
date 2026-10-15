/*
 * function: WIFIBATTLEMATCH_NET_GdbClearRecord
 * address: 0x021DBFA4
 * packet: pkt_ov175_021DBFA4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_SetupGdbRecord 0x021DB6A8 thumb ov175
 * leaf: reset request step then prepare four database fields.
 */
#include "../include/Obj01171.h"
extern void WIFIBATTLEMATCH_NET_SetupGdbRecord(char *);
void WIFIBATTLEMATCH_NET_GdbClearRecord(char *ctx)
{
    ((struct Obj01171 *)ctx)->f12C = 0;
    WIFIBATTLEMATCH_NET_SetupGdbRecord(ctx);
}
