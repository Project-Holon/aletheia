/*
 * function: func_021E0BE8
 * address:  0x021E0BE8
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E0BE8   0x021E0BE8  thumb ov093
 *   func_021C815C   0x021C815C  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021B9A24   0x021B9A24  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   func_021C830C   0x021C830C  thumb ov093
 *   func_021C8290   0x021C8290  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *
 * Six rejections in a row (func_021C815C(b) zero or 3, func_021B9A24(c,k),
 * func_021D775C(0x12) == 0x1fb, func_021D62C4(r,0x21), func_021C830C(b),
 * func_021C8290(b,k,c,(u16)func_021D775C(0x12))) before func_021D76BC(4, c).
 * The 0x1fb is the image's own pool constant.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021C815C(int a);
int func_021D775C(int a);
void *func_021C7CF4(int a, int b);
struct Unk021D62A8;
int func_021B9A24(unsigned int a, unsigned int b);
int func_021D62C4(struct Unk021D62A8 *p, int i);
int func_021C830C(int a);
int func_021C8290(int a, int k, int c, int t);
int func_021D76BC(int key, u32 val);

void func_021E0BE8(void *a, int b, int c)
{
    void *r;
    u8 k;
    u16 t;

    if (func_021C815C(b) == 0)
        return;
    if (func_021C815C(b) == 3)
        return;
    k = (u8)func_021D775C(3);
    r = func_021C7CF4(b, c);
    if (func_021B9A24(c, k) != 0)
        return;
    if (func_021D775C(0x12) == 0x1fb)
        return;
    if (func_021D62C4(r, 0x21) != 0)
        return;
    if (func_021C830C(b) != 0)
        return;
    t = (u16)func_021D775C(0x12);
    if (func_021C8290(b, k, c, t) != 0)
        return;
    func_021D76BC(4, c);
}
