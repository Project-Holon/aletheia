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

extern void func_021BB3D4(u8 *p, int v, int *buf);
extern void func_0204B404(int h, int *buf, int z);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B84C(int h, int f);
extern void func_0204B878(int h, int f);

#define W(o) (*(int *)(p + (o)))

void func_021B8FC4(u8 *p, int idx)
{
    int buf;

    func_021BB3D4(p, *(int *)(p + idx * 4 + 0x160), &buf);
    func_0204B404(W(0x1dc), &buf, 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 1);
    func_0204B84C(W(0x1dc), 2);
    if (idx == 0) {
        func_0204B878(W(0x1dc), 2);
    } else {
        func_0204B878(W(0x1dc), 3);
    }
}
