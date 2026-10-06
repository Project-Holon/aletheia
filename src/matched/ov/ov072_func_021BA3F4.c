/*
 * function: func_021BA3F4
 * address:  0x021BA3F4
 * packet:   pkt_ov072_021BA3F4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B9A0  0x0204B9A0  arm
 */

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} Pos;

struct Actor;
extern int func_021BA774(char *p, int i);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
typedef unsigned int   u32;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B9A0(struct Actor *a);

void func_021BA3F4(int *p, int a, int *b)
{
    Pos pos;

    if (a == 0) {
        func_0204B3DC((struct Obj *)p[1], 0);
        p[5] = 0;
        return;
    }
    if (p[5] != a) {
        pos.x = b[0] + func_021BA774((char *)a, 4);
        pos.y = b[1] + func_021BA774((char *)a, 5);
        func_0204B404((struct Obj *)p[1], (const struct Vec2 *)(&pos), 0);
        func_0204B3DC((struct Obj *)p[1], 1);
        func_0204B9A0((struct Actor *)p[1]);
        p[5] = a;
    }
}
