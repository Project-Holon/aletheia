/*
 * function: SCRCMD_GIMMICK39_CallEvent
 * address:  0x021B2380
 * packet:   pkt_ov021_021B2380
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GIMMICK39_CreateSwitchEvent  0x021F3E24  thumb  ov039
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern int GIMMICK39_CreateSwitchEvent(void *a, u32 b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_GIMMICK39_CallEvent(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    u8 k = VM_GetU16((struct Stream *)a);
    u32 r = GIMMICK39_CreateSwitchEvent(d, k);

    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(s, (void *)r);
    return 1;
}
