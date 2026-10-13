/*
 * function: NAMEIN_SETUP_StartHistoryScreenEvent
 * address: 0x0216C860
 * packet: pkt_ov010_0216C860
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   NAMEIN_SETUP_RunHistoryScreenEvent 0x0216C7FC thumb ov010
 */
#include "../include/Obj12397.h"
typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int NAMEIN_SETUP_RunHistoryScreenEvent(int, int *, int *);
void *NAMEIN_SETUP_StartHistoryScreenEvent(void *a) {
    void *v; void *t; void **p;
    v=GAMESYSTEM_GetFieldMap(a); t=func_020122C0(a,0,(void *)NAMEIN_SETUP_RunHistoryScreenEvent,0x14); p=func_020124E8(t);
    p[1]=a; ((struct Obj12397 *)p)->f0=v; return t;
}
