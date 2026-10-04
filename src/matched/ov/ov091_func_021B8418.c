/*
 * function: func_021B8418
 * address:  0x021B8418
 * packet:   pkt_ov091_021B8418
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The extent's last two bytes are alignment padding (00 00), not a follower.
 *
 * symbols:
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern int func_021B9A84(u32 p);
extern int func_021B9AB4(u8 *p);
extern void func_021BBE5C(int h, int f);
extern void func_021B8F68(u8 *p, int v);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

#define W(o) (*(int *)(p + (o)))

void func_021B8418(u8 *p)
{
    W(0x2c) = *(int *)(W(0x280) + 0x3c);
    p[0xe] = 0;
    W(0x3c) = 0x17;
    if (func_021B9A84((u32)p) == 1) {
        func_021BBE5C(W(0x108), 0);
        func_021BBE5C(W(0x10c), 0);
    }
    if (W(8) == 0) {
        if (W(0x2c) <= 5) {
            func_021B8F68(p, W(0x2c));
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
        } else {
            func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
        }
    } else {
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        if (W(0x2c) <= 5) {
            if (p[0xc] == 3) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            }
        } else {
            func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 0);
        }
    }
    func_0204B3DC((struct Obj *)W(0x1e4), W(0x14));
    if (func_021B9A84((u32)p) == 1 || func_021B9AB4(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
}
