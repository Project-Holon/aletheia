/*
 * function: SCRCMD_PROC_CheckPartyMonKnowsMove
 * address:  0x0215BAB0
 * packet:   pkt_0215BAB0
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
 *   SCRCMD_PROC_CheckMonKnowsMove  0x0215B500  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern int SCRCMD_PROC_CheckMonKnowsMove(int a0, int a1);

int SCRCMD_PROC_CheckPartyMonKnowsMove(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215BABA:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215BAC4:
t7 = a0 + 0;
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215BACE:
a1 = a0 + 0;
a0 = 0;
*q = a0;
a0 = t5 + 0;
a2 = (int)&v0;
    a0 = SCRCMD_PROC_GetPartyMember((void *)a0, a1, (void **)a2);
loc_0215BADC:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAE0:
    a0 = v0;
a1 = t7 + 0;
    a0 = SCRCMD_PROC_CheckMonKnowsMove(a0, a1);
loc_0215BAE8:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAEC:
a0 = 1;
*q = a0;
loc_0215BAF0:
a0 = 0;
    return a0;
}
