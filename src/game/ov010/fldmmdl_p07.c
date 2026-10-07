/*
 * file:     fldmmdl_p07.c
 * unit:     yes
 * function: func_0216CCDC, func_0216CD30
 * address:  0x0216CCDC
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
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0216D4DC  0x0216D4DC  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0216D4E4  0x0216D4E4  thumb  ov010
 */
#include "../../matched/include/Obj02669.h"
#include "../../matched/include/Obj09166.h"

struct Ctx;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0216D4DC(void *, int);
extern int func_02030DA4();
extern u32 func_020307B0(void *p);
extern void func_02049238(void *arc);
extern u32 *func_0216D4E4(u32 *p, u32 v);
void func_0216CCDC(char *a, int b, int c, int d, int e, int f);
void func_0216CD30(u32 *a0, int a1);
extern char d_02172B48[];


/*
 * lever: The allocation result is the second argument to func_02030CBC; its r1 live range orders the halfword reload.
 *
 * DIFF: original moves the alloc result to r1 (adds r1,r0) and stores it after the ldrh reload
 * (+2 B, pool shifts 4). Tried a result local and a halfword local.
 */
void func_0216CCDC(char *a, int b, int c, int d, int e, int f)
{
    int t;
    unsigned short h;
    ((struct Obj02669 *)a)->f34 = e;
    ((struct Obj02669 *)a)->fA = b;
    ((struct Obj02669 *)a)->f30 = c;
    ((struct Obj02669 *)a)->f3C = d;
    t = (int)func_02030734(b, func_02030CB0(((struct Obj02669 *)a)->f4), 0, d_02172B48, 0x109);
    h = ((struct Obj02669 *)a)->f4;
    ((struct Obj02669 *)a)->f1C = t;
    ((struct Obj02669 *)a)->f20 = (int)func_02030CBC(h, (struct Ctx *)t);
    ((struct Obj02669 *)a)->f10 = (int)func_020490F4(0x31, b);
    ((struct Obj02669 *)a)->f38 = f;
    func_0216D4DC(a, 0x10);
}


void func_0216CD30(u32 *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
a0 = (u32 *)(((struct Obj09166 *)t4)->f20);
    a0 = (u32 *)func_02030DA4(a0);
loc_0216CD3A:
a0 = (u32 *)(((struct Obj09166 *)t4)->f1C);
    a0 = (u32 *)func_020307B0(a0);
loc_0216CD40:
a0 = (u32 *)(((struct Obj09166 *)t4)->f10);
    func_02049238((void *)a0);
loc_0216CD46:
a0 = (u32 *)(t4 + 0);
a1 = 0x10;
    a0 = (u32 *)func_0216D4E4(a0, a1);
loc_0216CD4E:
    return;}
