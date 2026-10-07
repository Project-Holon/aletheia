/*
 * file:     fldmmdl_p24.c
 * unit:     yes
 * function: func_0216D6D8, func_0216D6F0, func_0216D6F4, func_0216D708, func_0216D71C, func_0216D730, func_0216D744, func_0216D758, func_0216D76C, func_0216D780, func_0216D794, func_0216D7A8, func_0216D7C0, func_0216D7C4, func_0216D7C8, func_0216D7CC, func_0216D7D4, func_0216D7D8, func_0216D7DC, func_0216D7E0, func_0216D7E4, func_0216D7E8, func_0216D7F0, func_0216D7F4, func_0216D7F8, func_0216D800, func_0216D804, func_0216D80C, func_0216D810, func_0216D818, func_0216D81C, func_0216D824, func_0216D828, func_0216D83C
 * address:  0x0216D6D8
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
#include "../../matched/include/Obj17814.h"
#include "../../matched/include/Obj17816.h"
#include "../../matched/include/Obj00113.h"
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

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

extern int func_02082BCC();
void *func_0216D6D8(int a0, int a1);
void *func_0216D6F0(void *p);
void func_0216D6F4(void *a0);
void func_0216D708(void *a0);
void func_0216D71C(void *a0);
void func_0216D730(void *a0);
int func_0216D744(int a0, int a1);
void func_0216D758(void *a0);
void func_0216D76C(void *a0);
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
void func_0216D7F0(void *p, short v);
void func_0216D7F4(void *p, short v);
int func_0216D7F8(void *p);
void func_0216D800(void *p, short v);
int func_0216D804(void *p);
void func_0216D80C(void *p, u16 v);
int func_0216D810(void *p);
void func_0216D818(void *p, u16 v);
int func_0216D81C(void *p);
void func_0216D824(void *p, u16 v);
void func_0216D828(u8 *p, Vec3s *out);
int func_0216D83C(void *p);


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


void func_0216D71C(void *a0)
{
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


void func_0216D76C(void *a0)
{
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
void func_0216D80C(void *p, u16 v) { ((struct Obj17838 *)p)->f36 = v; }


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
void func_0216D818(void *p, u16 v) { ((struct Obj17840 *)p)->f38 = v; }


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
void func_0216D824(void *p, u16 v) { ((struct Obj17842 *)p)->f3A = v; }


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
