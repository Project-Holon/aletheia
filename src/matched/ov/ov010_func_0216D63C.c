/*
 * function: FLDMMDL_GetParam
 * address:  0x0216D63C
 * packet:   pkt_0216D63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: dependency of INTRUDE_FIELD_GetMmdlParam0 (ov018 tail-call
 * thunk), which unblocks SCRCMD_SYMBOL_SelectObjectEntry and SCRCMD_SYMBOL_MoveObjectEntryToPairedBand.
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int FLDMMDL_GetParam(char *a0, int a1)
{
    switch (a1) {
    case 0:
        return ((struct Obj00113 *)a0)->f20;
    case 1:
        return ((struct Obj00113 *)a0)->f22;
    case 2:
        return ((struct Obj00113 *)a0)->f24;
    default:
        return 0;
    }
}
