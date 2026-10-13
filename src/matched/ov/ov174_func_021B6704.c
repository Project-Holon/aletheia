/*
 * function: func_021B6704
 * address: 0x021B6704
 * packet: pkt_ov174_021B6704
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: assign the getter result to width before dividing it; the combined call/divide swaps table and stack-address registers. Named x/y alone stayed DIFF12; split-assign(width) reached EXACT.
 * symbols:
 *   func_021B7360 0x021B7360 thumb ov174
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern unsigned func_021B7360(unsigned char *p);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern const u8 d_021B7380[][2];
void func_021B6704(u8 *p, int index)
{
    u16 point[2];
    unsigned width;
    unsigned x;
    unsigned y;
    width = func_021B7360(*((void **) ((p + 28) + (index * 4))));
    width = width / 2;
    x = ((d_021B7380[index][0] * 8) + 80) + width;
    point[0] = x;
    y = (d_021B7380[index][1] * 8) + 16;
    point[1] = y;
    func_0204B404(*((void **) (p + 84)), (const struct Vec2 *)point, 0);
    func_0204B3DC(*((void **) (p + 84)), 1);
    CLACT_RestartActorAnim(*((void **) (p + 84)));
}
