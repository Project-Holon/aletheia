/*
 * function: func_021DE9A0
 * address: 0x021DE9A0
 * packet: pkt_ov183_021DE9A0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DF0DC 0x021DF0DC thumb ov183
 *   func_021DEB4C 0x021DEB4C thumb ov183
 */
#include "../include/Obj02229.h"
#include "../include/Obj06605.h"
#include "../include/Obj24581.h"
typedef unsigned short u16;
struct Obj24810;
extern unsigned func_021F9B9C(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
typedef unsigned int   u32;
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern int *func_021FD73C(int *p, int v);
extern void func_021DF0DC(int *p, int *state, char *q);
extern void func_021DEB4C(int *task, int *state, char *p);
int func_021DE9A0(void *a, int b, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x10C, func_021F9B9C(((struct Obj06605 *)q)->f14));
    int i;
    MI_CpuFill8(p, 0, 0x10C);
    *(char * *)&((struct Obj02229 *)p)->f108 = q;
    ((struct Obj02229 *)p)->f18 = func_021F9B9C(((struct Obj06605 *)q)->f14);
    ((struct Obj02229 *)p)->f0 = BMP_OAM_CreateSys(((struct Obj02229 *)p)->f18, ((struct Obj06605 *)q)->fC);
    ((struct Obj02229 *)p)->f14 = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj02229 *)p)->f18));
    for (i = 0; i < 2; i++)
        *(void **)(p + i * 4 + 0x1C) = func_021FD760((unsigned int)(((struct Obj06605 *)q)->fC), (char *)(((struct Obj06605 *)q)->f10), i, ((struct Obj02229 *)p)->f18);
    ((struct Obj02229 *)p)->f10 = func_021FD6D8((int)p, (int)func_021DF0DC, ((struct Obj02229 *)p)->f18);
    if (((struct Obj24581 *)(*(char * *)&((struct Obj02229 *)p)->f108))->f4 != 0)
        func_021FD73C(((struct Obj02229 *)p)->f10, (int)func_021DEB4C);
    else
        func_021FD73C(((struct Obj02229 *)p)->f10, (int)func_021DF0DC);
    return 1;
}
