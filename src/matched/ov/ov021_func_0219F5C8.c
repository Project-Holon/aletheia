/*
 * function: FLDMMDL_DRAW_SetState
 * address:  0x0219F5C8
 * packet:   pkt_0219F5C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb
 */

typedef unsigned char u8;

void *FLDMMDL_GetDrawProcWork(void);

void FLDMMDL_DRAW_SetState(void *a, int v)
{
    ((char *)FLDMMDL_GetDrawProcWork())[2] = v;
}
