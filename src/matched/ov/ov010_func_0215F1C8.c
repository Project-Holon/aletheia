/*
 * function: SCRCMD_NETWORK_CmdWaitCommState
 * address:  0x0215F1C8
 * packet:   pkt_ov010_0215F1C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   SCRCMD_NETWORK_sFileName     0x0217294C  data  ov010  a4
 *   SCRCMD_NETWORK_WaitCommState  0x0215F168  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 */

typedef unsigned short u16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned int   u32;
extern void *SCRIPT_WORK_GetUserWorkPtr(void *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char SCRCMD_NETWORK_sFileName[];
extern int SCRCMD_NETWORK_WaitCommState(int a0, int a1);
extern void VM_SetWait(char *p, int val);

int SCRCMD_NETWORK_CmdWaitCommState(void *a, void *b)
{
    void **slot;
    u16 *w;
    void **p;

    slot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(b));
    w = SCRIPT_WORK_ReadWorkPointer(a, b);
    p = func_02030734(4, 4, 1, SCRCMD_NETWORK_sFileName, 0x63);
    *slot = p;
    *p = w;
    *w = 0;
    VM_SetWait(a, (int)SCRCMD_NETWORK_WaitCommState);
    return 1;
}
