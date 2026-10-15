/*
 * function: BR_CODEIN_ListCreate
 * address: 0x021DD37C
 * packet: pkt_ov183_021DD37C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_CODEIN_ListSetupButtons 0x021DDE2C thumb ov183
 *   BR_CODEIN_ListSetupText 0x021DD5C8 thumb ov183
 */
#include "../include/Obj00631.h"
#include "../include/Obj00632.h"
typedef unsigned short u16;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
typedef unsigned int   u32;
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_RES_LoadSprite(char *, unsigned int, unsigned int);
extern void BR_CODEIN_ListSetupButtons(char *, char *);
extern void BR_CODEIN_ListSetupText(char *, char *);
int BR_CODEIN_ListCreate(void *a, int unused, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x80, BR_PROC_SYS_GetSlotId((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC)));
    MI_CpuFill8(p, 0, 0x80);
    ((struct Obj00631 *)p)->f7C = BR_PROC_SYS_GetSlotId((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC));
    ((struct Obj00631 *)p)->f0 = BMP_OAM_CreateSys(((struct Obj00631 *)p)->f7C, ((struct Obj00632 *)q)->f4);
    ((struct Obj00631 *)p)->f4 = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj00631 *)p)->f7C));
    ((struct Obj00631 *)p)->f74 = BR_UTIL_CreateHandles((unsigned int)(((struct Obj00632 *)q)->f4), (char *)(*(int *)&((struct Obj00632 *)q)->f8), 1, ((struct Obj00631 *)p)->f7C);
    BR_RES_LoadSprite(*(char * *)&((struct Obj00632 *)q)->f8, 13, ((struct Obj00631 *)p)->f7C);
    BR_CODEIN_ListSetupButtons(p, q);
    BR_CODEIN_ListSetupText(p, q);
    return 1;
}
