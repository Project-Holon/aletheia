/*
 * function: GAME_DATA_GetListCursor
 * address:  0x02012F50
 * packet:   pkt_02012F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: base + 0x6A4.  No register-saving prologue, so
 * disasm.py never traced a func_ label here; matching it gives the overlay
 * call sites a `matched` witness.
 *
 * symbols:
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 */

void *GAME_DATA_GetListCursor(void *base)
{
    return (char *)base + 0x6A4;
}
