/*
 * function: PDC_GetMyItem
 * address:  0x021B614C
 * packet:   pkt_ov098_021B614C
 * region:   ov098
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    getter, ldr r0,[r0,#0x10]; bx lr. Witness for calls in ov098 PDC_MAIN_StepChooseItem (2026-10-05, lane W-B).
 */

int PDC_GetMyItem(int *p)
{
    return p[4];
}
