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
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct { unsigned short x, y; } Pos;
typedef unsigned int   u32;
extern u32 func_021BC720(void *p, u32 i);
extern void func_0204B404(int obj, Pos *pos, int c);
struct Obj;
extern void func_0204B3DC(struct Obj *a, unsigned int b);

void func_021BD588(void *p)
{
    int obj = func_021BC720(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    func_0204B404(obj, &pos, 0);
    func_0204B3DC((struct Obj *)obj, 1);
}
