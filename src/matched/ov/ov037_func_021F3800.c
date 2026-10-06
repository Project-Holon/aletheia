/*
 * function: func_021F3800
 * address:  0x021F3800
 * packet:   pkt_ov037_021F3800
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);

void func_021F3800(unsigned int a0)
{
    int *p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)a0)), 10);
    int *q;
    int *r;

    p[0] = 3;
    p[1] = 0;
    p[2] = 1;
    q = p + 3;
    q[0] = 1;
    q[1] = 1;
    q[2] = 1;
    r = p + 6;
    r[0] = 2;
    r[1] = 1;
    r[2] = 0;
}
