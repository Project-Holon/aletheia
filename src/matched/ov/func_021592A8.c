/*
 * function: SCRIPT_WORK_CmdDebugWork
 * address:  0x021592A8
 * packet:   pkt_021592A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);

int SCRIPT_WORK_CmdDebugWork(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_021592B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_021592BC:
a0 = 0;
    return a0;}
