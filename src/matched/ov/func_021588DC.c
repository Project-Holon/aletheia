/*
 * function: SCRIPT_SYS_EventMain
 * address:  0x021588DC
 * packet:   pkt_021588DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_SYS_Main  0x0215882C  thumb  ov010
 *   SCRIPT_WORK_Delete  0x02158F18  thumb  ov010
 *   SCRIPT_SYS_HasEndCallback  0x021588C0  thumb  ov010
 *   SCRIPT_SYS_CallEndCallback  0x021588B0  thumb  ov010
 *   SCRIPT_SYS_Delete  0x02158824  thumb  ov010
 */
#include "../include/Obj12030.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRIPT_SYS_Main(int a0);
extern int SCRIPT_WORK_Delete(int a0);
extern int SCRIPT_SYS_HasEndCallback(int a0);
extern int SCRIPT_SYS_CallEndCallback();
extern int SCRIPT_SYS_Delete();

int SCRIPT_SYS_EventMain(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = ((struct Obj12030 *)a2)->f4;
t6 = a0 + 0;
a0 = t5 + 0;
t4 = ((struct Obj12030 *)((char *)a2))->f0;
    a0 = SCRIPT_SYS_Main(a0);
loc_021588EA:
    if (a0 != 1) goto loc_021588F2;
loc_021588EE:
a0 = 0;
    return a0;
loc_021588F2:
a0 = t4 + 0;
    a0 = SCRIPT_WORK_Delete(a0);
loc_021588F8:
a0 = t5 + 0;
    a0 = SCRIPT_SYS_HasEndCallback(a0);
loc_021588FE:
    if (a0 != 1) goto loc_02158914;
loc_02158902:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_SYS_CallEndCallback(a0, a1);
loc_0215890A:
a0 = t5 + 0;
    a0 = SCRIPT_SYS_Delete(a0);
loc_02158910:
a0 = 0;
    return a0;
loc_02158914:
a0 = t5 + 0;
    a0 = SCRIPT_SYS_Delete(a0);
loc_0215891A:
a0 = 1;
    return a0;}
