/*
 * function: SCRIPT_WORK_CmdChangeScript
 * address:  0x02159570
 * packet:   pkt_02159570
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_GetPlayerZoneId  0x02159B38  thumb  ov010
 *   SCRIPT_SYS_AddScript  0x021589A0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern int SCRIPT_WORK_GetPlayerZoneId(int a0);
extern int SCRIPT_SYS_AddScript(int a, int b, int c);

int SCRIPT_WORK_CmdChangeScript(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t5 = a1 + 0;
t4 = a0 + 0;
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215957C:
a0 = t5 + 0;
    v1 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_02159582:
a0 = t4 + 0;
    a0 = VM_GetU16((struct Stream *)a0);
loc_0215958A:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = SCRIPT_WORK_GetPlayerZoneId(a0);
loc_02159592:
a1 = a0 + 0;
a2 = t4 + 0;
    a0 = SCRIPT_SYS_AddScript((int)v1, a1, a2);
loc_0215959C:
a0 = 1;
    return a0;}
