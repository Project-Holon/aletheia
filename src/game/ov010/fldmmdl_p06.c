/*
 * file:     fldmmdl_p06.c
 * unit:     yes
 * function: func_0216D60C, func_0216D620, func_0216D63C, func_0216D65C, func_0216D660, func_0216D668, func_0216D66C, func_0216D674, func_0216D678, func_0216D67C, func_0216D684, func_0216D69C, func_0216D6A0, func_0216D6B8, func_0216D6BC, func_0216D6D4, func_0216D6D8, func_0216D6F0, func_0216D6F4, func_0216D708, func_0216D71C, func_0216D730, func_0216D744, func_0216D758, func_0216D76C, func_0216D780, func_0216D794, func_0216D7A8, func_0216D7C0, func_0216D7C4, func_0216D7C8, func_0216D7CC, func_0216D7D4, func_0216D7D8, func_0216D7DC, func_0216D7E0, func_0216D7E4, func_0216D7E8, func_0216D7F0, func_0216D7F4, func_0216D7F8, func_0216D800, func_0216D804, func_0216D80C, func_0216D810, func_0216D818, func_0216D81C, func_0216D824, func_0216D828, func_0216D83C, func_0216D844, func_0216D848, func_0216D854, func_0216D85C, func_0216D860, func_0216D86C, func_0216D874, func_0216D87C, func_0216D888, func_0216D88C, func_0216D89C, func_0216D8AC, func_0216D8B0, func_0216D8C0, func_0216D8D0, func_0216D8E0, func_0216D8F0, func_0216D900, func_0216D910, func_0216D91C, func_0216D924, func_0216D92C, func_0216D948, func_0216D95C, func_0216D974, func_0216D98C
 * address:  0x0216D60C
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
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216D4DC 0x0216D4DC thumb ov010
 *   func_0216D4E4 0x0216D4E4 thumb ov010
 */
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj17809.h"
#include "../../matched/include/Obj17810.h"
#include "../../matched/include/Obj17811.h"
#include "../../matched/include/Obj17812.h"
#include "../../matched/include/Obj17813.h"
#include "../../matched/include/Obj19127.h"
#include "../../matched/include/Obj17814.h"
#include "../../matched/include/Obj17816.h"
#include "../../matched/include/Obj12058.h"
#include "../../matched/include/Obj19128.h"
#include "../../matched/include/Obj17824.h"
#include "../../matched/include/Obj17825.h"
#include "../../matched/include/Obj17826.h"
#include "../../matched/include/Obj17827.h"
#include "../../matched/include/Obj17828.h"
#include "../../matched/include/Obj17829.h"
#include "../../matched/include/Obj17830.h"
#include "../../matched/include/Obj17831.h"
#include "../../matched/include/Obj17832.h"
#include "../../matched/include/Obj17833.h"
#include "../../matched/include/Obj17834.h"
#include "../../matched/include/Obj17835.h"
#include "../../matched/include/Obj17836.h"
#include "../../matched/include/Obj17837.h"
#include "../../matched/include/Obj17838.h"
#include "../../matched/include/Obj17839.h"
#include "../../matched/include/Obj17840.h"
#include "../../matched/include/Obj17841.h"
#include "../../matched/include/Obj17842.h"
#include "../../matched/include/Obj17843.h"
#include "../../matched/include/Obj17844.h"
#include "../../matched/include/Obj19129.h"
#include "../../matched/include/Obj17845.h"
#include "../../matched/include/Obj17846.h"
#include "../../matched/include/Obj19130.h"
#include "../../matched/include/Obj17847.h"
#include "../../matched/include/Obj17848.h"
#include "../../matched/include/Obj19131.h"
#include "../../matched/include/Obj17849.h"
#include "../../matched/include/Obj17850.h"
#include "../../matched/include/Obj17851.h"
#include "../../matched/include/Obj09334.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed short   s16_0216D6F0;

typedef int (*Callback)(void *, unsigned int);

typedef signed short   s16_0216D7C0;

typedef signed short   s16_0216D7C4;

typedef signed short   s16_0216D7C8;

typedef signed short   s16_0216D7D4;

typedef signed short   s16_0216D7D8;

typedef signed short   s16_0216D7DC;

typedef signed short   s16_0216D7E0;

typedef signed short   s16_0216D7E4;

typedef signed short   s16_0216D7E8;

typedef signed short   s16_0216D7F0;

typedef signed short   s16_0216D7F4;

typedef signed short   s16_0216D7F8;

