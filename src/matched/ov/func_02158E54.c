/*
 * function: SCRIPT_WORK_InitFieldParam
 * address:  0x02158E54
 * packet:   pkt_02158E54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_02082A7C  0x02082A7C  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb
 */
#include "../include/Obj00020.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int func_02082A7C();
extern int FIELDMAP_GetMsgBg();

int SCRIPT_WORK_InitFieldParam(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a0 + 0;
a0 = a1 + 0;
    t4 = GAMESYSTEM_GetFieldMap((const struct Ctx *)a0);
loc_02158E5E:
a0 = 0;
a1 = t5 + 0;
a2 = 8;
    a0 = func_02082A7C(a0, a1, a2);
loc_02158E6A:
((struct Obj00020 *)t5)->f4 = t4;
    if (t4 == 0) goto loc_02158E78;
loc_02158E70:
a0 = (int)t4 + 0; /* int-typed on purpose: pointer local changes codegen */
    a0 = FIELDMAP_GetMsgBg(a0);
loc_02158E76:
((struct Obj00020 *)((char *)t5))->f0 = a0;
loc_02158E78:
    return a0;}
