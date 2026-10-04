/*
 * function: func_021B8FC4
 * address:  0x021B8FC4
 * packet:   pkt_ov091_021B8FC4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB3D4  0x021BB3D4  thumb  ov091
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char u8;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_021BB3D4(void *a, u8 *s, u16 *out);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B84C(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);

#define W(o) (*(int *)(p + (o)))

void func_021B8FC4(u8 *p, int idx)
{
    int buf;

    func_021BB3D4(p, (u8 *)(*(int *)(p + idx * 4 + 0x160)), (u16 *)(&buf));
    func_0204B404((struct Obj *)W(0x1dc), (const struct Vec2 *)(&buf), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 1);
    func_0204B84C(W(0x1dc), 2);
    if (idx == 0) {
        func_0204B878((struct Obj *)W(0x1dc), 2);
    } else {
        func_0204B878((struct Obj *)W(0x1dc), 3);
    }
}
