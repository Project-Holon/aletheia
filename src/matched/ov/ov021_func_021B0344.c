/*
 * function: SCRCMD_MSGWIN_CmdAddMenuItem
 * address:  0x021B0344
 * packet:   pkt_ov021_021B0344
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   SCRCMD_WORK_AddMenuItem  0x0215A7F0  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
typedef unsigned char  u8;
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
struct U16Vec;
extern void SCRCMD_WORK_AddMenuItem(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);

int SCRCMD_MSGWIN_CmdAddMenuItem(u32 a, u32 b)
{
    u32 x, y, z;
    void *t;

    t = SCRCMD_WORK_GetScriptWork((void *)b);
    x = VM_GetU16((struct Stream *)a);
    y = VM_GetU16((struct Stream *)a);
    z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRCMD_WORK_AddMenuItem((short unsigned int *)b, x, y, z, (struct U16Vec *)SCRIPT_WORK_GetMsgBuffer(t), (void *)SCRIPT_WORK_GetTempBuffer(t));
    return 0;
}
