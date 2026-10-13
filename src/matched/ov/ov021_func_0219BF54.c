/*
 * function: FLDMMDL_MOVE_SetHideNoEffect
 * address:  0x0219BF54
 * packet:   pkt_0219BF54
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

void FLDMMDL_MOVE_SetHideNoEffect(int a0)
{
    char *p = FLDMMDL_GetMoveProcWork();

    p[2] = 1;
}
