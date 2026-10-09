/*
 * file:     fldmmdl_p05.c
 * unit:     yes
 * function: func_0216D438, func_0216D454, func_0216D480, func_0216D4B4, func_0216D4D4, func_0216D4DC, func_0216D4E4, func_0216D4F0, func_0216D4F4, func_0216D4F8, func_0216D4FC, func_0216D508, func_0216D514, func_0216D518, func_0216D51C, func_0216D520, func_0216D524, func_0216D528, func_0216D52C, func_0216D530, func_0216D534, func_0216D538, func_0216D548, func_0216D550, func_0216D55C, func_0216D564, func_0216D568, func_0216D570, func_0216D57C, func_0216D584, func_0216D588, func_0216D58C, func_0216D590, func_0216D594, func_0216D598, func_0216D59C, func_0216D5A0, func_0216D5A4, func_0216D5A8, func_0216D5AC, func_0216D5B0, func_0216D5B4, func_0216D5B8, func_0216D5BC, func_0216D5D4, func_0216D5D8, func_0216D5E0, func_0216D5F8, func_0216D5FC, func_0216D600, func_0216D608
 * address:  0x0216D438
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
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 */
#include "../../matched/include/Obj17773.h"
#include "../../matched/include/Obj12057.h"
#include "../../matched/include/Obj17774.h"
#include "../../matched/include/Obj17775.h"
#include "../../matched/include/Obj17776.h"
#include "../../matched/include/Obj17777.h"
#include "../../matched/include/Obj17778.h"
#include "../../matched/include/Obj17779.h"
#include "../../matched/include/Obj17780.h"
#include "../../matched/include/Obj17781.h"
#include "../../matched/include/Obj17782.h"
#include "../../matched/include/Obj19121.h"
#include "../../matched/include/Obj17783.h"
#include "../../matched/include/Obj17784.h"
#include "../../matched/include/Obj17785.h"
#include "../../matched/include/Obj17786.h"
#include "../../matched/include/Obj19122.h"
#include "../../matched/include/Obj17788.h"
#include "../../matched/include/Obj17789.h"
#include "../../matched/include/Obj17790.h"
#include "../../matched/include/Obj19125.h"
#include "../../matched/include/Obj17791.h"
#include "../../matched/include/Obj17792.h"
#include "../../matched/include/Obj17793.h"
#include "../../matched/include/Obj17794.h"
#include "../../matched/include/Obj17795.h"
#include "../../matched/include/Obj17796.h"
#include "../../matched/include/Obj17797.h"
#include "../../matched/include/Obj17798.h"
#include "../../matched/include/Obj17799.h"
#include "../../matched/include/Obj17800.h"
#include "../../matched/include/Obj17801.h"
#include "../../matched/include/Obj17802.h"
#include "../../matched/include/Obj17803.h"
#include "../../matched/include/Obj17804.h"
#include "../../matched/include/Obj17805.h"
#include "../../matched/include/Obj17806.h"
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj17807.h"
#include "../../matched/include/Obj19126.h"
#include "../../matched/include/Obj17808.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0216D7C0();
extern void *func_0216D7C8(void *p, u16 v);
void func_0216D438(char *a0, int a1);
int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
int func_0216D480(char *p);
void *func_0216D4B4(char *p);
int func_0216D4D4(int a0, int a1);
int func_0216D4DC(int a0, int a1, int a2);
u32 *func_0216D4E4(u32 *p, u32 v);
u16 func_0216D4F0(void *p);
u16 func_0216D4F4(void *p);
u32 func_0216D4F8(u8 *p);
int func_0216D4FC(int a0);
int func_0216D508(int a0);
u32 func_0216D514(void *p);
u32 func_0216D518(u8 *p);
void func_0216D51C(u8 *p, u32 v);
u32 func_0216D520(void *p);
void func_0216D524(void *p, void *v);
u32 func_0216D528(u8 *p);
u32 func_0216D52C(void *p);
void *func_0216D530(void *p);
u32 func_0216D534(void *p);
u32 func_0216D538(u8 *p);
unsigned int *func_0216D548(unsigned int *, unsigned int);
u32 *func_0216D550(u32 *p, u32 v);
int func_0216D55C(int a0, int a1);
u32 func_0216D564(void *p);
void *func_0216D568(void *p, u32 v);
char *func_0216D570(char *p, u32 v);
u32 func_0216D57C(void *p, u32 v);
int func_0216D584(void *, u16);
u16 func_0216D588(void *p);
void func_0216D58C(void *p, u16 v);
u16 func_0216D590(void *p);
void func_0216D594(void *p, u32 v);
u16 func_0216D598(void *p);
void func_0216D59C(void *p, u16 v);
u16 func_0216D5A0(void *p);
int func_0216D5A4(void *, u16);
u16 func_0216D5A8(u8 *p);
int func_0216D5AC(void *, u16);
u16 func_0216D5B0(u8 *p);
int func_0216D5B4(void *, u16);
u32 func_0216D5B8(void *p);
int func_0216D5BC(void *p);
int func_0216D5D4(void *p);
int func_0216D5D8(int a0, int a1);
void func_0216D5E0(int a0, int a1);
u16 func_0216D5F8(void *p);
u16 func_0216D5FC(void *p);
int func_0216D600(int, int);
u16 func_0216D608(void *p);






