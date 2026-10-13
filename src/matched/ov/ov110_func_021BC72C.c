/*
 * function: func_021BC72C
 * address: 0x021BC72C
 * packet: pkt_ov110_021BC72C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC578 0x021BC578 thumb ov110
 *   func_021BC69C 0x021BC69C thumb ov110
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Pt { s16 a, b, x, y; };
struct Obj;
struct Vec2;
extern void func_021BC578(const s16 *a, s16 *b);
extern void func_021BC69C(u8 *p, int flag);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BC72C(char *p, int i)
{
    struct Pt t;
    if (*(u32 *)(p + 0x44) != 0) {
        func_021BC578((const s16 *)(p + 0x38 + i * 4), (s16 *)(&t));
        t.x = t.a;
        t.y = t.b;
    } else {
        t.x = 0x80;
        t.y = 0x18;
    }
    CLACT_AddActorSurfacePos(*(void **)(p + 0x14), (const struct Vec2 *)(&t.x), 0);
    t.y += 0xC0;
    CLACT_AddActorSurfacePos(*(void **)(p + 0x18), (const struct Vec2 *)(&t.x), 1);
    func_021BC69C((u8 *)p, 1);
}
