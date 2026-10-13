/*
 * function: SCRCMD_WORK_CmdGetFieldRecordPair
 * address:  0x0215AB60
 * packet:   pkt_0215AB60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int FIELD_CLOCK_GetMonth(int a0);
extern int FIELD_CLOCK_GetDay(int a0);

int SCRCMD_WORK_CmdGetFieldRecordPair(int a0, int a1)
{
    int t4;
    int t7;
    u16 *q;
    u16 *dst;
    void *v0;

t7 = a1 + 0;
t4 = a0 + 0;
a0 = t7 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215AB6C:
a0 = t4 + 0;
a1 = t7 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AB76:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AB80:
    a0 = FIELD_CLOCK_GetMonth((int)v0);
loc_0215AB88:
*q = a0;
    a0 = FIELD_CLOCK_GetDay((int)v0);
loc_0215AB90:
*dst = a0;
a0 = 0;
    return a0;}
