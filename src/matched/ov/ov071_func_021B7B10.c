/*
 * function: MONOLITH_TOOL_SLOT_SELECT_CreateButtons
 * address:  0x021B7B10
 * packet:   pkt_ov071_021B7B10
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MONOLITH_TOOL_ResetHighlights  0x021B6C54  thumb  ov071
 *   MONOLITH_TOOL_CreateButton  0x021B6A0C  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   MONOLITH_TOOL_HighlightButtonPulse  0x021B6B98  thumb  ov071
 *   MONOLITH_TOOL_SetButtonVisible  0x021B6B58  thumb  ov071
 */

extern void MONOLITH_TOOL_ResetHighlights(char *p);
extern void MONOLITH_TOOL_CreateButton(int a, void *b, int c, int d, int e, int f, int g, int h);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void MONOLITH_TOOL_HighlightButtonPulse(void *p, int *tbl, int n, int sel, int c);
extern void MONOLITH_TOOL_SetButtonVisible(void **p, int v);

void MONOLITH_TOOL_SLOT_SELECT_CreateButtons(int *a, char *b)
{
    MONOLITH_TOOL_ResetHighlights((char *)a);
    MONOLITH_TOOL_CreateButton(a[1], b + 0x2c, 1, 1, 0x80, 0x90, 14, 0);
    if (func_020355C4() == 0) {
        MONOLITH_TOOL_HighlightButtonPulse(a, (int *)(b + 0x2c), 1, 0, 3);
    } else {
        MONOLITH_TOOL_HighlightButtonPulse(a, (int *)(b + 0x2c), 1, 0xff, 3);
        b[0x83] = 1;
    }
    MONOLITH_TOOL_CreateButton(a[1], b + 0x3c, 1, 1, 0x80, 0x90, 15, 0);
    MONOLITH_TOOL_SetButtonVisible((void **)(b + 0x3c), 0);
}
