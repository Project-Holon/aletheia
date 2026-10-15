/*
 * function: MONOLITH_TOOL_SLOT_SELECT_SetMode
 * address:  0x021B7BFC
 * packet:   pkt_ov071_021B7BFC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MONOLITH_TOOL_SetButtonVisible  0x021B6B58  thumb  ov071
 */
#include "../include/Obj20705.h"

void MONOLITH_TOOL_SLOT_SELECT_SetMode(int *a, char *p, unsigned char m)
{
    void MONOLITH_TOOL_SetButtonVisible(void **p, int v);

    if (m == 0) {
        MONOLITH_TOOL_SetButtonVisible((void **)(p + 0x2c), 1);
        MONOLITH_TOOL_SetButtonVisible((void **)(p + 0x3c), 0);
    } else {
        *(unsigned char *)a[2] = 6;
        MONOLITH_TOOL_SetButtonVisible((void **)(p + 0x2c), 0);
        MONOLITH_TOOL_SetButtonVisible((void **)(p + 0x3c), 1);
    }
    ((struct Obj20705 *)p)->f82 = m;
}
