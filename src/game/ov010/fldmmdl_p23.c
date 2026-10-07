/*
 * file:     fldmmdl_p23.c
 * unit:     yes
 * function: func_0216D674, func_0216D678, func_0216D67C, func_0216D684, func_0216D69C, func_0216D6A0, func_0216D6B8, func_0216D6BC, func_0216D6D4
 * address:  0x0216D674
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
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj17813.h"
#include "../../matched/include/Obj19127.h"
#include "../../matched/include/Obj00113.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

extern int func_02082BCC();
void func_0216D674(void *p, u16 v);
u16 func_0216D678(void *p);
void *func_0216D67C(void *a0);
void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
void *func_0216D69C(void *p);
void *func_0216D6A0(int a0, int a1);
void *func_0216D6B8(void *p);
void *func_0216D6BC(int a0, int a1, int a2);
void *func_0216D6D4(void *p);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D674.c \
 *       --func func_0216D674 --addr 0x0216D674 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D674(void *p, u16 v) { ((struct Obj17813 *)p)->f2A = v; }


/*
 * Unlabelled leaf, blocker of ten ov021 callers: reads the halfword at +0x2A.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D678(void *p)
{
    return ((struct Obj19127 *)p)->f2A;
}




void *func_0216D67C(void *a0)
{
    return ((struct Obj00113 *)a0)->f88;
}


void *func_0216D684(int a0, int a1, u32 a2, u32 a3)
{
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D69C((void *)a0);
loc_0216D68C:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D696:
    return t4;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D69C.c \
 *       --func func_0216D69C --addr 0x0216D69C --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D69C(void *p) { return (char *)p + 148; }


void *func_0216D6A0(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D6B8((void *)a0);
loc_0216D6A8:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6B2:
    return t4;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D6B8.c \
 *       --func func_0216D6B8 --addr 0x0216D6B8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D6B8(void *p) { return (char *)p + 164; }


void *func_0216D6BC(int a0, int a1, int a2)
{
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D6D4((void *)a0);
loc_0216D6C4:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6CE:
    return t4;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D6D4.c \
 *       --func func_0216D6D4 --addr 0x0216D6D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D6D4(void *p) { return (char *)p + 180; }
