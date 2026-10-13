/*
 * function: FLDEFF_SHADOW_Create
 * address:  0x021AC218
 * packet:   pkt_ov021_021AC218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetEffectBbdAct  0x02188C88  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   FLDEFF_SHADOW_CreateSlot  0x021AC274  thumb  ov021
 *   d_021DE028     0x021DE028  data  a1
 *   gFldeffShadowBaseOffset     0x021D908C  data  a4
 */
#include "../include/Obj04241.h"

typedef struct { int x; int y; int z; } V;

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern u32 FIELDMAP_GetEffectBbdAct(u8 *p);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
struct Ctl;
extern void FLDEFF_SHADOW_CreateSlot(struct Ctl *p);
extern char d_021DE028[];
extern V gFldeffShadowBaseOffset;

char *FLDEFF_SHADOW_Create(int a, int heap)
{
    char *p;

    p = (char *)func_02030734(heap, 0x1c, 1, d_021DE028, 0x5c);
    *(int *)&((struct Obj04241 *)p)->f0 = a;
    *(V *)(p + 4) = gFldeffShadowBaseOffset;
    ((struct Obj04241 *)p)->f10 = FIELDMAP_GetEffectBbdAct((u8 *)FIELD_EFFECT_GetFieldMap((u8 *)a));
    ((struct Obj04241 *)p)->f14 = BILLBOARD_ACT_GetBoard((u32 *)(((struct Obj04241 *)p)->f10));
    FLDEFF_SHADOW_CreateSlot((struct Ctl *)p);
    return p;
}