void func_0216D438(char *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)func_0216D7C0(a0, a1);
loc_0216D440:
a0 = (char *)(t4 + 0);
a1 = 0;
    a0 = (char *)func_0216D7C8(a0, a1);
loc_0216D448:
a1 = 1;
a0 = (char *)(t4 + 0);
a1 = a1 << 0xa;
    a0 = (char *)func_0216D570(a0, a1);
loc_0216D452:
    return;}






int func_0216D454(int a0, u32 a1, u32 a2, u32 a3)
{
    int t4;
    int t5;

t4 = 2;
t4 = t4 << 8;
a1 = t4 + 0;
t5 = a0 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D462:
    if (a0 != 0) goto loc_0216D46A;
loc_0216D466:
a0 = 1;
    return a0;
loc_0216D46A:
a0 = t5 + 0;
a1 = t4 << 1;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D472:
    if (a0 == 0) goto loc_0216D47A;
loc_0216D476:
a0 = 1;
    return a0;
loc_0216D47A:
a0 = 0;
    return a0;}





int func_0216D480(char *p)
{
    if (func_0216D57C(p, 0x200) == 0) return 1;
    if (func_0216D57C(p, 0x400) == 0) return 0;
    func_0216D570(p, 0x600);
    return 1;
}





void *func_0216D4B4(char *p)
{
    func_0216D570(p, 0x600);
    func_0216D7C0(p, 0xff);
    return func_0216D7C8(p, 0);
}








int func_0216D4D4(int a0, int a1)
{

a0 = ((struct Obj17773 *)((char *)a0))->f0;
a0 = a0 & a1;
    return a0;}








int func_0216D4DC(int a0, int a1, int a2)
{

a2 = ((struct Obj12057 *)((char *)a0))->f0;
a1 = a1 | a2;
((struct Obj12057 *)((char *)a0))->f0 = a1;
    return a0;}





