/*
 * function: func_021EF58C
 * address:  0x021EF58C
 * packet:   pkt_ov026_021EF58C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
extern void func_021A26C4(int, s16 *);
extern void func_0204B878(int, int);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B954(int, int);

void func_021EF58C(int a, s16 *b, s16 *c, int d)
{
    u32 r;
    s16 v[2];
    int one;

    r = func_020056EC(0);
    c[2] = r % 24 + 0x50;
    c[3] = r % 24 + 0xE;
    c[4] = c[2] + b[11];
    c[5] = c[3] + b[12];
    v[0] = (r & 7) - 8;
    v[1] = r % 160 - 16;
    func_021A26C4(a, v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    func_0204B878(d, 2);
    one = 1;
    func_0204B92C((struct Obj *)d, 1);
    func_0204B954(d, one << 13);
}