typedef signed short   s16_0216D800;

typedef signed short   s16_0216D804;

typedef signed short   s16_0216D80C;

typedef signed short   s16_0216D810;

typedef signed short   s16_0216D818;

typedef signed short   s16_0216D81C;

typedef signed short   s16_0216D824;

typedef short s16_0216D828;

typedef struct { s16_0216D828 x, y, z; } Vec3s;

typedef signed short   s16_0216D83C;

typedef int s32_0216D60C;

typedef s32_0216D60C fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Actor {
    u8 pad00[0x44];
    VecFx32 pos;        /* 0x44 */
} Actor;

typedef struct { u32 a, b, c; } Triple;

typedef struct S12 { u32 a, b, c; } S12;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Rec12;

typedef signed char    s8;

typedef signed int     s32_0216D900;

extern int func_0216D5E0();
extern int func_0216D600(int, int);
extern int func_02082BCC(void *, int, int);
extern u32 func_0216D520(void *p);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216D4DC(int a0, int a1, int a2);
extern u32 *func_0216D4E4(u32 *p, u32 v);
int func_0216D60C(int a0, int a1);
int func_0216D620(int a0, int a1, int a2);
int func_0216D63C(char *a0, int a1);
void func_0216D65C(void *p, u16 v);
int func_0216D660(void *p);
void func_0216D668(void *p, u16 v);
int func_0216D66C(void *p);
int func_0216D674(void *, u16);
u16 func_0216D678(void *p);
void *func_0216D67C(void *a0);
void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
void *func_0216D69C(void *p);
void *func_0216D6A0(int a0, int a1);
void *func_0216D6B8(void *p);
void *func_0216D6BC(int a0, int a1, int a2);
void *func_0216D6D4(void *p);
void *func_0216D6D8(int a0, int a1);
void *func_0216D6F0(void *p);
void func_0216D6F4(void *a0);
void func_0216D708(void *a0);
int func_0216D71C(void *);
void func_0216D730(void *a0);
int func_0216D744(int a0, int a1);
void func_0216D758(void *a0);
int func_0216D76C(void *);
void func_0216D780(void *a0);
void func_0216D794(void *a0);
int func_0216D7A8(void *p, unsigned int v);
void func_0216D7C0(void *p, u16 v);
u16 func_0216D7C4(u8 *p);
void *func_0216D7C8(void *p, u16 v);
void func_0216D7CC(u8 *p);
u16 func_0216D7D4(u8 *p);
void func_0216D7D8(void *p, u32 v);
u32 func_0216D7DC(void *p);
void func_0216D7E0(void *p, u32 v);
u32 func_0216D7E4(void *p);
int func_0216D7E8(void *p);
void func_0216D7F0(void *, short);
void func_0216D7F4(void *, short);
int func_0216D7F8(void *p);
void func_0216D800(void *, short);
int func_0216D804(void *p);
void func_0216D80C(void *, s16);
int func_0216D810(void *p);
void func_0216D818(void *, s16);
int func_0216D81C(void *p);
void func_0216D824(void *, s16);
void func_0216D828(u8 *p, Vec3s *out);
int func_0216D83C(void *p);
void func_0216D844(void *, short);
void func_0216D848(char *p, short v);
int func_0216D854(void *p);
void func_0216D85C(void *p, int v);
void func_0216D860(char *p, short v);
int func_0216D86C(void *p);
void func_0216D874(int a0, int a1);
void func_0216D87C(char *p, short v);
void *func_0216D888(void *p);
void func_0216D88C(const struct Actor *, struct VecFx32 *);
void func_0216D89C(void *p, const Triple *q);
u32 func_0216D8AC(void *p);
void func_0216D8B0(u8 *p, u8 *q);
void func_0216D8C0(u8 *p, const Vec *v);
void func_0216D8D0(u8 *p, u8 *q);
void func_0216D8E0(u8 *p, Rec12 *src);
void func_0216D8F0(u8 *p, u8 *q);
void func_0216D900(void *p, const Triple *q);
int func_0216D910(int a0);
u8 func_0216D91C(int a0);
u8 func_0216D924(int a0);
void func_0216D92C(u8 *p, s32_0216D900 *q);
int func_0216D948(int a0);
void func_0216D95C(unsigned int *p, unsigned int v, int a2);
void func_0216D974(unsigned int *p, unsigned int v, int a2);
int func_0216D98C(int a0);







int func_0216D60C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D5E0(a0, a1);
loc_0216D616:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216D600(a0, a1);
loc_0216D61E:
    return a0;}









