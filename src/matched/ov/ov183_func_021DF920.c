/*
 * function: func_021DF920
 * address: 0x021DF920
 * packet: pkt_ov183_021DF920
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   func_021E02F8 0x021E02F8 thumb ov183
 */
#include "../include/Obj01765.h"
#include "../include/Obj02230.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, int, unsigned int);
typedef unsigned int   u32;
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_RES_LoadSprite(char *base, u32 idx, u32 area);
extern void func_021E02F8(char *p, int *q);
int func_021DF920(void *obj, int unused, char *q)
{
    char *p;
    int i;
    p = PROCSYS_AllocProcWork(obj, 0x58, BR_PROC_SYS_GetSlotId((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC)));
    MI_CpuFill8(p, 0, 0x58);
    ((struct Obj01765 *)p)->f54 = BR_PROC_SYS_GetSlotId((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC));
    ((struct Obj01765 *)p)->f48 = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj01765 *)p)->f54));
    ((struct Obj01765 *)p)->f44 = BMP_OAM_CreateSys(((struct Obj01765 *)p)->f54, ((struct Obj02230 *)q)->f4);
    ((struct Obj01765 *)p)->f38 = (int)BR_UTIL_CreateTextWin(((struct Obj02230 *)q)->f8, (void *)(*(int *)&((struct Obj01765 *)p)->f48), ((struct Obj01765 *)p)->f54);
    BR_UTIL_SetWindowText((char *)(((struct Obj01765 *)p)->f38), (char *)(((struct Obj02230 *)q)->f8), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)(p + i * 4 + 0x3C) = (int)BR_UTIL_CreateHandles(*(int *)&((struct Obj02230 *)q)->f4, (char *)(((struct Obj02230 *)q)->f8), i, ((struct Obj01765 *)p)->f54);
    }
    ((struct Obj02230 *)q)->f14 = 0xFFFF;
    ((struct Obj02230 *)q)->f16 = 0xFF;
    ((struct Obj02230 *)q)->f17 = 0xFF;
    ((struct Obj02230 *)q)->f18 = 0x13;
    BR_RES_LoadSprite((char *)(((struct Obj02230 *)q)->f8), 6, ((struct Obj01765 *)p)->f54);
    func_021E02F8(p, (int *)q);
    return 1;
}
