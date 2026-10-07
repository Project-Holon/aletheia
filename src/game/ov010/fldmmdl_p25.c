/*
 * file:     fldmmdl_p25.c
 * unit:     yes
 * function: func_0216D844, func_0216D848, func_0216D854, func_0216D85C, func_0216D860, func_0216D86C, func_0216D874, func_0216D87C, func_0216D888, func_0216D88C, func_0216D89C, func_0216D8AC, func_0216D8B0, func_0216D8C0, func_0216D8D0, func_0216D8E0, func_0216D8F0
 * address:  0x0216D844
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17844.h"
#include "../../matched/include/Obj19129.h"
#include "../../matched/include/Obj17845.h"
#include "../../matched/include/Obj17846.h"
#include "../../matched/include/Obj19130.h"
#include "../../matched/include/Obj17847.h"
#include "../../matched/include/Obj17848.h"
#include "../../matched/include/Obj19131.h"
#include "../../matched/include/Obj17849.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef int s32;

typedef s32 fx32;

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

void func_0216D844(void *p, short v);
void func_0216D848(char *p, short v);
int func_0216D854(void *p);
void func_0216D85C(void *p, int v);
void func_0216D860(char *p, short v);
int func_0216D86C(void *p);
void func_0216D874(int a0, int a1);
void func_0216D87C(char *p, short v);
void *func_0216D888(void *p);
void func_0216D88C(const Actor *a, VecFx32 *out);
void func_0216D89C(void *p, const Triple *q);
u32 func_0216D8AC(void *p);
void func_0216D8B0(u8 *p, u8 *q);
void func_0216D8C0(u8 *p, const Vec *v);
void func_0216D8D0(u8 *p, u8 *q);
void func_0216D8E0(u8 *p, Rec12 *src);
void func_0216D8F0(u8 *p, u8 *q);


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
void func_0216D88C(const Actor *a, VecFx32 *out)
{
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
