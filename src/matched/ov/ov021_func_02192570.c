/*
 * function: func_02192570
 * address:  0x02192570
 * packet:   pkt_ov021_02192570
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
 *   func_020450F0  0x020450F0  arm
 *   func_02043678  0x02043678  arm
 *   func_02045770  0x02045770  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02192264  0x02192264  thumb  ov021
 *   func_021922A4  0x021922A4  thumb  ov021
 *   func_02192244  0x02192244  thumb  ov021
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
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Bmp;
struct Cfg;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *w);
extern void func_02192264(u32 a, u32 b, u32 c, u32 d);
extern void func_021922A4(u32 a, u32 b, u32 c);
extern void func_02192244(u32 a, u32 b, u32 c);
extern void func_020409B4(u32 layer);
struct Fx;
struct G;
extern void func_021927C0(struct G *g, struct Fx *a);
extern void func_02193044(u32 a);

u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f)
{
    u32 *t;

    t = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0x115D);
    t[2] = (u32)a;
    t[0] = func_020450F0((u8)a[1], (u8)c, (u8)d, (u8)e, (u8)f, 9, 1);
    t[3] = (u32)func_02043678(1, 1, 0x20, *a);
    func_02192264(t[3], b, *a, 9);
    func_021922A4((u32)func_02045770((struct Descriptor *)t[0]), b, *a);
    func_02192244(a[1], 9, *a);
    func_02045374((struct Cfg *)t[0]);
    func_02045334((struct Descriptor *)t[0]);
    func_020409B4((u8)a[1]);
    func_021927C0((struct G *)(t + 4), (struct Fx *)a);
    a[3] = 0xB;
    func_02193044(0);
    return t;
}
