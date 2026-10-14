/*
 * function: func_021F89D0
 * address:  0x021F89D0
 * packet:   pkt_021F89D0
 * region:   ov184
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The table slot must be spelled `a[i + 1]` (indexed form).  The byte-offset
 * spelling `*(int *)((char *)a + 4 + i * 4)` folds `a + 4` into a base
 * register and rotates the loop's registers; the subscript keeps the table
 * pointer in r6, i in r4 and 0 in r7, and recomputes `a + i*4 + 4`.
 *
 * symbols:
 *   BR_RES_ReleaseSprite   0x021FC0C8  thumb
 *   BR_RES_ApplyBgSet   0x021FBDA4  thumb
 *   func_021FB494   0x021FB494  thumb
 *
 * If the lead handle is live, flush the two sub-slots and clear them.
 */
#include "../include/Obj04581.h"


extern void BR_RES_ReleaseSprite(int, int);
extern void BR_RES_ApplyBgSet(int, int);
extern void func_021FB494(int);

void func_021F89D0(int *a, char *p)
{
    int i;
    if (a[1] != 0) {
        BR_RES_ReleaseSprite(((struct Obj04581 *)p)->fC, 6);
        BR_RES_ApplyBgSet(((struct Obj04581 *)p)->fC, 0x17);
        for (i = 0; i < 2; i++) {
            func_021FB494(a[i + 1]);
            a[i + 1] = 0;
        }
    }
}
