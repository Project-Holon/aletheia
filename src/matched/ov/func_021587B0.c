/*
 * function: SCRIPT_SYS_ChangeScriptEvent
 * address:  0x021587B0
 * packet:   pkt_021587B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   SCRIPT_SYS_CreateScriptEvent  0x02158920  thumb  ov010
 *   func_020124E8  0x020124E8  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 */
#include "../include/Obj17623.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void *func_020124E4(struct Obj *p);
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEvent(int a, int b, int c, int d, int e);
extern void *func_020124E8(struct Obj *p);
extern int GAME_EVENT_ChangeEvent();

int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;
    int o4;
    void *p;
    void *q;
    struct Desc *v0;
t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
t6 = a3 + 0;
    p = func_020124E4((struct Obj *)a0);
loc_021587BE:
a1 = 0;
    o4 = a1;
a1 = t6 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    v0 = SCRIPT_SYS_CreateScriptEvent((int)p, a1, a2, a3, o4);
loc_021587CC:
    q = func_020124E8((struct Obj *)v0);
loc_021587D2:
a0 = t7 + 0;
    a0 = GAME_EVENT_ChangeEvent(a0, v0);
loc_021587DC:
a0 = ((struct Obj17623 *)q)->f0;
    return a0;
}
