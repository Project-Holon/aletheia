/*
 * function: CG_HELP_ProcInit
 * address: 0x021D4B14
 * packet: pkt_ov124_021D4B14
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   KEY_GetCont 0x0203630C arm
 *   func_0200854C 0x0200854C thumb
 *   gCgHelpFileName 0x021D4D4C data ov124 a1
 *   CG_HELP_Setup 0x021D4240 thumb ov124
 *   MYSTATUS_Create  0x0200846C  thumb  arm9
 */
#include "../include/Obj00068.h"
typedef unsigned short u16;
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern void *MYSTATUS_Create(int a0);
extern unsigned int KEY_GetCont(void);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void CG_HELP_Setup(char *);
extern const char gCgHelpFileName[];
int CG_HELP_ProcInit(void *a,int b,void *c)
{
    char *p;
    void **q;
    GFL_HEAP_CreateChildHeap(1,0x8a,0x60000);
    p = PROCSYS_AllocProcWork(a,0x60,0x8a);
    q = c;
    if (!q) {
        q = func_02030734(0x8a,8,1,gCgHelpFileName,0x2f3);
        *q = MYSTATUS_Create(0x8a);
        if (KEY_GetCont() & 0x100) func_0200854C(*q,1);
        else func_0200854C(*q,0);
    }
    ((struct Obj00068 *)p)->f4 = q;
    ((struct Obj00068 *)p)->f0 = 0x8a;
    CG_HELP_Setup(p);
    return 1;
}
