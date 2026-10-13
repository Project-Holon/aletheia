/*
 * function: C_GEAR_ChangeStep
 * address:  0x021EFEF8
 * packet:   pkt_ov029_021EFEF8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_ChangeStep 0x021EFEF8 thumb
 *   C_GEAR_SetStepFunc 0x021EFEE4 thumb
 *
 * evidence: C_GEAR_SetStepFunc is ov029's own code (a store leaf ending in bx lr
 * after the bx lr at 0x021EFEE0), inside ov029's window, so only ov029 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov029's own listing.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */

extern void C_GEAR_SetStepFunc(unsigned char *p, unsigned int v);

void C_GEAR_ChangeStep(char *p, void (*f)(void), int line)
{
    C_GEAR_SetStepFunc((unsigned char *)p, (int)f);
}
