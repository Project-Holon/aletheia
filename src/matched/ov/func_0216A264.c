/*
 * function: REPORT_EVENT_StartSaveEffect
 * address:  0x0216A264
 * packet:   pkt_0216A264
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_SAVEANIME_Create  0x021D1164  thumb
 *   FIELD_SAVEANIME_Start  0x021D11B0  thumb
 */
#include "../include/Obj00029.h"
#include "../include/Obj17755.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELD_SAVEANIME_Create(u32 heap, u32 v);
extern int FIELD_SAVEANIME_Start();

int REPORT_EVENT_StartSaveEffect(int a0)
{
    int a1;
    int t4;
    void *p;

t4 = a0 + 0;
a0 = ((struct Obj00029 *)t4)->f10;
a1 = *(int *)&((struct Obj00029 *)t4)->f8;
    p = FIELD_SAVEANIME_Create(a0, a1);
loc_0216A270:
a1 = *(int *)&((struct Obj00029 *)t4)->f18;
((struct Obj17755 *)a1)->f48 = p;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
p = ((struct Obj00029 *)a0)->f48;
    a0 = FIELD_SAVEANIME_Start(p, a1);
loc_0216A27C:
    return a0;}
