/*
 * function: FIELD_FK_DEMO_CreateEvent
 * address:  0x021F36F0
 * packet:   pkt_ov056_021F36F0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   FIELD_FK_DEMO_EventMain  0x021F3734  thumb  ov056
 *   FIELD_FK_DEMO_UploadModelTask  0x021F36E4  thumb  ov056
 */
#include "../include/Obj07668.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Desc;
struct Obj;
struct Work;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020056A0(void (*cb)(void), void *ctx, int a);
extern int FIELD_FK_DEMO_EventMain(void *a0, int *state, struct Work *p);
extern void FIELD_FK_DEMO_UploadModelTask(u8 *a, u8 *b);

void *FIELD_FK_DEMO_CreateEvent(void *a, u8 *b, u32 c)
{
    void *r;
    u32 *t;

    FIELDMAP_GetHeapId(b);
    r = func_020122C0(a, 0, FIELD_FK_DEMO_EventMain, 0xd4);
    t = func_020124E8(r);
    t[0] = (u32)b;
    t[1] = (u32)a;
    t[2] = c;
    ((struct Obj07668 *)t)->fD0 = func_020056A0((void (*)(void))FIELD_FK_DEMO_UploadModelTask, t, 0);
    return r;
}
