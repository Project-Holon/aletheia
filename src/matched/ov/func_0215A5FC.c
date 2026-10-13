/*
 * function: SCRCMD_WORK_GetMenuHeap
 * address:  0x0215A5FC
 * packet:   pkt_0215A5FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);

int SCRCMD_WORK_GetMenuHeap(int a0)
{
    void *v0;

    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215A602:
    a0 = SCRIPT_WORK_ResetFieldParam((int)v0);
loc_0215A606:
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}
