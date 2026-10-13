/*
 * function: SCRCMD_CreateTrainerEye
 * address:  0x021AE948
 * packet:   pkt_ov021_021AE948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   EVENT_TRAINER_EYE_Create  0x021AE454  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern u32 EVENT_TRAINER_EYE_Create(void *a, u32 b, u32 *c, u32 d);

int SCRCMD_CreateTrainerEye(u32 a, u32 b)
{
    u32 k;
    void *p;
    u32 *q;
    u32 *e;

    p = SCRCMD_WORK_GetScriptWork((void *)b);
    q = (u32 *)SCRIPT_WORK_ResetFieldParam((int)p);
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    if (k == 0) {
        e = (u32 *)SCRIPT_WORK_GetTrainerEntry(p, 0);
    } else if (k == 1) {
        e = (u32 *)SCRIPT_WORK_GetTrainerEntry(p, 1);
    }
    e[6] = EVENT_TRAINER_EYE_Create((void *)SCRCMD_WORK_GetHeapId((void *)b), q[1], e, k);
    return 0;
}
