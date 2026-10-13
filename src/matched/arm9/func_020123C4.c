/*
 * unit:     no
 * function: GAME_EVENT_IsRunning
 * address:  0x020123C4
 * packet:   pkt_02012380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 */

struct Ctx;
extern unsigned int GAMESYSTEM_GetEvent(const struct Ctx *p);

int GAME_EVENT_IsRunning(void *a0){ unsigned int t0; t0 = GAMESYSTEM_GetEvent(a0); if ((unsigned int)(t0) != (unsigned int)(0)) {  return 1; } else {  return 0; } }
