/*
 * function: FLDMMDL_SetAreaIdRef
 * address:  0x0216CDB8
 * packet:   pkt_ov010_0216CDB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thumb leaf (store, then tail call through a pool word), the
 * sole blocker of ov021 FIELDMAP_SetupMmdlSys (lane S26).
 * symbols:
 *   FLDMMDL_SysSetDrawInit  0x0216D95C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19116.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void FLDMMDL_SysSetDrawInit(unsigned int *p, unsigned int v, int a2);

void FLDMMDL_SetAreaIdRef(u8 *p, u32 v, int a2)
{
    ((struct Obj19116 *)p)->f40 = v;
    FLDMMDL_SysSetDrawInit((unsigned int *)p, 1, a2);
}
