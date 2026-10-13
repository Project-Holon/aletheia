/*
 * function: SCRCMD_WORK_SaveScriptState
 * address:  0x0215AA24
 * packet:   pkt_0215AA24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_BackupLocalWork  0x0215909C  thumb  ov010
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_BackupLocalWork(u8 *a);

void *SCRCMD_WORK_SaveScriptState(int a0)
{
    int t4;
    void *p;
    void *v0;

t4 = a0 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215AA2C:
    p = SCRIPT_WORK_BackupLocalWork((u8 *)v0);
loc_0215AA30:
((struct Obj00005 *)t4)->f1C = p;
    return p;}
