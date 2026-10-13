/*
 * function: EVENT_FIELD_PROCLINK_CreateFreeEvent
 * address:  0x021616A4
 * packet:   pkt_021616A4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, zero-fills the node, then fills link fields.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   EVENT_FIELD_PROCLINK_FreeEventMain  0x021616F0  thumb  ov010
 */
#include "../include/Obj04884.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Big;
struct Ctx;
void *func_020120F4(const struct Ctx *p);
void *GAME_DATA_GetSaveControl(struct Big *p);
void func_02082BCC(void *p, int v, int n);
int EVENT_FIELD_PROCLINK_FreeEventMain(int a0, int a1, int a2);

void *EVENT_FIELD_PROCLINK_CreateFreeEvent(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, EVENT_FIELD_PROCLINK_FreeEventMain, 0x1C);
    char *r4 = func_020124E8(r0v);

    func_02082BCC(r4, 0, 0x1C);
    ((struct Obj04884 *)r4)->fC = a3;
    ((struct Obj04884 *)r4)->f10 = a2;
    ((struct Obj04884 *)r4)->f4 = (int)p;
    ((struct Obj04884 *)r4)->f8 = a1;
    ((struct Obj04884 *)r4)->f0 = (int)GAME_DATA_GetSaveControl(func_020120F4(p));
    ((struct Obj04884 *)r4)->f14 = a4;
    return r0v;
}
