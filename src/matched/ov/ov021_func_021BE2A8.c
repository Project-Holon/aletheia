/*
 * function: FLD_EXP_OBJ_Create
 * address:  0x021BE2A8
 * packet:   pkt_ov021_021BE2A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFldExpObjFileName  0x021DE390  data
 *   func_02030734  0x02030734  arm
 *   G3D_UTIL_Create  0x02047CFC  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 heap;
    void *obj;
    unsigned char rest[0x40];
} Obj;

extern int sFldExpObjFileName;
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *G3D_UTIL_Create(u16, u16, u16);

Obj *FLD_EXP_OBJ_Create(u32 a, u32 b, u32 heap)
{
    Obj *o = func_02030734((u16)heap, sizeof(Obj), 1, (const char *)&sFldExpObjFileName, 0x4c);

    o->obj = G3D_UTIL_Create(a, b, heap);
    o->heap = heap;
    return o;
}
