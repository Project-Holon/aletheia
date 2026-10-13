/*
 * function: FIELD_BUILDMODEL_LoadModel
 * address:  0x0218BEE8
 * packet:   pkt_ov021_0218BEE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   G3D_SYSTEM_InitResourceByFile  0x02046CE0  arm
 *   FIELD_BUILDMODEL_GetModelDef  0x0218B924  thumb  ov021
 *   FIELD_BUILDMODEL_GetModelResourceData  0x0218BC00  thumb  ov021
 *   FIELD_BUILDMODEL_GetAnimResourceData  0x0218BC10  thumb  ov021
 *   FIELD_BUILDMODEL_CountAnimResources  0x0218BC8C  thumb  ov021
 *   FIELD_BUILDMODEL_GetModelAnimDefs  0x0218BCAC  thumb  ov021
 *   gBuildModelFileName     0x021DD9CC  data  ov021  a1
 */
#include "../include/Obj09454.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int G3D_SYSTEM_GetResourceSize(void);
struct S02046CE0;
extern void G3D_SYSTEM_InitResourceByFile(struct S02046CE0 *out, u32 *tag);
extern int FIELD_BUILDMODEL_GetModelDef(u8 *p, u32 a1);
extern char *FIELD_BUILDMODEL_GetModelResourceData(char *p, int i);
extern u8 *FIELD_BUILDMODEL_GetAnimResourceData(u8 *p, int i);
extern int FIELD_BUILDMODEL_CountAnimResources(int *p);
extern u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);
extern char gBuildModelFileName[];

void FIELD_BUILDMODEL_LoadModel(u8 *s, void **out, int x)
{
    u8 *t;
    int cnt;
    int i;

    out[0] = (void *)FIELD_BUILDMODEL_GetModelDef(s, x);
    out[1] = func_02030734(((struct Obj09454 *)s)->f0, G3D_SYSTEM_GetResourceSize(), 1, gBuildModelFileName, 0x4d0);
    G3D_SYSTEM_InitResourceByFile(out[1], (u32 *)FIELD_BUILDMODEL_GetModelResourceData(((struct Obj09454 *)s)->f18, x));
    t = FIELD_BUILDMODEL_GetModelAnimDefs(out[0]);
    cnt = FIELD_BUILDMODEL_CountAnimResources((int *)t);
    for (i = 0; i < 4; i++) {
        if (i < cnt) {
            out[2 + i] = func_02030734(((struct Obj09454 *)s)->f0, G3D_SYSTEM_GetResourceSize(), 1, gBuildModelFileName, 0x4db);
            G3D_SYSTEM_InitResourceByFile(out[2 + i], (u32 *)FIELD_BUILDMODEL_GetAnimResourceData(t, i));
        } else {
            out[2 + i] = 0;
        }
    }
}
