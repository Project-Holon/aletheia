/*
 * file:     eventdata_system_p24.c
 * unit:     yes
 * function: func_0216369C, func_021636A8, func_021636C8
 * address:  0x0216369C
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
 *   func_0216DBCC  0x0216DBCC  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_021AB3D4  0x021AB3D4  thumb
 */
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj17718.h"
#include "../../matched/include/Obj07203.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216DBCC(void *a0, u32 a1, int a2);
extern void *func_0216D67C(void *a0);
extern int func_0216D98C(int a0);
extern int func_021AB3D4();
void func_0216369C(void *a0, unsigned a1, unsigned a2, unsigned a3);
int func_021636A8(int a0, int a1);
int func_021636C8(int a0, int a1, int a2);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216DBCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216369C.c \
 *       --func func_0216369C --addr 0x0216369C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216369C(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_0216DBCC(a0, 0, a2);
}


int func_021636A8(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_021636B0:
    a0 = func_0216D98C(a0);
loc_021636B4:
    if (a0 == 0) goto loc_021636C0;
loc_021636B8:
a0 = ((struct Obj17718 *)t4)->f10;
a0 = *(u8 *)&((struct Obj00113 *)a0)->f4;
    if (a0 != 0) goto loc_021636C4;
loc_021636C0:
a0 = 0;
    return a0;
loc_021636C4:
a0 = 1;
    return a0;}


int func_021636C8(int a0, int a1, int a2)
{

a2 = ((struct Obj07203 *)a0)->fE;
a1 = 0x80;
    if ((a1 & a2) != 0) goto loc_021636D6;
loc_021636D2:
a0 = 0;
    return a0;
loc_021636D6:
a1 = ((struct Obj07203 *)a0)->f18;
    if (a1 != 3) goto loc_021636EA;
loc_021636DC:
a0 = ((struct Obj07203 *)a0)->fA;
    a0 = func_021AB3D4(a0);
loc_021636E2:
    if (a0 == 0) goto loc_021636EA;
loc_021636E6:
a0 = 0;
    return a0;
loc_021636EA:
a0 = 1;
    return a0;}
