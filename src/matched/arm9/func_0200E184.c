/*
 * function: SYMBOL_SAVE_FindBandThunk
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
 *   SYMBOL_SAVE_FindBand  0x0200E0BC  thumb
 *
 * notes:    Thumb thunk (ldr r3,[pc]; bx r3) to SYMBOL_SAVE_FindBand; a tail call. Witness for the call in ov010 SYMBOL_MAP_MoveRecordToPairedBand (2026-10-05, lane W-B).
 */

extern unsigned int SYMBOL_SAVE_FindBand(unsigned int);

unsigned int SYMBOL_SAVE_FindBandThunk(unsigned int a)
{
    return SYMBOL_SAVE_FindBand(a);
}
