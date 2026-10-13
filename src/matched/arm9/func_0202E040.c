/*
 * unit:     no
 * function: PMS_DRAW_PlaceDecoActor
 * address:  0x0202E040
 * packet:   pkt_0202DFEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Places one element sprite: sub_0202DE6C resolves the cell offset into a
 * pair of u32s, which are narrowed into the adjacent u16 pair the
 * CLACT_AddActorSurfacePos setter wants, then the cell's own id decides the priority
 * word through sub_0202E430 and the last stack argument (a 1-based index)
 * is passed on as `(u16)(n - 1)`.
 *
 * symbols:
 *   sub_0202DE6C   0x0202DE6C  thumb
 *   sub_0202E430   0x0202E430  thumb
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020416D4  0x020416D4  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Pos { u32 x; u32 y; };
struct Pt  { u16 x; u16 y; };

struct Pos0202DE6C;
extern void sub_0202DE6C(u32 a, u32 b, u32 c, const struct Pos0202DE6C *base, struct Pos0202DE6C *out);
extern u32   sub_0202E430(u32 id);
struct Descriptor;
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned char  u8;
struct Obj;
extern u8 func_020416D4(u32 layer);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void  CLACT_SetActorBgPriority(void *h, u32 a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void PMS_DRAW_PlaceDecoActor(void *h, struct Descriptor *cell, u32 b, u32 c,
                   u32 n, const struct Pos *base)
{
    struct Pos pos;
    struct Pt pt;
    u32 t;

    sub_0202DE6C((u32)cell, b, c, (const struct Pos0202DE6C *)base, (struct Pos0202DE6C *)(&pos));
    pt.x = (u16)pos.x;
    pt.y = (u16)pos.y;
    t = BMP_WIN_GetBgLayer(cell);
    CLACT_AddActorSurfacePos(h, (const struct Vec2 *)(&pt), (u16)sub_0202E430(t));
    CLACT_SetActorBgPriority(h, func_020416D4(t));
    CLACT_SetActorAnimSeq(h, (u16)(n - 1));
}
