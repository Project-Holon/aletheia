/*
 * function: BTLV_EFFVM_CmdReleaseClact
 * address:  0x021FB8F4
 * packet:   pkt_ov094_021FB8F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: releases slot arg of the table at 0xcc and marks it free.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFECT_GetClact 0x021F86F0 thumb ov094
 *   BTLV_CLACT_ReleaseActor 0x02201CA4 thumb ov094
 */
#include "../include/Obj21671.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetClact(void);
struct Res;
extern void BTLV_CLACT_ReleaseActor(struct Res *r, int i);

int BTLV_EFFVM_CmdReleaseClact(void *a, char *s)
{
    int *tab = (int *)(s + 0xcc);
    int i = VM_GetU32(a);

    BTLV_CLACT_ReleaseActor((struct Res *)BTLV_EFFECT_GetClact(), tab[i]);
    tab[i] = -1;
    return ((struct Obj21671 *)s)->f23C;
}
