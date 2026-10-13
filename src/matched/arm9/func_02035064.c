/*
 * function: func_02035064
 * address:  0x02035064
 * packet:   pkt_02035064
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState    0x021469BC  data
 *
 * Stores a callback and its argument into the object gUiState points at
 * (+0x24 and +0x34).  The pointer is reloaded for the second store because
 * the first store may alias it.  Called from GAMESYSTEM_RegisterSleepCheck and
 * GAMESYSTEM_ReleaseSleepCheck.
 */

typedef unsigned int u32;

struct Obj021469BC {
    unsigned char pad[0x24];
    const void   *fn;
    unsigned char pad2[0x0C];
    u32           arg;
};

extern struct Obj021469BC *gUiState;

void func_02035064(const void *fn, u32 arg)
{
    gUiState->fn = fn;
    gUiState->arg = arg;
}
