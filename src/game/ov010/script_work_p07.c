/*
 * file:     script_work_p07.c
 * unit:     yes
 * function: func_02158824, func_0215882C, func_0215886C, func_02158894, func_0215889C, func_021588A4, func_021588B0, func_021588C0
 * address:  0x02158824
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02011298  0x02011298  thumb
 *   func_02158CB4  0x02158CB4  thumb  ov010
 *   func_0201235C 0x0201235C thumb
 */
#include "../../matched/include/Obj00105.h"
#include "../../matched/include/Obj12028.h"
#include "../../matched/include/Obj09153.h"
#include "../../matched/include/Obj12029.h"
#include "../../matched/include/Obj17624.h"
#include "../../matched/include/Obj12271.h"
#include "../../matched/include/Obj17625.h"

struct ScriptVm;
struct S0201235C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_020307B0(void *p);
extern int func_02011298(struct ScriptVm *vm);
extern int func_02158CB4(int a0);
extern void func_0201235C(struct S0201235C *o, u32 *out);
void func_02158824(void *a0, unsigned a1, unsigned a2, unsigned a3);
int func_0215882C(int a0);
int func_0215886C(int a0, int a1);
int func_02158894(int a0, int a1);
void func_0215889C(void *p, u32 *out);
void func_021588A4(void *p, int a);
int func_021588B0(int a0, int a1, int a2);
int func_021588C0(int a0);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158824.c \
 *       --func func_02158824 --addr 0x02158824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02158824(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}


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
    a0 = func_02011298((struct ScriptVm *)a0);
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




int func_0215886C(int a0, int a1)
{
    int a2;
    int a3;
    int t4;

t4 = 0;
loc_02158870:
a2 = t4 << 2;
a3 = a0 + a2;
a2 = ((struct Obj12029 *)a3)->f4;
    if (a2 != 0) goto loc_02158888;
loc_0215887A:
((struct Obj12029 *)a3)->f4 = a1;
a1 = ((struct Obj09153 *)a0)->f2;
a1 = a1 + 1;
((struct Obj09153 *)a0)->f2 = a1;
a0 = t4 + 0;
    return a0;
loc_02158888:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158870;
loc_0215888E:
a0 = 3;
    return a0;}




int func_02158894(int a0, int a1)
{

a1 = a1 << 2;
a0 = a0 + a1;
a0 = ((struct Obj17624 *)a0)->f4;
    return a0;}

/*
 * extent: 8-byte tail stub; existing labelled func_021588A4 follows.
 */
void func_0215889C(void *p, u32 *out)
{
    func_0201235C(p, out);
}

/*
 * lever: Callback-field assignment before argument-field assignment hoists
 *        the callback pool load before both stores, preserving argument first.
 */
void func_021588A4(void *p, int a)
{
    void (*callback)(void *, u32 *) = func_0215889C;
    *(void (**)(void *, u32 *))((u32)p + 0x10) = callback;
    ((struct Obj12271 *)((u32)p))->f14 = a;
}




int func_021588B0(int a0, int a1, int a2)
{

a2 = a0 + 0;
a0 = a1 + 0;
a1 = *(int *)&((struct Obj00105 *)a2)->f14;
a2 = *(int *)&((struct Obj00105 *)a2)->f10;
    a0 = ((int (*)())a2)(a0, a1, a2);
loc_021588BC:
    return a0;}




int func_021588C0(int a0)
{

a0 = ((struct Obj17625 *)a0)->f10;
    if (a0 == 0) goto loc_021588CA;
loc_021588C6:
a0 = 1;
    return a0;
loc_021588CA:
a0 = 0;
    return a0;}
