/*
 * function: MONOLITH_TOOL_ApplyCursorChange
 * address:  0x021BA01C
 * packet:   pkt_ov071_021BA01C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MONOLITH_TOOL_ShowRowHighlight  0x021B9FEC  thumb  ov071
 *   MONOLITH_TOOL_SetButtonPulse  0x021B6C30  thumb  ov071
 *   MONOLITH_TOOL_SetButtonFlash  0x021B6C48  thumb  ov071
 *   MONOLITH_TOOL_HighlightButtonFlash  0x021B6BEC  thumb  ov071
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj00044.h"

typedef unsigned char u8;

extern void MONOLITH_TOOL_ShowRowHighlight(void *p, int a);
typedef unsigned int   u32;
extern void MONOLITH_TOOL_SetButtonPulse(int *p, int flag, int index);
extern void MONOLITH_TOOL_SetButtonFlash(void *p, int a);
extern void MONOLITH_TOOL_HighlightButtonFlash(void *p, int *tbl, int n, int sel, int c);
extern void func_02041B6C(u32 bit);

void MONOLITH_TOOL_ApplyCursorChange(void *a, u8 *p)
{
    int v;
    int m;

    if (((struct Obj00044 *)p)->f304 == 1) {
        MONOLITH_TOOL_ShowRowHighlight(p, ((struct Obj00044 *)p)->f2F4);
        v = ((struct Obj00044 *)p)->f2F4;
        if (v == 0xffff) {
            MONOLITH_TOOL_SetButtonPulse(a, 0, 1);
        } else {
            m = ((struct Obj00044 *)p)->f308;
            if ((m == 2 && v == ((struct Obj00044 *)p)->f2FC) || (m == 1 && v == ((struct Obj00044 *)p)->f2F8)) {
                if (*(int *)(p + 0x1b4 + v * 4) == 0) {
                    ((struct Obj00044 *)p)->f300 = v;
                    if (((struct Obj00044 *)p)->f308 == 1) {
                        MONOLITH_TOOL_SetButtonFlash(a, 1);
                    } else {
                        MONOLITH_TOOL_HighlightButtonFlash(a, (int *)(p + 8), 1, 0, 3);
                    }
                } else if (m == 2) {
                    MONOLITH_TOOL_SetButtonPulse(a, 1, 1);
                }
            } else {
                MONOLITH_TOOL_SetButtonPulse(a, 1, 1);
            }
        }
        func_02041B6C(6);
        ((struct Obj00044 *)p)->f304 = 0;
    }
}
