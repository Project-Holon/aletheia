/*
 * function: SCRCMD_GetTrainerEyeTrainerId
 * address:  0x021AE9F0
 * packet:   pkt_ov021_021AE9F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);

int SCRCMD_GetTrainerEyeTrainerId(u32 a, u32 b)
{
    u32 k;
    void *p;
    u16 *out;
    u32 *e;

    p = SCRCMD_WORK_GetScriptWork((void *)b);
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    e = 0;
    if (k == 0) {
        e = (u32 *)SCRIPT_WORK_GetTrainerEntry(p, 0);
    } else if (k == 1) {
        e = (u32 *)SCRIPT_WORK_GetTrainerEntry(p, 1);
    }
    *out = e ? e[4] : 0;
    return 0;
}
