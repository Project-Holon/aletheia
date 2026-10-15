/*
 * function: UI_SetWakeHookGlobal
 * address:  0x02035040
 * packet:   pkt_02035040
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState    0x021469BC  data
 *   UI_SetWakeHook 0x02035034 arm
 *
 * Wrapper: calls UI_SetWakeHook with the object gUiState points at as the first argument.
 */

typedef unsigned int u32;

extern char *gUiState;
extern void UI_SetWakeHook(char *o, u32 a, u32 b);

void UI_SetWakeHookGlobal(u32 a, u32 b)
{
    UI_SetWakeHook(gUiState, a, b);
}
