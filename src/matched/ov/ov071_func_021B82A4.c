/*
 * function: MONOLITH_TOOL_MENU_UpdateButtons
 * address:  0x021B82A4
 * packet:   pkt_ov071_021B82A4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MONOLITH_TOOL_UpdateHighlight  0x021B6C7C  thumb  ov071
 *   MONOLITH_TOOL_IsButtonUploaded  0x021B6B70  thumb  ov071
 *   d_021BA978     0x021BA978  data  a4
 */
#include "../include/Obj20722.h"

extern unsigned d_021BA978[];

typedef unsigned char  u8;
void MONOLITH_TOOL_MENU_UpdateButtons(int *a, char *p)
{
    void MONOLITH_TOOL_UpdateHighlight(int *p, int idx);
    int MONOLITH_TOOL_IsButtonUploaded(void **p, u8 *q);
    unsigned i;

    MONOLITH_TOOL_UpdateHighlight(a, 3);
    for (i = 0; i < d_021BA978[((struct Obj20722 *)p)->f32]; i++) {
        MONOLITH_TOOL_IsButtonUploaded((void **)a[1], (u8 *)(p + i * 16));
    }
}
