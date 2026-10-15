/*
 * function: SCRIPT_COMMAND_CmdStopSeq
 * address:  0x021FC5D8
 * packet:   pkt_021FC5D8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACTING_StopSeq  0x021F9690  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23266.h"

extern void STA_ACTING_StopSeq(char *p);

int SCRIPT_COMMAND_CmdStopSeq(int a, char **pp)
{
    STA_ACTING_StopSeq(((struct Obj23266 *)(*pp))->f34);
    return 0;
}
