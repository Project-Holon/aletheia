/*
 * function: EVENT_COMM_COMMON_CreateMissionResultEvent
 * address:  0x021804F8
 * packet:   pkt_ov018_021804F8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb ov021
 *   EVENT_COMM_COMMON_MissionResultEventMain  0x02180538  thumb ov018
 */
#include "../include/Obj12504.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
struct Desc;
struct Obj;
void *func_0201210C(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
u16 FIELDMAP_GetHeapId(u8 *p);
int EVENT_COMM_COMMON_MissionResultEventMain(void);

void *EVENT_COMM_COMMON_CreateMissionResultEvent(void *p, int a)
{
    void *v = func_0201210C(p);
    void *r = func_020122C0(p, 0, EVENT_COMM_COMMON_MissionResultEventMain, 0x138);
    u16 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x138);
    *q = FIELDMAP_GetHeapId(v);
    ((struct Obj12504 *)q)->f34 = a;
    return r;
}
