/*
 * file:     eventdata_system_p11.c
 * unit:     yes
 * function: func_02163418, func_02163464, func_021634D8, func_021634FC, func_0216352C, func_0216355C, func_02163580, func_02163618, func_02163650, func_0216369C, func_021636A8, func_021636C8
 * address:  0x02163418
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
 *   func_0216DC00 0x0216DC00 thumb ov010
 *   func_021AB41C 0x021AB41C thumb ov021
 *   func_0216D900 0x0216D900 thumb ov010
 *   d_021714D0 0x021714D0 data ov010 a4
 *   func_021AB4EC  0x021AB4EC  thumb
 *   func_021AB4F8  0x021AB4F8  thumb
 *   func_021AB434  0x021AB434  thumb
 *   func_021AB428  0x021AB428  thumb
 *   func_021AB250  0x021AB250  thumb
 *   func_021AB264  0x021AB264  thumb
 *   func_021AB270  0x021AB270  thumb
 *   func_021AC760  0x021AC760  thumb
 *   func_0216D608 0x0216D608 thumb ov010
 *   func_021AB3D4  0x021AB3D4  thumb
 *   func_021AB3E0  0x021AB3E0  thumb
 *   func_021AB334  0x021AB334  thumb
 *   func_021AB328  0x021AB328  thumb
 *   func_021BBDD4  0x021BBDD4  thumb
 *   func_021AB304  0x021AB304  thumb
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021C4BE0  0x021C4BE0  thumb
 *   func_0216DBCC  0x0216DBCC  thumb  ov010
 *   func_021AB364  0x021AB364  thumb
 *   func_021C4A10  0x021C4A10  thumb
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 */
#include "../../matched/include/Obj00110.h"
#include "../../matched/include/Obj00110.h"
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj17718.h"
#include "../../matched/include/Obj07203.h"

typedef struct { int x, y, z; } V;

typedef struct { char pad[10]; unsigned short f; } S;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216DC00(void *a0);
extern int func_021AB41C(unsigned short);
extern void func_0216D900(int, const V *);
extern int func_021AB4EC();
extern int func_021AB4F8();
extern int func_021AB434();
extern int func_021AB428();
extern int func_021AB250();
extern int func_021AB264();
extern int func_021AB270();
extern int func_021AC760();
extern u16 func_0216D608(void *p);
extern int func_021AB3D4();
extern int func_021AB3E0();
extern int func_021AB334();
extern int func_021AB328();
extern int func_021BBDD4();
extern int func_021AB304();
extern int func_0216DBE8(void *a0);
extern int func_021C4BE0();
extern int func_0216DBCC();
extern int func_021AB364();
extern int func_021C4A10();
extern void *func_0216D67C(void *a0);
extern int func_0216D98C(int a0);
/* * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path. */ void func_02163418(int a, S *s);
int func_02163464(int a0, int a1);
void func_021634D8(int a0, int a1, int a2, int a3);
void func_021634FC(void *p, u8 *q);
void func_0216352C(void *p, u8 *q);
void func_0216355C(int a0, int a1, int a2, int a3);
void func_02163580(int a0, int a1, int a2);
int func_02163618(int a0, int a1);
int func_02163650(int a0, int a1);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Tail call through a pool word and `bx r3`: a two-instruction * thunk into func_0216DBCC, the shape of the arm9 copy. * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0216369C.c \ * --func func_0216369C --addr 0x0216369C --region ov010 --cc dsi/1.1p1 --thumb */ void func_0216369C(void *a0, unsigned a1, unsigned a2, unsigned a3);
int func_021636A8(int a0, int a1);
int func_021636C8(int a0, int a1, int a2);
extern V d_021714D0;






static inline void vzero(V *p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}






/*
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 */
void func_02163418(int a, S *s)
{
    V v;
    V *pz;
    if (func_0216DC00((void *)a) == 0 && func_021AB41C(s->f) != 0) {
        v = d_021714D0;
        func_0216D900(a, &v);
        return;
    }
    {
        unsigned char buf[12];
        V *z = (V *)buf;
        vzero(z);
        func_0216D900(a, z);
    }
}







int func_02163464(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_021AB4EC(a0);
loc_02163470:
    if (a0 == 0) goto loc_02163478;
loc_02163474:
t4 = 6;
    goto loc_021634D4;
loc_02163478:
a0 = t5 + 0;
    a0 = func_021AB4F8(a0);
loc_0216347E:
    if (a0 == 0) goto loc_02163486;
loc_02163482:
t4 = 7;
    goto loc_021634D4;
loc_02163486:
a0 = t5 + 0;
    a0 = func_021AB434(a0);
loc_0216348C:
    if (a0 == 0) goto loc_0216349A;
loc_02163490:
t4 = 1;
    if (t6 != 3) goto loc_021634D4;
loc_02163496:
t4 = 5;
    goto loc_021634D4;
loc_0216349A:
a0 = t5 + 0;
    a0 = func_021AB428(a0);
loc_021634A0:
    if (a0 == 0) goto loc_021634AC;
loc_021634A4:
    if (t6 != 3) goto loc_021634D4;
loc_021634A8:
t4 = 4;
    goto loc_021634D4;
loc_021634AC:
a0 = t5 + 0;
    a0 = func_021AB250(a0);
loc_021634B2:
    if (a0 == 0) goto loc_021634BA;
loc_021634B6:
t4 = 1;
    goto loc_021634D4;
loc_021634BA:
a0 = t5 + 0;
    a0 = func_021AB264(a0);
loc_021634C0:
    if (a0 == 0) goto loc_021634C8;
loc_021634C4:
t4 = 2;
    goto loc_021634D4;
loc_021634C8:
a0 = t5 + 0;
    a0 = func_021AB270(a0);
loc_021634CE:
    if (a0 == 0) goto loc_021634D4;
loc_021634D2:
t4 = 3;
loc_021634D4:
a0 = t4 + 0;
    return a0;}







