/*
 * function: FIELD_G3D_MAPPER_Create
 * address:  0x0218C9E8
 * packet:   pkt_ov021_0218C9E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gFieldG3dMapperSrcName     0x021DD9EC  data  ov021  a4
 *   FIELD_BUILDMODEL_Create  0x0218B754  thumb
 *   FIELD_WFBC_Create  0x021938AC  thumb ov021
 *   HEIGHT_EX_CreateTable  0x021C05D4  thumb ov021
 */
#include "../include/Obj01115.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern int gFieldG3dMapperSrcName;
extern int FIELD_BUILDMODEL_Create(int a, void *p, int b);
typedef unsigned int   u32;
extern void *FIELD_WFBC_Create(u32 heap);
extern int HEIGHT_EX_CreateTable(int a, int b);

char *FIELD_G3D_MAPPER_Create(int heap, int b)
{
    char *p = func_02030734(heap, 0x74, 1, (const char *)&gFieldG3dMapperSrcName, 0xf9);
    int z = 0;
    ((struct Obj01115 *)p)->f0 = heap;
    ((struct Obj01115 *)p)->f34 = z;
    ((struct Obj01115 *)p)->f38 = z;
    ((struct Obj01115 *)p)->f3C = z;
    ((struct Obj01115 *)p)->f14 = z;
    ((struct Obj01115 *)p)->f16 = z;
    ((struct Obj01115 *)p)->f18 = z;
    ((struct Obj01115 *)p)->f1C = z;
    ((struct Obj01115 *)p)->f4 = z;
    ((struct Obj01115 *)p)->f8 = z;
    ((struct Obj01115 *)p)->fC = 1;
    ((struct Obj01115 *)p)->f10 = -1;
    ((struct Obj01115 *)p)->f40 = z;
    ((struct Obj01115 *)p)->f68 = z;
    ((struct Obj01115 *)p)->f64 = FIELD_BUILDMODEL_Create(((struct Obj01115 *)p)->f0, p, b);
    ((struct Obj01115 *)p)->f6C = (int)FIELD_WFBC_Create(heap);
    ((struct Obj01115 *)p)->f70 = HEIGHT_EX_CreateTable(0x10, (u8)heap);
    return p;
}
