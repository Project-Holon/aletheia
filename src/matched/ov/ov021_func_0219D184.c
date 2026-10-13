/*
 * function: FLDMMDL_BLACT_CancelReservedActor
 * address:  0x0219D184
 * packet:   pkt_ov021_0219D184
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_BLACT_FindReservedRes  0x0219CF00  thumb  ov021
 *   FLDMMDL_BLACT_CancelReservedRes  0x0219CF54  thumb  ov021
 *   FLDMMDL_BLACT_IsActorReservedByOther  0x0219D144  thumb  ov021
 *   FLDMMDL_BLACT_ClearActorReserve  0x0219D1F8  thumb  ov021
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */
#include "../include/Obj02699.h"

typedef unsigned short u16;
extern u16 FLDMMDL_SysGetMmdlMax(void *p);
extern int FLDMMDL_BLACT_FindReservedRes(int *, unsigned int, unsigned short *);
extern int FLDMMDL_BLACT_CancelReservedRes(int *, unsigned int);
extern int FLDMMDL_BLACT_IsActorReservedByOther(int *, unsigned int, int);
typedef unsigned char  u8;
extern void FLDMMDL_BLACT_ClearActorReserve(u8 *p);
struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FLDMMDL_BLACT_CancelReservedActor(int *obj, int key)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short s;

    i = 0;
    n = FLDMMDL_SysGetMmdlMax((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] == key) {
            *((unsigned char *)p + 0xd) = 0;
            if (FLDMMDL_BLACT_FindReservedRes(obj, ((struct Obj02699 *)p)->f8, &s) == 1 && (s & 1)) {
                if (FLDMMDL_BLACT_IsActorReservedByOther(obj, ((struct Obj02699 *)p)->f8, p[1]) == 0) {
                    FLDMMDL_BLACT_CancelReservedRes(obj, ((struct Obj02699 *)p)->f8);
                }
            }
            if (p[4] != 0) {
                G3D_SYSTEM_DeleteResource((void *)p[4]);
                p[4] = 0;
            }
            FLDMMDL_BLACT_ClearActorReserve((u8 *)p);
            return;
        }
    }
}
