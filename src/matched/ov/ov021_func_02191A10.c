/*
 * function: func_02191A10
 * address:  0x02191A10
 * packet:   pkt_ov021_02191A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DDA50     0x021DDA50  data  a4
 *   func_02030734  0x02030734  arm
 *   func_02040618  0x02040618  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043678  0x02043678  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02191D88  0x02191D88  thumb  ov021
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02191DC8  0x02191DC8  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_02043678(u32 a, u32 b, u32 c, u32 d);
struct Descriptor;
extern void *func_02045770(struct Descriptor *w);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045374(u32 w);
extern void func_02045334(u32 w);
extern void func_02191D88(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02045758(u32 w);
extern u32 func_02045760(u32 w);
extern u32 func_02045738(u32 w);
extern u32 func_02045740(u32 w);
extern void func_02191DC8(u32 layer, u32 x, u32 y, u32 w, u32 h, u32 tile, u32 pal);
extern void func_020409B4(u32 layer);
extern void func_021927C0(u32 *p, u16 *a);
extern void func_02193044(u32 a);

u32 *func_02191A10(u16 *a, u32 b, u32 c)
{
    u32 *p;
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    p = (u32 *)func_02030734(a[0], 0x34, 1, d_021DDA50, 0xee0);
    p[0] = (u32)a;
    p[12] = c;
    p[7] = -48;
    func_02040618((u8)a[1], 0, 0);
    func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
    p[1] = func_020450F0((u8)a[1], 2, 0x13, 0x1c, 4, 9, 1);
    p[2] = func_02043678(0x1c, 4, 0x20, a[0]);
    p[3] = func_02043678(0x1c, 4, 0x20, a[0]);
    func_02043B5C((u32)func_02045770((struct Descriptor *)p[1]), 15);
    func_02045374(p[1]);
    func_02045334(p[1]);
    func_02191D88(a[1], 9, b, a[0]);
    x = func_02045758(p[1]);
    y = func_02045760(p[1]);
    w = func_02045738(p[1]);
    h = func_02045740(p[1]);
    func_02191DC8((u8)a[1], x, y, w, h, 0x33, 9);
    func_020409B4((u8)a[1]);
    func_021927C0(p + 10, (u16 *)p[0]);
    a[3] = 11;
    func_02193044(0);
    return p;
}
