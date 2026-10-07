/*
 * file:     eventdata_system_p25.c
 * unit:     yes
 * function: func_021636F0, func_0216372C, func_0216375C
 * address:  0x021636F0
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
 *   func_021636A8  0x021636A8  thumb  ov010
 *   func_021636C8  0x021636C8  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DD04 0x0216DD04 thumb ov010
 *   func_021AC528 0x021AC528 thumb ov021
 */
#include "../../matched/include/Obj07203.h"
#include "../../matched/include/Obj00110.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern int func_021636A8(int a0, int a1);
extern int func_021636C8();
extern u32 func_0216D57C(void *p, u32 v);
extern int func_021AC2C0();
extern int func_0216D568();
extern int func_0216D570();
extern int func_0216DD04(void *p);
extern void func_021AC528(u32 a, u32 b);
void func_021636F0(int a0, int a1);
void func_0216372C(int a0, int a1);
void func_0216375C(void *p, u8 *q);


void func_021636F0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_021636A8(a0, a1);
loc_021636FA:
    if (a0 != 1) goto loc_02163728;
loc_021636FE:
a0 = t4 + 0;
    a0 = func_021636C8(a0);
loc_02163704:
    if (a0 != 1) goto loc_02163728;
loc_02163708:
t6 = 1;
t6 = t6 << 0xe;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163714:
    if (a0 != 0) goto loc_02163728;
loc_02163718:
a1 = ((struct Obj07203 *)t4)->f14;
a0 = t5 + 0;
    a0 = func_021AC2C0(a0, a1);
loc_02163720:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_0216D568(a0, a1);
loc_02163728:
    return;}


void func_0216372C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_021636A8(a0, a1);
loc_02163736:
    if (a0 != 1) goto loc_0216375A;
loc_0216373A:
a0 = t4 + 0;
    a0 = func_021636C8(a0);
loc_02163740:
    if (a0 != 0) goto loc_02163750;
loc_02163744:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xe;
    a0 = func_0216D568(a0, a1);
loc_0216374E:
    return;
loc_02163750:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xe;
    a0 = func_0216D570(a0, a1);
loc_0216375A:
    return;}

void func_0216375C(void *p, u8 *q)
{
    if (!(((struct Obj00110 *)q)->fE & 2) && !func_0216DD04(p))
        func_021AC528((u32)p, *(u32 *)&((struct Obj00110 *)q)->f14);
}
