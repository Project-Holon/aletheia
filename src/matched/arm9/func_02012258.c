/*
 * unit:     no
 * function: GAMESYSTEM_ReleaseSleepCallback
 * address:  0x02012258
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UI_SetWakePoweredHookGlobal  0x02035138  arm
 */

typedef unsigned int   u32;
extern void UI_SetWakePoweredHookGlobal(void *fn, u32 arg);
void GAMESYSTEM_ReleaseSleepCallback(void *o)
{
    UI_SetWakePoweredHookGlobal(0, 0);
}
