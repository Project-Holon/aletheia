/*
 * function: ov208_func_021C535C
 * address:  0x021C535C
 * packet:   pkt_ov208_021C535C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B688  0x0204B688  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u8  b6;
    u8  b7;
} Ov208ObjPos;

extern u32  func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32  func_0204A6C8(u32 a, u32 b, u32 c, u32 d, u32 heap);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int res, unsigned int j, unsigned int k, const void *pos, unsigned short f, unsigned short heap);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern u32  func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void func_0204B6F4(u32 obj, u32 v, u32 flag);
extern void func_0204B688(u32 obj, u32 v);

u32 ov208_func_021C535C(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                        u32 form, u32 gender, u32 isEgg)
{
    Ov208ObjPos pos;
    u32 obj;

    pos.x = 0x80;
    pos.y = 0x80;
    pos.z = 1;
    pos.b6 = 1;
    pos.b7 = 0;
    *res = func_0204A6C8(arc, func_0201BABC(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)func_0204B294((void *)owner, *res, j, k, &pos, 1, heap);
    func_0204B92C((struct Obj *)obj, 0);
    func_0204B6F4(obj, func_0201BB5C(species, form, gender, isEgg), 0);
    func_0204B688(obj, 0);
    return obj;
}
