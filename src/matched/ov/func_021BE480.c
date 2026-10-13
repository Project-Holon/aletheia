/*
 * function: FLD_EXP_OBJ_GetModelStatus
 * address:  0x021BE480
 * packet:   pkt_021BE480
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb
 *
 * Unlabelled leaf in ov021, immediately after FLD_EXP_OBJ_RemoveUnit's epilogue
 * (0x021BE47C) and before the next traced function at 0x021BE4A4; it saves
 * nothing, so disasm.py prints it inside the pool/.word run.  It is the
 * blocker target of ov010's NAMEIN_SETUP_SyncObjHeightToAnim (pkt_0216C280), reached across the
 * ov010/ov021 overlay pair.  Element lookup: stride 0x10, null when the +8
 * slot is zero or the index is out of range, else base + index*0x44 + 8.
 */
#include "../include/Obj12119.h"

typedef unsigned int u32;

int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j)
{
    char *e = p + i * 0x10;

    if (((struct Obj12119 *)e)->f8 == 0)
        return 0;
    if (i >= 4)
        return 0;
    return ((struct Obj12119 *)e)->fC + j * 0x44 + 8;
}
