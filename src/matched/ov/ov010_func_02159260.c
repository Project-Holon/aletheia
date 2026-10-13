/*
 * function: SCRIPT_WORK_CmdTimeWait
 * address:  0x02159260
 * packet:   pkt_02159260
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching SCRIPT_WORK_WaitTime (ov010, EXACT; itself unblocked by
 * SCRCMD_WORK_CountDownWait). The ABS32 pool word +0x20 now attests as `matched`.
 *
 * Registers the second argument under the key the first argument yields,
 * and installs the in-overlay handler the pool names.
 *
 * symbols:
 *   SCRCMD_WORK_SetWaitCount   0x0215A684  thumb  ov010
 *   VM_GetU16   0x02011330  thumb
 *   VM_SetWait   0x020113D0  thumb
 *   SCRIPT_WORK_WaitTime   0x02159254  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void SCRCMD_WORK_SetWaitCount(int *p, unsigned short v);
extern void VM_SetWait(char *p, int val);
extern void SCRIPT_WORK_WaitTime(char *a0, char *a1);

int SCRIPT_WORK_CmdTimeWait(void *a0, void *a1)
{
    SCRCMD_WORK_SetWaitCount(a1, VM_GetU16(a0));
    VM_SetWait(a0, (int)SCRIPT_WORK_WaitTime);

    return 1;
}

