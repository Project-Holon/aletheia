/*
 * function: FLDMMDL_GetRealObjCode
 * address:  0x0216E3D0
 * packet:   pkt_ov010_0216E3D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0216E3D9);
 * the sole blocker of ov021 SCRCMD_FLDMMDL_AddMmdl.
 *
 * symbols:
 *   FLDMMDL_GetEventWorkObjCode  0x0216E3D8  thumb  ov010
 */

unsigned int FLDMMDL_GetEventWorkObjCode(unsigned int a, unsigned int id);

int FLDMMDL_GetRealObjCode(int a, int b)
{
    return FLDMMDL_GetEventWorkObjCode(a, b);
}
