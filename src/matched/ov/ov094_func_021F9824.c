/*
 * function: func_021F9824
 * address:  0x021F9824
 * packet:   pkt_ov094_021F9824
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns flag bit 6 of the owner's work when the handle at 0x1e8 is set, else -1.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 */
#include "../include/Obj21656.h"
typedef struct {
    unsigned lo : 6;
    unsigned b6 : 1;
} Flags;

struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);

int func_021F9824(void *a)
{
    Flags *s = func_02011324(a);
    int r = -1;

    if (((struct Obj21656 *)s)->f1E8 != 0)
        r = s->b6;
    return r;
}
