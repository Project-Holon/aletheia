/*
 * function: func_02158CB4
 * address:  0x02158CB4
 * packet:   pkt_02158CB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011324  0x02011324  thumb
 *   func_0215A5A4  0x0215A5A4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02011264  0x02011264  thumb
 */
#include "../include/Obj17627.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern int func_0215A5A4(int a0);
extern int func_020307B0();
extern int func_02011264();

int func_02158CB4(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_02011324((struct ScriptVm *)a0);
loc_02158CBC:
    a0 = func_0215A5A4((int)p);
loc_02158CC0:
a0 = ((struct Obj17627 *)t4)->f2C;
    a0 = func_020307B0(a0);
loc_02158CC6:
a0 = t4 + 0;
    a0 = func_02011264(a0);
loc_02158CCC:
    return a0;}
