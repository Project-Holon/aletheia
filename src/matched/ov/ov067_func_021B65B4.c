/*
 * function: TOUCHBAR_ResetAndEnableButton
 * address:  0x021B65B4
 * packet:   pkt_ov067_021B65B4
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHBAR_SetButtonEnabled  0x021B6548  thumb
 *
 * Seeded start (layout/function_starts.txt): no lr-saving prologue, so the
 * listing showed it as data.  Referenced by ov119 func_021D8980, which does
 * bl 0x021B65B4 (r0 = object, r1 = 1) at 0x021D898C right before its calls
 * to 0x021B6558 and 0x021B6548; those two are ov067-only starts, so the
 * window is ov067 (ov071's own 0x021B65B4 is unrelated code).
 *
 * Clears +0x08, sets +0x00 to -1 (the `subs r2, #1` reuses the zero), then
 * tail-calls TOUCHBAR_SetButtonEnabled(p, a1, 1) through `ldr r3, =func; bx r3`.
 */

typedef unsigned int u32;

extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);

void TOUCHBAR_ResetAndEnableButton(u32 *p, u32 a1)
{
    p[2] = 0;
    p[0] = (u32)-1;
    TOUCHBAR_SetButtonEnabled((unsigned char *)p, a1, 1);
}
