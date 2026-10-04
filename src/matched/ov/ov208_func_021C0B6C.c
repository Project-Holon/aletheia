/*
 * function: func_021C0B6C
 * address:  0x021C0B6C
 * packet:   pkt_ov208_021C0B6C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B688  0x0204B688  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

extern void *func_020490F4(unsigned int id, u16 heap);
extern u32  func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32  func_0204B294(u32 res, u32 a, u32 b, u32 c, ObjPos *pos, u16 f, u16 heap);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32  func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void func_0204B6F4(u32 obj, u32 v, u32 flag);
extern void func_0204B688(u32 obj, u32 on);
extern void func_02049238(void *h);

u32 func_021C0B6C(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form,
                  u32 gender, u32 isEgg, u8 x, u8 y)
{
    ObjPos pos;
    void *h;
    u32 obj;

    h = func_020490F4(7, heap);
    pos.x = x;
    pos.y = y;
    pos.z = 1;
    pos.pri = 1;
    pos.f7 = 0;
    *slot = func_0204A6C8(h, func_0201BABC(species, form, gender, isEgg), 0, 1, heap);
    obj = func_0204B294(res, *slot, a, b, &pos, 1, heap);
    func_0204B92C((struct Obj *)obj, 0);
    func_0204B6F4(obj, func_0201BB5C(species, form, gender, isEgg), 0);
    func_0204B688(obj, 0);
    func_02049238(h);
    return obj;
}
