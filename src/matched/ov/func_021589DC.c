/*
 * function: SCRIPT_SYS_GetFromWork
 * address:  0x021589DC
 * packet:   pkt_021589DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   func_020124E8  0x020124E8  thumb
 */
#include "../include/Obj01023.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void *SCRIPT_WORK_GetEvent(void *p);
extern void *func_020124E8(struct Obj *p);

int SCRIPT_SYS_GetFromWork(int a0)
{
    void *p;

    p = SCRIPT_WORK_GetEvent((void *)a0);
loc_021589E2:
    if (p != 0) goto loc_021589EA;
loc_021589E6:
a0 = 0;
    return a0;
loc_021589EA:
    p = func_020124E8((struct Obj *)p);
loc_021589EE:
a0 = *(int *)&((struct Obj01023 *)p)->f4;
    return a0;}
