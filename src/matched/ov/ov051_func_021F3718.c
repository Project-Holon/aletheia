/*
 * unit:     yes
 * function: FIELD_GIMMICK_D06_GetPanelPositions, FIELD_GIMMICK_D06_GetPanelCount
 * address:  0x021F3718
 * packet:   pkt_ov051_021F3718
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two accessors over the result of FIELD_GIMMICK_D06_FindPanelTable.
 *
 * symbols:
 *   FIELD_GIMMICK_D06_FindPanelTable  0x021F36F8  thumb  ov051
 */
#include "../include/Obj20555.h"
#include "../include/Obj20556.h"

int FIELD_GIMMICK_D06_GetPanelPositions(int a)
{
    void *FIELD_GIMMICK_D06_FindPanelTable(int a);
    return ((struct Obj20555 *)((char *)FIELD_GIMMICK_D06_FindPanelTable(a)))->f8;
}

int FIELD_GIMMICK_D06_GetPanelCount(int a)
{
    void *FIELD_GIMMICK_D06_FindPanelTable(int a);
    return ((struct Obj20556 *)((char *)FIELD_GIMMICK_D06_FindPanelTable(a)))->f4;
}
