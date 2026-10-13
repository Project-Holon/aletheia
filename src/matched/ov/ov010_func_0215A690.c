/*
 * function: SCRCMD_WORK_CountDownWait
 * address:  0x0215A690
 * packet:   pkt_0215A690
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: dependency of SCRIPT_WORK_WaitTime (tail-call pool word
 * 0x0215A691), which in turn unblocks SCRIPT_WORK_CmdTimeWait.
 */
#include "../include/Obj18794.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int SCRCMD_WORK_CountDownWait(char *a0)
{
    u16 *p = (u16 *)(*(char * *)&((struct Obj18794 *)a0)->f20 + 0x106);

    if (*p == 0)
        return 1;
    (*p)--;
    return 0;
}
