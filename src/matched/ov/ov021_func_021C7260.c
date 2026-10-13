/*
 * function: FIELD_TASK_CreatePlayerSpinEaseIn
 * address:  0x021C7260
 * packet:   pkt_ov021_021C7260
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
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_TASK_UpdateSpinEaseIn  0x021C748C  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 */
#include "../include/Obj05088.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void *FIELD_TASK_Create(u32 h, int size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
extern void FIELD_TASK_UpdateSpinEaseIn(void);
extern u16 FLDMMDL_GetDirDisp(void *a);

void *FIELD_TASK_CreatePlayerSpinEaseIn(u32 a, u16 b, int c)
{
    void *o;
    u8 *p;
    u32 h;
    void *q;
    void *t;

    h = FIELDMAP_GetHeapId((u8 *)a);
    q = FIELDMAP_GetFieldPlayer((void *)a);
    o = FIELD_TASK_Create(h, 0x10, (void *)FIELD_TASK_UpdateSpinEaseIn);
    p = (u8 *)FIELD_TASK_GetWork(o);
    ((struct Obj05088 *)p)->f0 = a;
    t = FIELD_PLAYER_GetMmdl((void *)q);
    ((struct Obj05088 *)p)->f4 = t;
    ((struct Obj05088 *)p)->f8 = 0;
    ((struct Obj05088 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05088 *)p)->fE = FLDMMDL_GetDirDisp(t);
    return o;
}