void func_021634D8(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj00110 *)t4)->fE;
t5 = a0 + 0;
a0 = 0x20;
    if ((a0 & a1) == 0) goto loc_021634FA;
loc_021634E6:
a0 = ((struct Obj00110 *)t4)->fA;
a1 = ((struct Obj00110 *)t4)->f18;
    a0 = func_02163464(a0, a1);
loc_021634EE:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
a2 = 0;
    a0 = func_021AC760(a0, a1, a2, a3);
loc_021634FA:
    return;}





/*
 * trailing: two-byte zero alignment at 0x0216352A before func_0216352C.
 */
void func_021634FC(void *p, u8 *q)
{
    int flag;
    int kind;
    if (((struct Obj00110 *)q)->fE & 0x20) {
        flag = func_0216D608(p);
        kind = func_02163464(((struct Obj00110 *)q)->fA, q[24]);
        if (flag != 0)
            func_021AC760(*(u32 *)&((struct Obj00110 *)q)->f14, (u32)p, 1, kind);
    }
}




/*
 * trailing: two-byte zero alignment at 0x0216355A before func_0216355C.
 */
void func_0216352C(void *p, u8 *q)
{
    int flag;
    int kind;
    if (((struct Obj00110 *)q)->fE & 0x20) {
        flag = func_0216D608(p);
        kind = func_02163464(((struct Obj00110 *)q)->fA, q[24]);
        if (flag == 0)
            func_021AC760(*(u32 *)&((struct Obj00110 *)q)->f14, (u32)p, 1, kind);
    }
}




void func_0216355C(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj00110 *)t4)->fE;
t5 = a0 + 0;
a0 = 0x20;
    if ((a0 & a1) == 0) goto loc_0216357E;
loc_0216356A:
a0 = ((struct Obj00110 *)t4)->fA;
a1 = ((struct Obj00110 *)t4)->f18;
    a0 = func_02163464(a0, a1);
loc_02163572:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
a2 = 1;
    a0 = func_021AC760(a0, a1, a2, a3);
loc_0216357E:
    return;}




void func_02163580(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a1 + 0;
a1 = ((struct Obj00110 *)t5)->fC;
t6 = a0 + 0;
a0 = 8;
    if ((a0 & a1) == 0) goto loc_02163616;
loc_0216358E:
a0 = ((struct Obj00110 *)t5)->f8;
t4 = 5;
    a0 = func_021AB3D4(a0);
loc_02163596:
    if (a0 == 0) goto loc_021635AE;
loc_0216359A:
a0 = ((struct Obj00110 *)t5)->f18;
    if (a0 != 3) goto loc_02163608;
loc_021635A0:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 2;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_021635AA:
t4 = 3;
    goto loc_02163608;
loc_021635AE:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB3E0(a0);
loc_021635B4:
    if (a0 == 0) goto loc_021635CE;
loc_021635B8:
a0 = ((struct Obj00110 *)t5)->f18;
    if (a0 == 0) goto loc_021635C2;
loc_021635BE:
    if (a0 != 3) goto loc_02163608;
loc_021635C2:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 2;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_021635CC:
    goto loc_021635AA;
loc_021635CE:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB334(a0);
loc_021635D4:
    if (a0 == 1) goto loc_021635E2;
loc_021635D8:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB328(a0);
loc_021635DE:
    if (a0 != 1) goto loc_021635EE;
loc_021635E2:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 2;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_021635EC:
    goto loc_021635AA;
loc_021635EE:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB41C(a0);
loc_021635F4:
    if (a0 != 1) goto loc_021635FC;
loc_021635F8:
t4 = 4;
    goto loc_02163608;
loc_021635FC:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 0;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_02163606:
t4 = 1;
loc_02163608:
    if (t4 == 5) goto loc_02163616;
loc_0216360C:
a1 = ((struct Obj00110 *)t5)->f14;
a0 = t6 + 0;
a2 = t4 + 0;
    a0 = func_021BBDD4(a0, a1, a2);
loc_02163616:
    return;}




int func_02163618(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB304(a0);
loc_02163624:
    if (a0 != 1) goto loc_02163644;
loc_02163628:
a0 = t5 + 0;
    a0 = func_0216DBE8((void *)a0);
loc_0216362E:
    if (a0 != 0) goto loc_0216364C;
loc_02163632:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = func_021C4BE0(a0, a1);
loc_0216363A:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216DBCC(a0, a1);
loc_02163642:
    return a0;
loc_02163644:
a0 = t5 + 0;
a1 = 0;
    a0 = func_0216DBCC(a0, a1);
loc_0216364C:
    return a0;}




int func_02163650(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB304(a0);
loc_0216365C:
    if (a0 != 1) goto loc_0216367C;
loc_02163660:
a0 = t5 + 0;
    a0 = func_0216DBE8((void *)a0);
loc_02163666:
    if (a0 != 0) goto loc_02163698;
loc_0216366A:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = func_021C4BE0(a0, a1);
loc_02163672:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216DBCC(a0, a1);
loc_0216367A:
    return a0;
loc_0216367C:
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB364(a0);
loc_02163682:
    if (a0 != 1) goto loc_02163690;
loc_02163686:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = func_021C4A10(a0, a1);
loc_0216368E:
    return a0;
loc_02163690:
a0 = t5 + 0;
a1 = 0;
    a0 = func_0216DBCC(a0, a1);
loc_02163698:
    return a0;}



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
