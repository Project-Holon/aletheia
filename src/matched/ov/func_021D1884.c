/*
 * function: SCRCMD_MMDL_ICA_EndProc
 * address:  0x021D1884
 * packet:   pkt_021D1884
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0x188.
 *
 * symbols:
 *   FIELD_SUBPROC_End  0x021BBA1C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18374.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_SUBPROC_End(int *p);

void SCRCMD_MMDL_ICA_EndProc(u8 *p)
{
    FIELD_SUBPROC_End((int *)(((struct Obj18374 *)p)->f188));
}
