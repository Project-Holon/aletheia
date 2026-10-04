/*
 * function: func_021B7070
 * address:  0x021B7070
 * packet:   pkt_ov071_021B7070
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021BA84C     0x021BA84C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

extern int func_0204B294(int, int, int, int, Rect *, int, int);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern const Rect d_021BA84C;

void func_021B7070(int *p, int *out)
{
    Rect r;
    int h;

    r = d_021BA84C;
    h = func_0204B294(p[0x14 / 4], p[0x54 / 4], p[0x50 / 4], p[0x58 / 4], &r, 1, 0x61);
    func_0204B92C((struct Obj *)h, 1);
    *out = h;
}