u32 *func_0216D4E4(u32 *p, u32 v)
{
    *p &= ~v;
    return p;
}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D4F0.c \
 *       --func func_0216D4F0 --addr 0x0216D4F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D4F0(void *p) { return ((struct Obj17774 *)p)->f4; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D4F4.c \
 *       --func func_0216D4F4 --addr 0x0216D4F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D4F4(void *p) { return ((struct Obj17775 *)p)->fC; }




/*
 * Getter: halfword at +0xa.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D4F8(u8 *p)
{
return ((struct Obj17776 *)p)->fA;
}







int func_0216D4FC(int a0)
{
    int a1;
a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 + 1;
((struct Obj17777 *)a0)->f6 = a1;
    return a0;}







int func_0216D508(int a0)
{
    int a1;

a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 - 1;
((struct Obj17778 *)a0)->f6 = a1;
    return a0;}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D514.c \
 *       --func func_0216D514 --addr 0x0216D514 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D514(void *p) { return ((struct Obj17779 *)p)->f20; }






/*
 * Reads the word field at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D518(u8 *p)
{
    return ((struct Obj17780 *)p)->f10;
}






/*
 * Stores the word field at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D51C(u8 *p, u32 v)
{
    ((struct Obj17781 *)p)->f24 = v;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D520.c \
 *       --func func_0216D520 --addr 0x0216D520 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D520(void *p) { return ((struct Obj17782 *)p)->f24; }




/*
 * Unlabelled leaf: str r1, [r0, #0x28]; bx lr.
 */
void func_0216D524(void *p, void *v)
{
    ((struct Obj19121 *)p)->f28 = v;
}



/*
 * Getter: word at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D528(u8 *p)
{
return ((struct Obj17783 *)p)->f28;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D52C.c \
 *       --func func_0216D52C --addr 0x0216D52C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D52C(void *p) { return ((struct Obj17784 *)p)->f34; }



/*
 * Getter: word at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void *func_0216D530(void *p)
{
    return ((struct Obj17785 *)p)->f38;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D534.c \
 *       --func func_0216D534 --addr 0x0216D534 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D534(void *p) { return ((struct Obj17786 *)p)->f3C; }




/*
 * Unlabelled leaf (no lr push): returns the halfword at the pointer held at +0x40, or 0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D538(u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj19122 *)p)->f40;
    if (q != 0)
        return *q;
    return 0;
}






unsigned int *func_0216D548(unsigned int *p, unsigned int v){
    *p |= v;
    return p;
}




u32 *func_0216D550(u32 *p, u32 v)
{
    *p &= ~v;
    return p;
}






int func_0216D55C(int a0, int a1)
{

a0 = ((struct Obj17788 *)((char *)a0))->f0;
a0 = a0 & a1;
    return a0;}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D564.c \
 *       --func func_0216D564 --addr 0x0216D564 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D564(void *p) { return ((struct Obj17789 *)p)->f4; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Read-modify-write OR into a word field.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D568.c \
 *       --func func_0216D568 --addr 0x0216D568 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D568(void *p, u32 v) { ((struct Obj17790 *)p)->f4 |= v;  return p; }




char *func_0216D570(char *p, u32 v)
{
    ((struct Obj19125 *)p)->f4 &= ~v;
    return p;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field mask test: load and return `field & mask`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D57C.c \
 *       --func func_0216D57C --addr 0x0216D57C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D57C(void *p, u32 v) { return ((struct Obj17791 *)p)->f4 & v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D584.c \
 *       --func func_0216D584 --addr 0x0216D584 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D584(void *p, u16 v) { ((struct Obj17792 *)p)->f8 = v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D588.c \
 *       --func func_0216D588 --addr 0x0216D588 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D588(void *p) { return ((struct Obj17793 *)p)->f8; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D58C.c \
 *       --func func_0216D58C --addr 0x0216D58C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D58C(void *p, u16 v) { ((struct Obj17794 *)p)->fA = v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D590.c \
 *       --func func_0216D590 --addr 0x0216D590 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D590(void *p) { return ((struct Obj17795 *)p)->fA; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D594.c \
 *       --func func_0216D594 --addr 0x0216D594 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D594(void *p, u32 v) { ((struct Obj17796 *)p)->fC = v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D598.c \
 *       --func func_0216D598 --addr 0x0216D598 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D598(void *p) { return ((struct Obj17797 *)p)->fC; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D59C.c \
 *       --func func_0216D59C --addr 0x0216D59C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D59C(void *p, u16 v) { ((struct Obj17798 *)p)->fE = v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5A0.c \
 *       --func func_0216D5A0 --addr 0x0216D5A0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D5A0(void *p) { return ((struct Obj17799 *)p)->fE; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5A4.c \
 *       --func func_0216D5A4 --addr 0x0216D5A4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5A4(void *p, u16 v) { ((struct Obj17800 *)p)->f10 = v; }



/*
 * Getter: halfword at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D5A8(u8 *p)
{
return ((struct Obj17801 *)p)->f10;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5AC.c \
 *       --func func_0216D5AC --addr 0x0216D5AC --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5AC(void *p, u16 v) { ((struct Obj17802 *)p)->f12 = v; }





/*
 * Reads the halfword field at +0x12.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D5B0(u8 *p)
{
    return ((struct Obj17803 *)p)->f12;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5B4.c \
 *       --func func_0216D5B4 --addr 0x0216D5B4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5B4(void *p, u16 v) { ((struct Obj17804 *)p)->f14 = v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5B8.c \
 *       --func func_0216D5B8 --addr 0x0216D5B8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D5B8(void *p) { return ((struct Obj17805 *)p)->f14; }



int func_0216D5BC(void *p)
{
    return func_0216D5B8(p) == 0xFFFF;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5D4.c \
 *       --func func_0216D5D4 --addr 0x0216D5D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5D4(void *p) { return ((struct Obj17806 *)p)->f16; }






int func_0216D5D8(int a0, int a1)
{
    int a2;

a2 = ((struct Obj00113 *)a0)->f18;
((struct Obj00113 *)a0)->f1C = a2;
((struct Obj00113 *)a0)->f18 = a1;
    return a0;}




void func_0216D5E0(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = 8;
t5 = a0 + 0;
    a0 = func_0216D55C(a0, a1);
loc_0216D5EC:
    if (a0 != 0) goto loc_0216D5F6;
loc_0216D5F0:
a0 = ((struct Obj00113 *)t5)->f18;
((struct Obj00113 *)t5)->f1C = a0;
((struct Obj00113 *)t5)->f18 = t4;
loc_0216D5F6:
    return;}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5F8.c \
 *       --func func_0216D5F8 --addr 0x0216D5F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D5F8(void *p) { return ((struct Obj17807 *)p)->f18; }




/*
 * Unlabelled leaf (halfword getter at +0x1c), filed as the only blocker of
 * func_021BBDD4 (ov021).
 */
u16 func_0216D5FC(void *p) { return ((struct Obj19126 *)p)->f1C; }






int func_0216D600(int a0, int a1){
    int a2;

a2 = ((struct Obj00113 *)a0)->f1A;
((struct Obj00113 *)a0)->f1E = a2;
((struct Obj00113 *)a0)->f1A = a1;
    return a0;}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D608.c \
 *       --func func_0216D608 --addr 0x0216D608 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D608(void *p) { return ((struct Obj17808 *)p)->f1A; }
