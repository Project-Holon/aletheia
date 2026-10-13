/*
 * function: SCRCMD_GIMMICK45_CallEvent
 * address:  0x021B26AC
 * packet:   pkt_ov021_021B26AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GIMMICK45_StartSecondarySwitchEvent  0x021F384C  thumb  ov045
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *GIMMICK45_StartSecondarySwitchEvent(void *a, int b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_GIMMICK45_CallEvent(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    u32 r = (u32)GIMMICK45_StartSecondarySwitchEvent(d, VM_GetU16((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(s, (void *)r);
    return 1;
}
