/*
 * function: FLDMMDL_SetupSysProc
 * address:  0x0216CCDC
 * packet:   pkt_ov010_0216CCDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever: The allocation result is the second argument to func_02030CBC; its r1 live range orders the halfword reload.
 *
 * DIFF: original moves the alloc result to r1 (adds r1,r0) and stores it after the ldrh reload
 * (+2 B, pool shifts 4). Tried a result local and a halfword local.
 *
 * symbols:
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020490F4  0x020490F4  arm
 *   FLDMMDL_SysSetStatusBit  0x0216D4DC  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 */
#include "../include/Obj02669.h"

typedef unsigned int   u32;
typedef unsigned short u16;
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Ctx;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020490F4(u32 id, u32 heap);
extern void FLDMMDL_SysSetStatusBit(void *, int);
extern char d_02172B48[];

void FLDMMDL_SetupSysProc(char *a, int b, int c, int d, int e, int f)
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
    FLDMMDL_SysSetStatusBit(a, 0x10);
}
