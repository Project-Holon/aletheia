/*
 * unit:     no
 * function: func_0202E040
 * address:  0x0202E040
 * packet:   pkt_0202DFEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Places one element sprite: sub_0202DE6C resolves the cell offset into a
 * pair of u32s, which are narrowed into the adjacent u16 pair the
 * func_0204B404 setter wants, then the cell's own id decides the priority
 * word through sub_0202E430 and the last stack argument (a 1-based index)
 * is passed on as `(u16)(n - 1)`.
 *
 * symbols:
 *   sub_0202DE6C   0x0202DE6C  thumb
 *   sub_0202E430   0x0202E430  thumb
 *   func_02045730  0x02045730  arm
 *   func_020416D4  0x020416D4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Pos { u32 x; u32 y; };
struct Pt  { u16 x; u16 y; };

extern void  sub_0202DE6C(u32 a, u32 b, u32 c, const struct Pos *base,
                          struct Pos *out);
extern u32   sub_0202E430(u32 id);
extern u32   func_02045730(u32 cell);
typedef unsigned char  u8;
struct Obj;
extern u8 func_020416D4(u32 layer);
extern void  func_0204B404(void *h, struct Pt *p, u16 v);
extern void  func_0204B84C(void *h, u32 a);
extern void func_0204B878(struct Obj *p, u16 value);

void func_0202E040(void *h, u32 cell, u32 b, u32 c,
                   u32 n, const struct Pos *base)
{
    struct Pos pos;
    struct Pt pt;
    u32 t;

    sub_0202DE6C(cell, b, c, base, &pos);
    pt.x = (u16)pos.x;
    pt.y = (u16)pos.y;
    t = func_02045730(cell);
    func_0204B404(h, &pt, (u16)sub_0202E430(t));
    func_0204B84C(h, func_020416D4(t));
    func_0204B878(h, (u16)(n - 1));
}
