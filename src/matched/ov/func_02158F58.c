/*
 * function: SCRIPT_WORK_ResetFieldParam
 * address:  0x02158F58
 * packet:   pkt_02158F58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_InitFieldParam  0x02158E54  thumb  ov010
 */
#include "../include/Obj17630.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRIPT_WORK_InitFieldParam(int a0, int a1);

int SCRIPT_WORK_ResetFieldParam(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a1 = ((struct Obj17630 *)t4)->f10;
a0 = a0 + 0x18;
    a0 = SCRIPT_WORK_InitFieldParam(a0, a1);
loc_02158F64:
t4 = t4 + 0x18;
a0 = t4 + 0;
    return a0;}
