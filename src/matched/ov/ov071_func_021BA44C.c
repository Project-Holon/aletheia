/*
 * function: func_021BA44C
 * address:  0x021BA44C
 * packet:   pkt_ov071_021BA44C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char u8;

typedef struct {
    int h[3];
    struct {
        int h;
        u8 on;
        u8 pad[3];
    } e[3];
} S;

typedef unsigned int   u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(unsigned int index);

void func_021BA44C(int a, S *p)
{
    int i;

    p->h[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(0, 2, 4, 0x1c, 8, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    p->h[2] = func_020450F0(0, 2, 0xf, 0x1c, 9, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[2]);
    func_02045374((struct Cfg *)p->h[2]);
    for (i = 0; i < 3; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}
