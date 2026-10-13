/*
 * function: FIELD_TASK_CreateMmdlSpinLinear
 * address:  0x021C7220
 * packet:   pkt_ov021_021C7220
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_TASK_UpdateSpinLinear  0x021C7418  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 */
#include "../include/Obj05087.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELD_TASK_Create(u32 h, int size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
extern void FIELD_TASK_UpdateSpinLinear(void);
extern u16 FLDMMDL_GetDirDisp(void *p);

void *FIELD_TASK_CreateMmdlSpinLinear(u32 a, u16 b, int c, u32 d)
{
    void *o;
    u8 *p;

    o = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 0x10, (void *)FIELD_TASK_UpdateSpinLinear);
    p = (u8 *)FIELD_TASK_GetWork(o);
    ((struct Obj05087 *)p)->f0 = a;
    ((struct Obj05087 *)p)->f4 = d;
    ((struct Obj05087 *)p)->f8 = 0;
    ((struct Obj05087 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05087 *)p)->fE = FLDMMDL_GetDirDisp((void *)d);
    return o;
}
