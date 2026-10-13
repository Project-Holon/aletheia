/*
 * function: func_0215882C
 * address:  0x0215882C
 * packet:   pkt_0215882C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_Control  0x02011298  thumb
 *   func_02158CB4  0x02158CB4  thumb  ov010
 */
#include "../include/Obj00105.h"
#include "../include/Obj12028.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct ScriptVm;
extern int VM_Control(struct ScriptVm *vm);
extern int func_02158CB4(int a0);

int func_0215882C(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
loc_02158832:
a0 = t4 << 2;
t7 = t5 + a0;
t6 = ((struct Obj12028 *)t7)->f4;
    if (t6 == 0) goto loc_02158856;
loc_0215883C:
a0 = t6 + 0;
    a0 = VM_Control((struct ScriptVm *)a0);
loc_02158842:
    if (a0 != 0) goto loc_02158856;
loc_02158846:
a0 = 0;
((struct Obj12028 *)t7)->f4 = a0;
a0 = ((struct Obj00105 *)t5)->f2;
a0 = a0 - 1;
((struct Obj00105 *)t5)->f2 = a0;
a0 = t6 + 0;
    a0 = func_02158CB4(a0);
loc_02158856:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158832;
loc_0215885C:
a0 = ((struct Obj00105 *)t5)->f2;
    if (a0 == 0) goto loc_02158866;
loc_02158862:
a0 = 1;
    return a0;
loc_02158866:
a0 = 0;
    return a0;}
