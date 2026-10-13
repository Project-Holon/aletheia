/*
 * function: NO_GEAR_StoreStepFunc
 * address:  0x021EFEC0
 * packet:   pkt_021EFEC0
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte Thumb leaf (`str r1,[r0]; bx lr`), emitted as a data
 * word by disasm.py because it saves no lr, but a real function start: it is
 * the tail-call target of NO_GEAR_SetStepFunc. Matching it here turns that tail
 * call into a `matched` relocation.
 *
 * symbols:
 *   NO_GEAR_StoreStepFunc  0x021EFEC0  thumb
 */

void NO_GEAR_StoreStepFunc(int *p, int v)
{
    *p = v;
}
