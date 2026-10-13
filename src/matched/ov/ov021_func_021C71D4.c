/*
 * function: FIELD_TASK_CreatePlayerSpinLinear
 * address:  0x021C71D4
 * packet:   pkt_ov021_021C71D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_TASK_UpdateSpinLinear  0x021C7418  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05086.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_TASK_Create(u32 heap, u32 n, void *cb);
extern u32 FIELD_TASK_GetWork(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetDirDisp(void *a);
extern void FIELD_TASK_UpdateSpinLinear(void);

void *FIELD_TASK_CreatePlayerSpinLinear(u32 a, u32 b, u32 c)
{
    u32 heap = FIELDMAP_GetHeapId((u8 *)a);
    void *x = FIELDMAP_GetFieldPlayer((void *)a);
    void *r = FIELD_TASK_Create(heap, 0x10, (void *)FIELD_TASK_UpdateSpinLinear);
    u8 *e = (u8 *)FIELD_TASK_GetWork(r);
    void *t;

    ((struct Obj05086 *)e)->f0 = a;
    t = FIELD_PLAYER_GetMmdl((void *)x);
    ((struct Obj05086 *)e)->f4 = t;
    ((struct Obj05086 *)e)->f8 = 0;
    ((struct Obj05086 *)e)->fA = b;
    e[12] = c;
    ((struct Obj05086 *)e)->fE = FLDMMDL_GetDirDisp(t);
    return r;
}
