/*
 * function: SCRCMD_PROC_CheckMonIsEgg
 * address:  0x0215B6C0
 * packet:   pkt_0215B6C0
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
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int SCRCMD_PROC_CheckMonIsEgg(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215B6CC:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215B6D6:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = SCRCMD_PROC_GetPartyMember((void *)a0, a1, (void **)a2);
loc_0215B6E4:
    if (a0 != 1) goto loc_0215B6FE;
loc_0215B6E8:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = POKE_TOOL_GetPartyValue((void *)a0, a1, a2);
loc_0215B6F2:
    if (a0 != 0) goto loc_0215B6FA;
loc_0215B6F6:
*q = t6;
    goto loc_0215B6FE;
loc_0215B6FA:
a0 = 1;
*q = a0;
loc_0215B6FE:
a0 = 0;
    return a0;
}
