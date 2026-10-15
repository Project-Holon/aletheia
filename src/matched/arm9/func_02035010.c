/*
 * function: UI_SetSleepHookGlobal
 * address:  0x02035010
 * packet:   pkt_02035010
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState    0x021469BC  data
 *   UI_SetSleepHook 0x02035004 arm
 *
 * Wrapper: calls UI_SetSleepHook with the object gUiState points at as the first argument.
 */

typedef unsigned int u32;

extern char *gUiState;
extern void UI_SetSleepHook(char *o, u32 a, u32 b);

void UI_SetSleepHookGlobal(u32 a, u32 b)
{
    UI_SetSleepHook(gUiState, a, b);
}
