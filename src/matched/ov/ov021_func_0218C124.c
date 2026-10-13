/*
 * function: FIELD_BUILDMODEL_UpdateAnimSet
 * address:  0x0218C124
 * packet:   pkt_ov021_0218C124
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelAnimDefs  0x0218BCAC  thumb  ov021
 *   gBuildModelAnimOpsTable     0x021D3D5C  data  a4
 */

#include "../include/G_Ops.h"

typedef struct {
    void (*f0)(void *p, void *s);
    void (*f4)(void *p, int idx, int c);
    void (*f8)(void);
} Ops;

typedef struct {
    int f0;
    int *f4;
} Obj;

extern struct Ops gBuildModelAnimOpsTable[];
typedef unsigned char  u8;
u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);

void FIELD_BUILDMODEL_UpdateAnimSet(void *p, Obj *s)
{
    unsigned char k = *FIELD_BUILDMODEL_GetModelAnimDefs((u8 *)(*s->f4));
    if (s->f0 != 0)
        gBuildModelAnimOpsTable[k].f0(p, s);
}
