/*
 * function: func_021B9FC8
 * address: 0x021B9FC8
 * packet: pkt_ov069_021B9FC8
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * symbols:
 *   func_0202616C 0x0202616C thumb
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Point { u16 x, y; } Point;
extern u8 *func_0202616C(void *p, int i);
extern void func_0204B404(void *cell, Point *pt, u16 flags);
void func_021B9FC8(char *p, int i)
{
    Point pt;
    u8 *v;
    v = func_0202616C(*(void **)(p + 0x14C), i);
    pt.x = v[0];
    pt.y = v[1];
    func_0204B404(*(void **)(p + 0x124), &pt, 0);
}
