/*
 * function: FLDMMDL_MOVE_ClearFellowTracking
 * address:  0x0219BB3C
 * packet:   pkt_0219BB3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb
 */

void *FLDMMDL_GetMoveProcWork(void);

void FLDMMDL_MOVE_ClearFellowTracking(void)
{
    char *p = FLDMMDL_GetMoveProcWork();

    p[1] = 0;
}
