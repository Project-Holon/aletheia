/*
 * function: SCRCMD_WORK_CmdGetFieldRecordB
 * address:  0x0215AB3C
 * packet:   pkt_0215AB3C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_CLOCK_GetWeek  0x021690F0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int FIELD_CLOCK_GetWeek(int a0);

int SCRCMD_WORK_CmdGetFieldRecordB(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215AB48:
a0 = t5 + 0;
a1 = t6 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AB52:
    a0 = FIELD_CLOCK_GetWeek((int)v0);
loc_0215AB5A:
*q = a0;
a0 = 0;
    return a0;}
