/*
 * function: func_0220C4D4
 * address:  0x0220C4D4
 * packet:   pkt_0220C4D4
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 */

struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
typedef unsigned int   u32;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_0220C4D4(int a, int b)
{
    func_0204B3DC((struct Obj *)a, 1);
    func_0204B404((struct Obj *)a, (const struct Vec2 *)b, 1);
}
