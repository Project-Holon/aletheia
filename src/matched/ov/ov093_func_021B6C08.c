/*
 * function: func_021B6C08
 * address:  0x021B6C08
 * packet:   pkt_ov093_021B6C08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021CD8E0  0x021CD8E0  thumb  ov093
 *   func_021B9674  0x021B9674  thumb  ov093
 *   func_021BAB5C  0x021BAB5C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10[4];
    u8 pad20[0xa8];
    u8 fc8[0xe8];
};

extern void func_021E9034(char *p);
extern void func_021CD8E0(u8 *p);
extern void func_021B9674(char *p);
extern void func_021BAB5C(int a);

int func_021B6C08(int a0, struct S *s)
{
    u32 i;

    if (s->f04 != 0) {
        func_021E9034((char *)s->f04);
        s->f04 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (s->f10[i] != 0) {
            func_021CD8E0((u8 *)s->f10[i]);
        }
    }
    func_021B9674((char *)((u8 *)s + 0xc8));
    func_021B9674((char *)((u8 *)s + 0x1b0));
    if (s->f08 != 0) {
        func_021BAB5C(s->f08);
    }
    if (s->f0c != 0) {
        func_021BAB5C(s->f0c);
    }
    return 1;
}
