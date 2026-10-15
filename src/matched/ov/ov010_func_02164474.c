/*
 * function: FIELD_MAP_CHANGE_MoveActiveEntries
 * address:  0x02164474
 * packet:   pkt_ov010_02164474
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 EVENT_MAPCHANGE_ContinueEvent.
 *
 * symbols:
 *   MOVE_POKEMON_MoveActiveEntries  0x0215E364  thumb  ov010
 */

void MOVE_POKEMON_MoveActiveEntries(void *a);

void FIELD_MAP_CHANGE_MoveActiveEntries(int a, int b)
{
    MOVE_POKEMON_MoveActiveEntries((void *)a);
}
