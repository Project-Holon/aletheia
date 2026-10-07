/*
 * file:     trcard_sys_p01.c
 * unit:     yes
 * function: func_0216E474, func_0216E47C, func_0216E490, func_0216E4B0, func_0216E4EC, func_0216E51C, func_0216E544, func_0216E57C
 * address:  0x0216E474
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
 *   MIi_CpuClear32  0x02082A7C  arm
 *   d_02172A70 0x02172A70 data a2
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D88C 0x0216D88C thumb ov010
 */
#include "../../matched/include/Obj09169.h"
#include "../../matched/include/Obj19138.h"
#include "../../matched/include/Obj19139.h"

struct Actor;
struct VecFx32;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Vec_0216E544;

typedef struct
{
    int x;
    int y;
    int z;
} Vec_0216E57C;

typedef struct
{
    char pad00[44];
    unsigned int raw44;
} Context;

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u16 func_0216D598(void *p);
extern int func_0216E5FC();
extern u16 func_0216D590(void *p);
extern u16 func_0216D588(void *p);
extern void *func_0216D67C(void *);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
u32 func_0216E474(void);
void func_0216E47C(void *block);
int func_0216E490(int a0);
int func_0216E4B0(int a, int b);
int func_0216E4EC(int a0, int a1);
int func_0216E51C(void *a, int a1);
int func_0216E544(void *a, Vec_0216E544 *out);
void func_0216E57C(void *a, int a1);
extern const u16 d_02172A70[][4];


/*
 * Save-table size callback: returns 0x168, the size of the block that
 * func_0216E47C fills.  Pointer word 0x0216E475 at arm9 0x0209DC90.
 */
u32 func_0216E474(void)
{
    return 0x168;
}


/*
 * Save-table init callback: fills the 0x168-byte block with 0xFF bytes
 * (tail call to MIi_CpuClear32 through the pool word at 0x0216E48C).
 * Pointer word 0x0216E47D at arm9 0x0209DC94.
 */
void func_0216E47C(void *block)
{
    MIi_CpuClear32(0xFFFFFFFF, block, 0x168);
}




int func_0216E490(int a0)
{
    int a1;
    int a2;

a1 = 0;
a2 = ((struct Obj09169 *)((char *)a0))->f0;
a1 = ~a1;
    if (a2 != a1) goto loc_0216E4A6;
loc_0216E49A:
a2 = ((struct Obj09169 *)a0)->f4;
    if (a2 != a1) goto loc_0216E4A6;
loc_0216E4A0:
a0 = ((struct Obj09169 *)a0)->f8;
    if (a0 == a1) goto loc_0216E4AA;
loc_0216E4A6:
a0 = 1;
    return a0;
loc_0216E4AA:
a0 = 0;
    return a0;}


/*
 * lever: declaring x and y before the unsigned-long index restores the
 * table base, sentinel and index register allocation. The once300
 * permuter found this ordering; explicit-region one resolves both pools.
 */
int func_0216E4B0(int a, int b)
{
    int x;
    int y;
    unsigned long i;
    i = 0;
    do
    {
        x = d_02172A70[i][0];
        y = d_02172A70[i][1];
        if ((x == a) && (y == b))
            return d_02172A70[i][2];
        i++;
    }
    while ((x != 65535) && (y != 65535));
    return 30;
}


int func_0216E4EC(int a0, int a1)
{
    int t4;
    int t5;

t4 = a0 + 0;
t5 = 0x1e;
    a0 = func_0216D598((void *)a0);
loc_0216E4F6:
    a0 = func_0216E5FC(a0);
loc_0216E4FA:
    if (a0 != 1) goto loc_0216E516;
loc_0216E4FE:
a0 = t4 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E504:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E50C:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216E4B0(a0, a1);
loc_0216E514:
t5 = a0 + 0;
loc_0216E516:
a0 = t5 + 0;
    return a0;}

int func_0216E51C(void *a, int a1) { int i; unsigned int base; i=func_0216E4EC((int)a, a1); if(i!=30) { base=((struct Obj19138 *)((char *)func_0216D67C(a)))->f2C; return func_0216E490((int)((void *)(base+i*12))); } return 0; }

int func_0216E544(void *a, Vec_0216E544 *out) { int i; Vec_0216E544 *p; unsigned int base; i=func_0216E4EC((int)a, (int)out); if(i!=30) { base=((struct Obj19139 *)((char *)func_0216D67C(a)))->f2C; p=(Vec_0216E544 *)(base+i*12); if(func_0216E490((int)p)) { *out=*p; return 1; } } return 0; }


/*
 * lever: binding the getter's pointer result to tmp restores the base
 * load before the stride, while retaining the unsigned raw address sum.
 * Context shape: matched CC58 allocates 0x48 and stores input c at +44.
 * E4EC returns 30 unless E4FA compares equal to 1, then returns E4B0's
 * halfword or 30. Thus i <=65535 and i*12 <=786420; no Vec array bound
 * is assumed. D88C unconditionally initializes all 12 bytes of v.
 */
void func_0216E57C(void *a, int a1)
{
    int i;
    Vec_0216E57C *p;
    Vec_0216E57C v;
    Context *tmp;
    i = func_0216E4EC((int)a, a1);
    if (i != 30)
    {
        tmp = func_0216D67C(a);
        p = (Vec_0216E57C *) (tmp->raw44 + (i * 12));
        func_0216D88C(a, (struct VecFx32 *)&v);
        *p = v;
    }
}
