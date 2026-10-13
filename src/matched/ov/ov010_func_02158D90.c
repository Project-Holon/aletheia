/*
 * function: SCRIPT_SYS_IsZoneScriptId
 * address:  0x02158D90
 * packet:   pkt_ov010_02158D90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov010 listing): 0 for 2000, 1 below
 * 0x291C, else 0.  Callee of ov021 func_0218A0E4, FIELD_EVENT_CHECK_CheckRailEvents and
 * FIELD_EVENT_CHECK_CheckGridEvents.
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

int SCRIPT_SYS_IsZoneScriptId(u16 v)
{
    if (v == 2000)
        return 0;
    if (v < 0x291C)
        return 1;
    return 0;
}