int func_0216D620(int a0, int a1, int a2)
{

    if (a2 == 0) goto loc_0216D62E;
loc_0216D624:
    if (a2 == 1) goto loc_0216D632;
loc_0216D628:
    if (a2 == 2) goto loc_0216D636;
loc_0216D62C:
    return a0;
loc_0216D62E:
((struct Obj00113 *)a0)->f20 = a1;
    return a0;
loc_0216D632:
((struct Obj00113 *)a0)->f22 = a1;
    return a0;
loc_0216D636:
((struct Obj00113 *)a0)->f24 = a1;
    return a0;}







/*
 * Recursive MATCH unblocker: dependency of func_0217C294 (ov018 tail-call
 * thunk), which unblocks func_0216AC90 and func_0216ACCC.
 */
int func_0216D63C(char *a0, int a1)
{
    switch (a1) {
    case 0:
        return ((struct Obj00113 *)a0)->f20;
    case 1:
        return ((struct Obj00113 *)a0)->f22;
    case 2:
        return ((struct Obj00113 *)a0)->f24;
    default:
        return 0;
    }
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
 *   python tools/match.py one --src src/matched/func_0216D65C.c \
 *       --func func_0216D65C --addr 0x0216D65C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D65C(void *p, u16 v) { ((struct Obj17809 *)p)->f2C = v; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D660.c \
 *       --func func_0216D660 --addr 0x0216D660 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D660(void *p) { return ((struct Obj17810 *)p)->f2C; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D668.c \
 *       --func func_0216D668 --addr 0x0216D668 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D668(void *p, u16 v) { ((struct Obj17811 *)p)->f2E = v; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D66C.c \
 *       --func func_0216D66C --addr 0x0216D66C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D66C(void *p) { return ((struct Obj17812 *)p)->f2E; }






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
int func_0216D674(void *p, u16 v) { ((struct Obj17813 *)p)->f2A = v; }






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





void *func_0216D6D8(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D6F0((void *)a0);
loc_0216D6E0:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6EA:
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
 *   python tools/match.py one --src src/matched/func_0216D6F0.c \
 *       --func func_0216D6F0 --addr 0x0216D6F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D6F0(void *p) { return (char *)p + 196; }





/*
 * Indirect call through the entry the object's vtable pointer
 * holds, skipped when the slot is empty.
 */
void func_0216D6F4(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj17814 *)a0)->f8C + 0x4);

    if (fn != 0)
        fn(a0);
}





void func_0216D708(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj17816 *)a0)->f8C + 0x8);

    if (fn != 0)
        fn(a0);
}





int func_0216D71C(void *a0){
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f8C + 0xC);

    if (fn != 0)
        fn(a0);
}





void func_0216D730(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj12058 *)a0)->f8C + 0x10);

    if (fn != 0)
        fn(a0);
}







int func_0216D744(int a0, int a1)
{

a1 = a0 + 0;
a1 = a1 + 0x90;
a1 = *(int *)&((struct Obj00113 *)((char *)a1))->f0;
a1 = *(int *)&((struct Obj00113 *)((char *)a1))->f0;
    if (a1 == 0) goto loc_0216D754;
loc_0216D752:
    a0 = ((int (*)())a1)();
loc_0216D754:
    return a0;}





void func_0216D758(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f90 + 0x4);

    if (fn != 0)
        fn(a0);
}





int func_0216D76C(void *a0){
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f90 + 0x8);

    if (fn != 0)
        fn(a0);
}





void func_0216D780(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f90 + 0xC);

    if (fn != 0)
        fn(a0);
}





void func_0216D794(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj12058 *)a0)->f90 + 0x10);

    if (fn != 0)
        fn(a0);
}




