/*
 * function: SCRCMD_PushAndPlayBgm
 * address:  0x021AF2F4
 * packet:   pkt_ov021_021AF2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(void *a, u32 b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PushAndPlayBgm(u32 a, u32 b)
{
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRIPT_SYS_CallEvent(x, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(y, VM_GetU16((struct Stream *)a)));
    return 1;
}
