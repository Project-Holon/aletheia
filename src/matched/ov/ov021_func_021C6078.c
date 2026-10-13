/*
 * function: SWEET_SCENT_CreateEvent
 * address:  0x021C6078
 * packet:   pkt_ov021_021C6078
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   SWEET_SCENT_EventMain  0x021C60B8  thumb  ov021
 */
#include "../include/Obj06082.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void SWEET_SCENT_EventMain(void);

void *SWEET_SCENT_CreateEvent(void *a, void *b, u8 c)
{
    void *task;
    u8 *w;

    task = func_020122C0(a, 0, SWEET_SCENT_EventMain, 0x14);
    w = func_020124E8(task);
    MI_CpuFill8(w, 0, 0x14);
    w[0] = c;
    ((struct Obj06082 *)w)->f4 = a;
    ((struct Obj06082 *)w)->fC = b;
    ((struct Obj06082 *)w)->f10 = FIELDMAP_GetFieldPlayer(b);
    ((struct Obj06082 *)w)->f8 = func_020120F4(a);
    return task;
}
