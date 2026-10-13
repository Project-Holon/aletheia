/*
 * unit:     yes
 * function: GIMMICK_OBJ_ELBOARD_GetScroll, GIMMICK_OBJ_ELBOARD_GetHeapId, GIMMICK_OBJ_ELBOARD_GetLineCount
 * address:  0x021F47B0
 * packet:   pkt_021F47B0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * int getter, u16 getter, u8 getter.
 */
#include "../include/Obj20545.h"
#include "../include/Obj20546.h"
#include "../include/Obj20547.h"

int GIMMICK_OBJ_ELBOARD_GetScroll(void *p)
{
    return ((struct Obj20545 *)p)->f18;
}

int GIMMICK_OBJ_ELBOARD_GetHeapId(void *p)
{
    return ((struct Obj20546 *)p)->f0;
}

int GIMMICK_OBJ_ELBOARD_GetLineCount(void *p)
{
    return ((struct Obj20547 *)p)->f2;
}
