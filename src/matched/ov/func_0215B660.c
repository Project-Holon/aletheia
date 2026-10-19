/*
 * function: SCRCMD_PROC_CheckMonHpNotFullOrEgg
 * address:  0x0215B660
 * packet:   pkt_0215B660
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */
#include "../include/Obj04130.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int SCRCMD_PROC_CheckMonHpNotFullOrEgg(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215B66C:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215B676:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = SCRCMD_PROC_GetPartyMember((void *)a0, a1, (void **)a2);
loc_0215B684:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B688:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0xa0;
a2 = t6 + 0;
    a0 = (int)POKE_TOOL_GetPartyValue((void *)a0, a1, a2);
loc_0215B692:
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x10;
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0xa1;
a2 = t6 + 0;
    a0 = (int)POKE_TOOL_GetPartyValue((void *)a0, a1, a2);
loc_0215B6A0:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    if (t5 == a0) goto loc_0215B6B6;
loc_0215B6A8:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = (int)POKE_TOOL_GetPartyValue((void *)a0, a1, a2);
loc_0215B6B2:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B6B6:
a0 = 1;
*q = a0;
loc_0215B6BA:
a0 = 0;
    return a0;
}
