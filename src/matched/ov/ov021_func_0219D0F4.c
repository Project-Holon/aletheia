/*
 * function: FLDMMDL_BLACT_AddReservedActors
 * address:  0x0219D0F4
 * packet:   pkt_ov021_0219D0F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_AddReservedActor  0x0219D064  thumb  ov021
 *   FLDMMDL_BLACT_ClearActorReserve  0x0219D1F8  thumb  ov021
 */
#include "../include/Obj00808.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 FLDMMDL_SysGetMmdlMax(void *p);
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern void FLDMMDL_BLACT_AddReservedActor(int *, int *);
typedef unsigned char  u8;
extern void FLDMMDL_BLACT_ClearActorReserve(u8 *p);

void FLDMMDL_BLACT_AddReservedActors(int *obj)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short sp[2];

    i = 0;
    n = FLDMMDL_SysGetMmdlMax((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    if (n == 0) {
        return;
    }
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && *((unsigned char *)p + 0xd) == 1) {
            if (FLDMMDL_BLACT_FindRes((u32)obj, ((struct Obj00808 *)p)->f8, (u32)(&sp[0]), (u32)(&sp[1])) == 1) {
                FLDMMDL_BLACT_AddReservedActor(obj, p);
                FLDMMDL_BLACT_ClearActorReserve((u8 *)p);
            }
        }
    }
}
