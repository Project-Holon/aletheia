/*
 * function: INTRUDE_COMM_OnSessionExit
 * address:  0x02173580
 * packet:   pkt_ov011_02173580
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Callback leaf: sets the state byte at 0x8FD to 10.  It saves nothing, so
 * disasm.py left it as .word data; its only reference is the function
 * pointer INTRUDE_COMM_Shutdown hands to GFL_NET_Exit, which is why it is filed
 * here, to give that pool word a matched witness.
 */

typedef unsigned char u8;

void INTRUDE_COMM_OnSessionExit(u8 *w)
{
    w[0x8fd] = 10;
}
