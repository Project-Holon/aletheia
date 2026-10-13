/*
 * function: GIMMICK53_LoadWaitLimits
 * address:  0x021F3978
 * packet:   pkt_ov053_021F3978
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   sGimmick53WaitMembers     0x021F3CF0  data  a4
 */
#include "../include/Obj09845.h"

typedef struct { int v[5]; } T5;

extern T5 sGimmick53WaitMembers;
typedef unsigned int   u32;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);

void GIMMICK53_LoadWaitLimits(char *a)
{
    T5 t = sGimmick53WaitMembers;
    int i;

    for (i = 0; i < 5; i++) {
        int *p = ARC_TOOL_LoadMember(0x94, t.v[i], ((struct Obj09845 *)a)->f0);
        ((int *)(a + 0x30))[i] = p[0];
        ((int *)(a + 0x44))[i] = p[1];
        func_020307B0(p);
    }
}