int func_0216D7A8(void *p, unsigned int v)
{
    Callback f;
    f = *(Callback *)&((struct Obj19128 *)((char *)((struct Obj00113 *)p)->f90))->f14;
    if (f != 0)
        return f(p, v);
    return 0;
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
 *   python tools/match.py one --src src/matched/func_0216D7C0.c \
 *       --func func_0216D7C0 --addr 0x0216D7C0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7C0(void *p, u16 v) { ((struct Obj17824 *)p)->f26 = v; }






/*
 * Reads the halfword field at +0x26.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D7C4(u8 *p)
{
    return ((struct Obj17825 *)p)->f26;
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
 *   python tools/match.py one --src src/matched/func_0216D7C8.c \
 *       --func func_0216D7C8 --addr 0x0216D7C8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D7C8(void *p, u16 v) { ((struct Obj17826 *)p)->f28 = v;  return p; }





/*
 * Increments the halfword at +0x28 of the object in r0.
 *
 * Filed as the TARGET of 27 ov021 `bl` sites (rule 10): ov010's listing emits
 * these 8 bytes as a `.word` because nothing traced an entry point here -- its
 * only callers are the ov021 sites -- so no `label` witness exists anywhere and
 * a region hint cannot invent one.  The source is the witness.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D7CC(u8 *p)
{
    ((struct Obj00113 *)p)->f28 = ((struct Obj00113 *)p)->f28 + 1;
}






/*
 * Reads the halfword field at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D7D4(u8 *p)
{
    return ((struct Obj17827 *)p)->f28;
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
 *   python tools/match.py one --src src/matched/func_0216D7D8.c \
 *       --func func_0216D7D8 --addr 0x0216D7D8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7D8(void *p, u32 v) { ((struct Obj17828 *)p)->f74 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7DC.c \
 *       --func func_0216D7DC --addr 0x0216D7DC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D7DC(void *p) { return ((struct Obj17829 *)p)->f74; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7E0.c \
 *       --func func_0216D7E0 --addr 0x0216D7E0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7E0(void *p, u32 v) { ((struct Obj17830 *)p)->f78 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7E4.c \
 *       --func func_0216D7E4 --addr 0x0216D7E4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D7E4(void *p) { return ((struct Obj17831 *)p)->f78; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7E8.c \
 *       --func func_0216D7E8 --addr 0x0216D7E8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D7E8(void *p) { return ((struct Obj17832 *)p)->f30; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7F0.c \
 *       --func func_0216D7F0 --addr 0x0216D7F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7F0(void *p, short v) { ((struct Obj17833 *)p)->f30 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7F4.c \
 *       --func func_0216D7F4 --addr 0x0216D7F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7F4(void *p, short v) { ((struct Obj17834 *)p)->f32 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7F8.c \
 *       --func func_0216D7F8 --addr 0x0216D7F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D7F8(void *p) { return ((struct Obj17835 *)p)->f34; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D800.c \
 *       --func func_0216D800 --addr 0x0216D800 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D800(void *p, short v) { ((struct Obj17836 *)p)->f34 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D804.c \
 *       --func func_0216D804 --addr 0x0216D804 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D804(void *p) { return ((struct Obj17837 *)p)->f36; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D80C.c \
 *       --func func_0216D80C --addr 0x0216D80C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D80C(void *p, s16 v) { ((struct Obj17838 *)p)->f36 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D810.c \
 *       --func func_0216D810 --addr 0x0216D810 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D810(void *p) { return ((struct Obj17839 *)p)->f38; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D818.c \
 *       --func func_0216D818 --addr 0x0216D818 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D818(void *p, s16 v) { ((struct Obj17840 *)p)->f38 = v; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D81C.c \
 *       --func func_0216D81C --addr 0x0216D81C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D81C(void *p) { return ((struct Obj17841 *)p)->f3A; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D824.c \
 *       --func func_0216D824 --addr 0x0216D824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D824(void *p, s16 v) { ((struct Obj17842 *)p)->f3A = v; }





/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 func_0217BDE0: copies the three
 * s16 at +0x3C/+0x3E/+0x40 out to a caller's vector.
 */
void func_0216D828(u8 *p, Vec3s *out)
{
    out->x = ((struct Obj00113 *)p)->f3C;
    out->y = ((struct Obj00113 *)p)->f3E;
    out->z = ((struct Obj00113 *)p)->f40;
}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D83C.c \
 *       --func func_0216D83C --addr 0x0216D83C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D83C(void *p) { return ((struct Obj17843 *)p)->f3C; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D844.c \
 *       --func func_0216D844 --addr 0x0216D844 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D844(void *p, short v) { ((struct Obj17844 *)p)->f3C = v; }




void func_0216D848(char *p, short v)
{
    ((struct Obj19129 *)p)->f3C += v;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D854.c \
 *       --func func_0216D854 --addr 0x0216D854 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D854(void *p) { return ((struct Obj17845 *)p)->f3E; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D85C.c \
 *       --func func_0216D85C --addr 0x0216D85C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D85C(void *p, int v) { ((struct Obj17846 *)p)->f3E = v; }




/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 func_0219912C.
 */
void func_0216D860(char *p, short v)
{
    ((struct Obj19130 *)p)->f3E += v;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D86C.c \
 *       --func func_0216D86C --addr 0x0216D86C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D86C(void *p) { return ((struct Obj17847 *)p)->f40; }






void func_0216D874(int a0, int a1)
{

a0 = a0 + 0x40;
((struct Obj17848 *)((char *)a0))->f0 = a1;
    return;}




void func_0216D87C(char *p, short v)
{
    ((struct Obj19131 *)p)->f40 += v;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D888.c \
 *       --func func_0216D888 --addr 0x0216D888 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D888(void *p) { return (char *)p + 68; }




/*
 * Copy an actor's position out (the getter of func_0216D89C).
 */
void func_0216D88C(const struct Actor *a, struct VecFx32 *out){
    *out = a->pos;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Twelve-byte struct copy between an interior member of the
 * object and a caller-supplied 3-word record: the compiler
 * emits ldm/stm plus the odd word.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D89C.c \
 *       --func func_0216D89C --addr 0x0216D89C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D89C(void *p, const Triple *q)
{
    *(Triple *)((char *)p + 68) = *q;
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
 *   python tools/match.py one --src src/matched/func_0216D8AC.c \
 *       --func func_0216D8AC --addr 0x0216D8AC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D8AC(void *p) { return ((struct Obj17849 *)p)->f48; }





/*
 * Copies a 12-byte record from p + 0x50 into q.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D8B0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x50);
}




/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: copies a 12-byte vector
 * into the object at +0x50.
 */
void func_0216D8C0(u8 *p, const Vec *v)
{
    *(Vec *)(p + 0x50) = *v;
}





/*
 * Copies a 12-byte record from p + 0x5c into q.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D8D0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x5c);
}




/*
 * Unlabelled leaf (no lr save): copies a 12-byte record into the object at
 * +0x5c.  Filed as the sole blocker of ov021 func_021A3DA0.
 */
void func_0216D8E0(u8 *p, Rec12 *src)
{
    *(Rec12 *)(p + 0x5c) = *src;
}





/*
 * Copies a 12-byte record from p + 0x68 into q.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D8F0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x68);
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Twelve-byte struct copy between an interior member of the
 * object and a caller-supplied 3-word record: the compiler
 * emits ldm/stm plus the odd word.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D900.c \
 *       --func func_0216D900 --addr 0x0216D900 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D900(void *p, const Triple *q)
{
    *(Triple *)((char *)p + 104) = *q;
}



int func_0216D910(int a0)
{

    a0 = (int)func_0216D67C((void *)a0);
loc_0216D916:
    a0 = func_0216D520((void *)a0);
loc_0216D91A:
    return a0;}





u8 func_0216D91C(int a0)
{

a0 = a0 + 0x7c;
a0 = ((struct Obj17850 *)((char *)a0))->f0;
    return a0;}





u8 func_0216D924(int a0)
{

a0 = a0 + 0x7d;
a0 = ((struct Obj17851 *)((char *)a0))->f0;
    return a0;}



/*
 * Unlabelled leaf: widens three signed bytes at p + 0x7e..0x80 to fixed
 * point (<< 12) and stores them into q[0..2].
 *
 * Addresses are Black-image addresses.
 */
void func_0216D92C(u8 *p, s32_0216D900 *q)
{
    q[0] = ((struct Obj09334 *)p)->f7E << 12;
    q[1] = ((struct Obj09334 *)p)->f7F << 12;
    q[2] = ((struct Obj09334 *)p)->f80 << 12;
}



int func_0216D948(int a0)
{
    int a1;
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D4D4(a0, a1);
loc_0216D952:
    if (a0 != 0) goto loc_0216D958;
loc_0216D956:
t4 = 0;
loc_0216D958:
a0 = t4 + 0;
    return a0;}


void func_0216D95C(unsigned int *p, unsigned int v, int a2)
{
    if (v == 1) func_0216D4DC((int)p, 1, a2);
    else func_0216D4E4(p, 1);
}


void func_0216D974(unsigned int *p, unsigned int v, int a2)
{
    if (v == 0) func_0216D4DC((int)p, 8, a2);
    else func_0216D4E4(p, 8);
}



int func_0216D98C(int a0)
{
    int a1;
a1 = 8;
    a0 = func_0216D4D4(a0, a1);
loc_0216D994:
    if (a0 != 0) goto loc_0216D99C;
loc_0216D998:
a0 = 1;
    return a0;
loc_0216D99C:
a0 = 0;
    return a0;}
