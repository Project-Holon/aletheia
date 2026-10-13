/*
 * function: SCRCMD_GIMMICK38_CallCheckEvent
 * address:  0x021B273C
 * packet:   pkt_ov021_021B273C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent  0x021F3A88  thumb  ov038
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern int FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(int a0, int a1, int a2);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_GIMMICK38_CallCheckEvent(int a, int b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    int p = VM_GetU16((struct Stream *)a);
    int q = VM_GetU16((struct Stream *)a);
    int r = FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent((int)y, p, q);

    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(x, (void *)r);
    return 1;
}
