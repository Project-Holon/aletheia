/*
 * function: BR_CODEIN_ResultCreate
 * address: 0x021DE1C8
 * packet: pkt_ov183_021DE1C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_CODEIN_ResultSetupTextWin 0x021DE3E4 thumb ov183
 *   BR_CODEIN_ResultSetupButtons 0x021DE7C0 thumb ov183
 */
#include "../include/Obj02519.h"
#include "../include/Obj06604.h"
typedef unsigned short u16;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
typedef unsigned int   u32;
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_CODEIN_ResultSetupTextWin(char *, char *);
extern void BR_CODEIN_ResultSetupButtons(char *, char *);
int BR_CODEIN_ResultCreate(void *a, int b, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x70, BR_PROC_SYS_GetSlotId(((struct Obj06604 *)q)->fC));
    MI_CpuFill8(p, 0, 0x70);
    ((struct Obj02519 *)p)->f6C = BR_PROC_SYS_GetSlotId(((struct Obj06604 *)q)->fC);
    ((struct Obj02519 *)p)->f0 = BMP_OAM_CreateSys(((struct Obj02519 *)p)->f6C, ((struct Obj06604 *)q)->f0);
    ((struct Obj02519 *)p)->f4 = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj02519 *)p)->f6C));
    ((struct Obj02519 *)p)->f64 = BR_UTIL_CreateHandles((unsigned int)(((struct Obj06604 *)q)->f0), (char *)(((struct Obj06604 *)q)->f8), 1, ((struct Obj02519 *)p)->f6C);
    BR_CODEIN_ResultSetupTextWin(p, q);
    BR_CODEIN_ResultSetupButtons(p, q);
    return 1;
}
