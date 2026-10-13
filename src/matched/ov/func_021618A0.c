/*
 * function: EVENT_FIELD_PROCLINK_CreateObjAnimEvent
 * address:  0x021618A0
 * packet:   pkt_021618A0
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then a sub-init call and link fields.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_FIELD_PROCLINK_ObjAnimEventMain  0x02161850  thumb  ov010
 *   EVENT_FIELD_PROCLINK_ClearAnimNode  0x02161950  thumb  ov010
 */
#include "../include/Obj05855.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
int EVENT_FIELD_PROCLINK_ObjAnimEventMain(void *a0, int *state, struct Obj *o);
void EVENT_FIELD_PROCLINK_ClearAnimNode(char *p);

void *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(void *p, int a1, int a2, int a3)
{
    void *r0v = func_020122C0(p, 0, EVENT_FIELD_PROCLINK_ObjAnimEventMain, 0x34);
    char *r4 = func_020124E8(r0v);

    EVENT_FIELD_PROCLINK_ClearAnimNode(r4);
    ((struct Obj05855 *)r4)->f0 = p;
    ((struct Obj05855 *)r4)->f4 = a1;
    ((struct Obj05855 *)r4)->f8 = (int)GAMESYSTEM_GetGameData(p);
    ((struct Obj05855 *)r4)->fC = a2;
    ((struct Obj05855 *)r4)->f10 = a3;
    return r0v;
}
