/*
 * function: func_0216A184
 * address:  0x0216A184
 * packet:   pkt_0216A184
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 */
#include "../include/Obj00029.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02027974();
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern int func_02027858();

int func_0216A184(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027974(a0);
loc_0216A190:
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_020279E8((struct TaskMenu *)a0);
loc_0216A198:
    if (a0 != 1) goto loc_0216A1B8;
loc_0216A19C:
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027A04((const u8 *)a0);
loc_0216A1A4:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027858(a0);
loc_0216A1AE:
a0 = 1;
    if (t4 != 0) goto loc_0216A1BC;
loc_0216A1B4:
a0 = 0;
    return a0;
loc_0216A1B8:
a0 = 0;
a0 = ~a0;
loc_0216A1BC:
    return a0;}
