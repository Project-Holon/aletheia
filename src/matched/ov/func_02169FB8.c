/*
 * function: func_02169FB8
 * address:  0x02169FB8
 * packet:   pkt_02169FB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_02169F34  0x02169F34  thumb  ov010
 */
#include "../include/Obj00029.h"
#include "../include/Obj04885.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020310C4();
extern int func_020286C4();
extern int func_02169F34(u8 *p);

int func_02169FB8(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)((char *)a0))->f0;
    a0 = func_020310C4(a0);
loc_02169FC4:
a2 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = ((struct Obj04885 *)a2)->f1C;
a1 = ((struct Obj04885 *)a2)->f10;
a2 = ((struct Obj04885 *)a2)->f8;
    a0 = func_020286C4(a0, a1, a2);
loc_02169FD0:
a0 = t4 + 0;
    a0 = func_02169F34((u8 *)a0);
loc_02169FD6:
    if (a0 != 0) goto loc_02169FDE;
loc_02169FDA:
a0 = 0;
    return a0;
loc_02169FDE:
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)((char *)a0))->f0;
    a0 = func_020310C4(a0);
loc_02169FE6:
a2 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = ((struct Obj04885 *)a2)->f1C;
a1 = ((struct Obj04885 *)a2)->f10;
a2 = ((struct Obj04885 *)a2)->f8;
    a0 = func_020286C4(a0, a1, a2);
loc_02169FF2:
a0 = t4 + 0;
    a0 = func_02169F34((u8 *)a0);
loc_02169FF8:
    return a0;}
