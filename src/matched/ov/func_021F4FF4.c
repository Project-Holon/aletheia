/*
 * function: func_021F4FF4
 * address:  0x021F4FF4
 * packet:   pkt_021F4FF4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_AddActorSurfacePos  0x0204B404  arm

 *
 * Same one-entry u16 table send, with count 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_021F4FF4(u32 a, u32 b, u32 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    CLACT_AddActorSurfacePos((struct Obj *)a, (const struct Vec2 *)t, 0);
}
