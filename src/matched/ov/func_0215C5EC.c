/*
 * function: SCRCMD_PROC_CallFieldOpenEvent
 * address:  0x0215C5EC
 * packet:   pkt_0215C5EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Two overlay lookups on the second argument, the second of them classified
 * by an arm9 call, then submitted together.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork   0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem   0x0215A5DC  thumb  ov010
 *   FIELD_STATUS_CreateFieldOpenEvent   0x020145CC  thumb
 *   SCRIPT_SYS_CallEvent   0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_PROC_CallFieldOpenEvent(void *a0, void *a1)
{
    void *v = SCRCMD_WORK_GetScriptWork(a1);

    SCRIPT_SYS_CallEvent(v, FIELD_STATUS_CreateFieldOpenEvent(SCRCMD_WORK_GetGameSystem(a1)));

    return 1;
}

