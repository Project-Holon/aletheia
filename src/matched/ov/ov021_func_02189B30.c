/*
 * function: FIELDMAP_SetupMapperParam
 * address:  0x02189B30
 * packet:   pkt_ov021_02189B30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMapType  0x02189B28  thumb  ov021
 *   MAP_MATRIX_GetWidth  0x02159BF4  thumb  ov010
 *   MAP_MATRIX_GetHeight  0x02159BF8  thumb  ov010
 *   MAP_MATRIX_GetCount  0x02159BFC  thumb  ov010
 *   MAP_MATRIX_GetMapGrid  0x02159C20  thumb  ov010
 *   func_020140BC  0x020140BC  thumb
 *   func_020140C0  0x020140C0  thumb
 *   func_020140CC  0x020140CC  thumb
 *   sMapTypeTable     0x021D3700  data  a4
 */
#include "../include/Obj03106.h"

typedef struct Rec { int w[15]; } Rec;
typedef struct Ent { Rec r; int f3c; int f40; int f44; } Ent;

extern Ent sMapTypeTable[];
extern unsigned int FIELDMAP_GetMapType(unsigned int a);
struct Obj;
extern unsigned short MAP_MATRIX_GetWidth(struct Obj *p);
extern unsigned short MAP_MATRIX_GetHeight(struct Obj *p);
extern int MAP_MATRIX_GetCount(struct Obj *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sub020140BCObj;
extern char *MAP_MATRIX_GetMapGrid(char *p);
extern u16 func_020140BC(struct Sub020140BCObj *p);
extern u32 func_020140C0(struct Sub020140BCObj *p);
extern u32 func_020140CC(struct Sub020140BCObj *p);

void FIELDMAP_SetupMapperParam(int a, int x, char *out, void *obj)
{
    int i = (int)FIELDMAP_GetMapType((unsigned int)a);

    *(Rec *)out = sMapTypeTable[i].r;
    if (sMapTypeTable[i].f40 != 0) {
        ((struct Obj03106 *)out)->f14 = MAP_MATRIX_GetWidth(obj);
        ((struct Obj03106 *)out)->f16 = MAP_MATRIX_GetHeight(obj);
        ((struct Obj03106 *)out)->f18 = MAP_MATRIX_GetCount(obj);
        ((struct Obj03106 *)out)->f1C = (int)MAP_MATRIX_GetMapGrid(obj);
    }
    ((struct Obj03106 *)out)->f20 = 1;
    ((struct Obj03106 *)out)->f24 = 0xe;
    ((struct Obj03106 *)out)->f28 = func_020140BC((struct Sub020140BCObj *)x);
    ((struct Obj03106 *)out)->f2C = func_020140C0((struct Sub020140BCObj *)x);
    ((struct Obj03106 *)out)->f30 = func_020140CC((struct Sub020140BCObj *)x);
}
