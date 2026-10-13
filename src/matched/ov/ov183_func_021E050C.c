/*
 * function: func_021E050C
 * address: 0x021E050C
 * packet: pkt_ov183_021E050C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E05C2 alignment padding.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021E07A4 0x021E07A4 thumb ov183
 *   func_021E06D0 0x021E06D0 thumb ov183
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 */
#include "../include/Obj01767.h"
typedef unsigned short u16;
struct Data { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };
typedef unsigned int   u32;
struct Object;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
struct Obj24810;
extern unsigned func_021F9B9C(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBE54(char *, unsigned int, unsigned int);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries);
struct Source;
extern char *func_021E06D0(const struct Source *src, u16 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *func_021FD12C(int, void *, u16);
extern void func_021FD170(char *p, char *q, void *text);
int func_021E050C(void *task, int unused, char *q)
{
    struct Data *p;
    int entries[3];
    func_021FC20C((char *)(*(int *)&((struct Obj01767 *)q)->f8));
    func_021FC214(*(char * *)&((struct Obj01767 *)q)->f8);
    p = PROCSYS_AllocProcWork(task, 24, func_021F9B9C(((struct Obj01767 *)q)->fC));
    MI_CpuFill8(p, 0, 24);
    p->heap = func_021F9B9C(((struct Obj01767 *)q)->fC);
    func_021FB964((void *)(*(int *)&((struct Obj01767 *)q)->f8), 29, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 11, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 12, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 6, p->heap);
    p->e = func_021FD760((unsigned int)(((struct Obj01767 *)q)->f4), (char *)(*(int *)&((struct Obj01767 *)q)->f8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = func_021E07A4(p->heap, 12, ((struct Obj01767 *)q)->f4, (void *)(*(int *)&((struct Obj01767 *)q)->f8), p->e, entries);
    p->b = func_021E06D0(p->a, p->heap);
    p->d = (void *)PRINTSYS_QUE_Create((void *)p->heap);
    p->c = func_021FD12C(*(int *)&((struct Obj01767 *)q)->f8, p->d, p->heap);
    func_021FD170(p->c, (char *)(*(int *)&((struct Obj01767 *)q)->f8), (void *)104);
    return 1;
}
