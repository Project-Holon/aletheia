/*
 * unit:     no
 * function: GAME_DATA_SaveStart
 * address:  0x02012DAC
 * packet:   pkt_02012BF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SAVE_CONTROL_StartSave  0x02007150  thumb
 *   WIH_DWC_PauseTimers  0x0201042C  thumb
 *   GAME_DATA_WriteToSave  0x02012CE0  thumb
 */
#include "../include/Obj00054.h"

int GAME_DATA_SaveStart(int a0){ int t0, t1, t2, t3; t0 = GAME_DATA_WriteToSave(a0); t1 = WIH_DWC_PauseTimers((int)t0); *(unsigned char *)(((char *)((a0 + 0)) + ((int)(0x1CE) << 0))) = (unsigned char)1; t2 = func_0203516C((int)2, (int)1); t3 = SAVE_CONTROL_StartSave((int)*(int *)&((struct Obj00054 *)((char *)((a0 + 0))))->f0); return t3; }
