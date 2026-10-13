/*
 * function: func_0200E184
 * address:  0x0200E184
 * packet:   pkt_0200E184
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200E0BC  0x0200E0BC  thumb
 *
 * notes:    Thumb thunk (ldr r3,[pc]; bx r3) to func_0200E0BC; a tail call. Witness for the call in ov010 SYMBOL_MAP_MoveRecordToPairedBand (2026-10-05, lane W-B).
 */

extern unsigned int func_0200E0BC(unsigned int);

unsigned int func_0200E184(unsigned int a)
{
    return func_0200E0BC(a);
}
