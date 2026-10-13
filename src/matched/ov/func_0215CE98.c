/*
 * function: SCRCMD_PROC_GetDaycareState
 * address:  0x0215CE98
 * packet:   pkt_0215CE98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * unblocked: SODATEYA_HasEgg (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SODATEYA_HasEgg  0x021C3400  thumb  ov021
 */
#include "../include/Obj17693.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(void *a0);
extern int SODATEYA_HasEgg(void *a);

int SCRCMD_PROC_GetDaycareState(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215CEA0:
a0 = t5 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215CEA8:
    v2 = GAMESYSTEM_GetFieldMap(v1);
loc_0215CEAC:
    a0 = SODATEYA_HasEgg(FIELDMAP_GetSodateya(v2));
loc_0215CEB0:
loc_0215CEB4:
((struct Obj17693 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}
