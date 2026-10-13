/*
 * function: SCRIPT_WORK_WaitTime
 * address:  0x02159254
 * packet:   pkt_02159254
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691
 * (SCRCMD_WORK_CountDownWait). Matched so the ABS32 site in SCRIPT_WORK_CmdTimeWait attests as
 * `matched`.
 *
 * symbols:
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRCMD_WORK_CountDownWait(char *);

void SCRIPT_WORK_WaitTime(char *a0, char *a1)
{
    SCRCMD_WORK_CountDownWait(a1);
    (void)a0;
}
