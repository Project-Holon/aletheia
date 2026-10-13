/*
 * function: SCRCMD_PopBgmEvent
 * address:  0x021AF174
 * packet:   pkt_ov021_021AF174
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; } S;

extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PopBgmEvent(S *s, u32 *st)
{
    u32 x = s->f8;

    SCRIPT_WORK_ResetFieldParam(x);
    switch (*st) {
    case 0:
        SCRIPT_SYS_CallEvent((void *)x, FIELD_SOUND_SYSTEM_StartPopAndWaitTask((void *)s->f0, 0, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
