/*
 * function: func_021C53A0
 * address:  0x021C53A0
 * packet:   pkt_ov021_021C53A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021C58CC  0x021C58CC  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern void func_02082BCC(void *p, int v, int n);
typedef unsigned int   u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_021C58CC(char *p, u16 a, u16 b, u32 heap);

void func_021C53A0(int *a, const u16 *b, int c, int d, int e, int f, int *g, u16 h)
{
    int i = 0;
    int r;

    func_02082BCC(a, 0, 0x4c);
    a[3] = e;
    a[8] = f;
    *(u16 *)((char *)a + 0x34) = h;
    a[0xe] = c;
    a[0xf] = d;
    for (i = 0; i < 3; i++) {
        a[0xa + i] = g[i];
    }
    r = func_020450F0(1, 1, 0xc, 0x1e, 0xc, 0xb, 1);
    a[2] = r;
    func_02045334((struct Descriptor *)r);
    func_02045374((struct Cfg *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    a[4] = a[2];
    *(u8 *)(a + 5) = 0;
    func_021C58CC((char *)a, b[0], b[1], h);
}
