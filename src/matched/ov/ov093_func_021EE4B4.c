/*
 * function: func_021EE4B4
 * address:  0x021EE4B4
 * packet:   pkt_ov093_021EE4B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D590C  0x021D590C  thumb  ov093
 *   func_021EF7AC  0x021EF7AC  thumb  ov093
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct C {
    u8 pad00[0x8];
    int f08;
    int f0c;
    u8 pad10[0x14];
    int f24;
    u8 pad28[0xc];
    int f34;
    u8 pad38[0x134];
    int f16c;
    u16 f170;
    u16 f172;
    u16 f174;
    u16 f176;
    u16 f178;
    u16 f17a;
    u16 f17c;
};

extern void func_021D590C(int a, void *b);
extern void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02043B5C(int a, int b);
extern void func_0201C7A4(int a, int b, int c, int d, int e);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_020061E4(u32 a);

int func_021EE4B4(int *st, struct C *c)
{
    switch (*st) {
    case 0:
        func_021D590C(c->f16c, &c->f170);
        func_021EF7AC(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        func_02043B5C(c->f0c, 12);
        func_0201C7A4(c->f0c, 0, 0, c->f34, c->f24);
        (*st)++;
        break;
    case 1:
        func_02045334((struct Descriptor *)c->f08);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
