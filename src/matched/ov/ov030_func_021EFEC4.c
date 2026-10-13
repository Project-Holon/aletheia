/*
 * function: NO_GEAR_SetStepFunc
 * address:  0x021EFEC4
 * packet:   pkt_ov030_021EFEC4
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to the unlabelled ov030 leaf NO_GEAR_StoreStepFunc; its ABS32 pool word
 * is now witnessed by the EXACT shard entry for NO_GEAR_StoreStepFunc (matched x1).
 *
 * symbols:
 *   NO_GEAR_SetStepFunc 0x021EFEC4 thumb
 *   NO_GEAR_StoreStepFunc 0x021EFEC0 thumb
 */

extern void NO_GEAR_StoreStepFunc(int *p, int v);

void NO_GEAR_SetStepFunc(int *p, int v)
{
    NO_GEAR_StoreStepFunc(p, v);
}
