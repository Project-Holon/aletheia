/*
 * function: FIELD_BUILDMODEL_CreateNodeFromEntry
 * address:  0x0218C724
 * packet:   pkt_ov021_0218C724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x60-byte node for a definition, builds its matrices, registers it.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0207AF1C  0x0207AF1C  thumb
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   FIELD_G3D_MAPPER_GetOriginOffset  0x0218DC5C  thumb  ov021
 *   FIELD_BUILDMODEL_InitAnimSet  0x0218BFB4  thumb  ov021
 *   FIELD_BUILDMODEL_AddNode  0x0218BA70  thumb  ov021
 *   FIELD_BUILDMODEL_SwapEntryModelId  0x0218C54C  thumb  ov021
 *   gBuildModelFileName     0x021DD9CC  data   ov021  a4
 *   FX_SinCosTable_     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04199.h"
#include "../include/Obj04200.h"
#include "../include/Obj12576.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0207AF1C(void *m, int a, int b);
struct V3;
extern void FIELD_G3D_MAP_GetPos(u8 *src, struct V3 *dst);
extern void func_0207C9D0(void *a, void *b, void *c);
extern void FIELD_G3D_MAPPER_GetOriginOffset(u32 a, void *b);
extern void FIELD_BUILDMODEL_InitAnimSet(u8 *a, u32 *out, u32 *st);
extern void FIELD_BUILDMODEL_AddNode(u8 *owner, u8 *node);
extern void FIELD_BUILDMODEL_SwapEntryModelId(u32 a, int b);
extern s16 FX_SinCosTable_[];
extern u8 gBuildModelFileName[];

u8 *FIELD_BUILDMODEL_CreateNodeFromEntry(u8 *owner, u32 *obj)
{
    u8 *def = (u8 *)obj[3];
    u8 *p;
    u32 tmp[3];
    int k;

    p = func_02030734(((struct Obj04199 *)owner)->f0, 0x60, 0, (const char *)gBuildModelFileName, 0x7E9);
    *(u8 * *)&((struct Obj04200 *)p)->f0 = owner;
    *(u32 * *)&((struct Obj04200 *)p)->f8 = obj;
    ((struct Obj04200 *)p)->f4 = 0xFFFF;
    k = ((struct Obj12576 *)def)->f10 >> 4;
    func_0207AF1C(p + 0x3C, FX_SinCosTable_[k * 2], FX_SinCosTable_[k * 2 + 1]);
    FIELD_G3D_MAP_GetPos((u8 *)obj[0], (struct V3 *)(p + 0x24));
    func_0207C9D0(p + 0x24, def + 4, p + 0x24);
    FIELD_G3D_MAPPER_GetOriginOffset(((struct Obj04199 *)owner)->f4, tmp);
    func_0207C9D0(p + 0x24, tmp, p + 0x24);
    ((struct Obj04200 *)p)->f30 = 0x1000;
    ((struct Obj04200 *)p)->f34 = 0x1000;
    ((struct Obj04200 *)p)->f38 = 0x1000;
    FIELD_BUILDMODEL_InitAnimSet(owner, (u32 *)(p + 0xC), (u32 *)(*(u8 * *)&((struct Obj04199 *)owner)->f1CC + ((struct Obj12576 *)def)->f0 * 0x18));
    FIELD_BUILDMODEL_AddNode(owner, p);
    FIELD_BUILDMODEL_SwapEntryModelId(*(u32 *)&((struct Obj04200 *)p)->f8, 0);
    return p;
}
