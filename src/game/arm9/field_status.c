/*
 * file:     field_status.c
 * unit:     yes
 * function: FIELD_STATUS_CreateSubProcListEvent
 * address:  0x02014910
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mcss.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "field_status_shared_types.h"

extern void *func_020122C0(void *owner, void *parent, void *callback, u32 workSize);

extern void *func_020124E8(void *task);

extern u32 func_02014878(u32 task, u32 *mode, u32 *taskWork);

void *FIELD_STATUS_CreateSubProcListEvent(void *anime, int slot, int config, int target);

/*
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           func_02014878 is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */
void *FIELD_STATUS_CreateSubProcListEvent(void *anime, int slot, int config, int target)
{
    void *task = func_020122C0(anime, 0, (void *)((int)func_02014878), 0x10);
    u32 *taskWork = func_020124E8(task);

    taskWork[0] = (u32)anime;
    taskWork[1] = slot;
    taskWork[2] = config;
    taskWork[3] = target;
    return task;
}
