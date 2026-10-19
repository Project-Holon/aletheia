/*
 * function: BR_CODEIN_ProfileScreenCreate
 * address: 0x021E050C
 * packet: pkt_ov183_021E050C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E05C2 alignment padding.
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_CODEIN_ProfileCreateObject 0x021E07A4 thumb ov183
 *   BR_CODEIN_ProfileCreate 0x021E06D0 thumb ov183
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 */
#include "../include/Obj01767.h"
typedef unsigned short u16;
struct Data { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };
typedef unsigned int   u32;
struct Object;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_RES_LoadSprite(char *, unsigned int, unsigned int);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern struct Object *BR_CODEIN_ProfileCreateObject(int heap, int n, void *a, void *b, void *c, int *entries);
struct Source;
extern char *BR_CODEIN_ProfileCreate(const struct Source *src, u16 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *BR_UTIL_CreateTextWin(int, void *, u16);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
int BR_CODEIN_ProfileScreenCreate(void *task, int unused, char *q)
{
    struct Data *p;
    int entries[3];
    BR_RES_GetFont((char *)(*(int *)&((struct Obj01767 *)q)->f8));
    BR_RES_GetMsgData(*(char * *)&((struct Obj01767 *)q)->f8);
    p = PROCSYS_AllocProcWork(task, 24, BR_PROC_SYS_GetSlotId(((struct Obj01767 *)q)->fC));
    MI_CpuFill8(p, 0, 24);
    p->heap = BR_PROC_SYS_GetSlotId(((struct Obj01767 *)q)->fC);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj01767 *)q)->f8), 29, p->heap);
    BR_RES_LoadSprite(*(char * *)&((struct Obj01767 *)q)->f8, 11, p->heap);
    BR_RES_LoadSprite(*(char * *)&((struct Obj01767 *)q)->f8, 12, p->heap);
    BR_RES_LoadSprite(*(char * *)&((struct Obj01767 *)q)->f8, 6, p->heap);
    p->e = BR_UTIL_CreateHandles((unsigned int)(((struct Obj01767 *)q)->f4), (char *)(*(int *)&((struct Obj01767 *)q)->f8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = BR_CODEIN_ProfileCreateObject(p->heap, 12, ((struct Obj01767 *)q)->f4, (void *)(*(int *)&((struct Obj01767 *)q)->f8), p->e, entries);
    p->b = BR_CODEIN_ProfileCreate(p->a, p->heap);
    p->d = (void *)PRINTSYS_QUE_Create((void *)p->heap);
    p->c = BR_UTIL_CreateTextWin(*(int *)&((struct Obj01767 *)q)->f8, p->d, p->heap);
    BR_UTIL_SetWindowText(p->c, (char *)(*(int *)&((struct Obj01767 *)q)->f8), (void *)104);
    return 1;
}
