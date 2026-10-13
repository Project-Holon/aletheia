/*
 * function: func_021BD588
 * address:  0x021BD588
 * packet:   pkt_ov217_021BD588
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BC720  0x021BC720  thumb  ov217
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct { unsigned short x, y; } Pos;
typedef unsigned int   u32;
extern u32 func_021BC720(void *p, u32 i);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

void func_021BD588(void *p)
{
    int obj = func_021BC720(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    CLACT_AddActorSurfacePos((struct Obj *)obj, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorDrawEnable((struct Obj *)obj, 1);
}
