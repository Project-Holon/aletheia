/*
 * function: func_02192628
 * address:  0x02192628
 * packet:   pkt_ov021_02192628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020456F8  0x020456F8  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02041300  0x02041300  arm
 *   func_02045334  0x02045334  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_020437AC  0x020437AC  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
struct Obj020437AC;
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
struct Descriptor;
extern void func_02045334(struct Descriptor *w);
extern void func_020409B4(u32 layer);
extern void func_021927E8(u32 *p);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *p);

void func_02192628(u32 *a)
{
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    func_020456F8((struct Descriptor *)a[0]);
    x = func_02045758((struct Descriptor *)a[0]);
    y = func_02045760((struct Descriptor *)a[0]);
    w = func_02045738((struct Descriptor *)a[0]);
    h = func_02045740((struct Descriptor *)a[0]);
    func_02041300((u8)((u16 *)a[2])[1], 0, x, y, w, h, 0x11);
    func_02045334((struct Descriptor *)a[0]);
    func_020409B4((u8)((u16 *)a[2])[1]);
    func_021927E8(a + 4);
    func_020437AC((struct Obj020437AC *)a[3]);
    func_020452E8((struct Descriptor *)a[0]);
    func_020307B0(a);
}
