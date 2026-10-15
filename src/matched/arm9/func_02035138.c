/*
 * function: UI_SetWakePoweredHookGlobal
 * address:  0x02035138
 * packet:   pkt_02035138
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState    0x021469BC  data
 *   UI_SetWakePoweredHook 0x0203512C  arm
 *
 * Tail call: UI_SetWakePoweredHook(*gUiState, fn, arg).  Called from GAMESYSTEM_RegisterSleepCallback
 * and GAMESYSTEM_ReleaseSleepCallback.
 */

typedef unsigned int u32;

extern void *gUiState;
struct Obj02035120;
extern void UI_SetWakePoweredHook(struct Obj02035120 *p, u32 a, u32 b);

void UI_SetWakePoweredHookGlobal(void *fn, u32 arg)
{
    UI_SetWakePoweredHook(gUiState, (u32)fn, arg);
}
