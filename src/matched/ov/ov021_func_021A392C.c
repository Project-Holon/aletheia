/*
 * function: FIELD_PLAYER_CORE_SetDirDisp
 * address:  0x021A392C
 * packet:   pkt_ov021_021A392C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x1c]; ldr r3,[pc,#4]; bx r3; nop; .word 0x0216D5E1
 * The pool word carries the Thumb bit for FLDMMDL_SetDirDispCheckPause, which is traced
 * only in ov010 (0x0216D5E0 is data in ov009), so the hint names ov010.
 *
 * symbols:
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */
#include "../include/Obj19776.h"

extern void FLDMMDL_SetDirDispCheckPause(int, int);

void FIELD_PLAYER_CORE_SetDirDisp(void *p, int b)
{
    FLDMMDL_SetDirDispCheckPause(((struct Obj19776 *)p)->f1C, b);
}
