/*
 * function: func_021B8C14
 * address:  0x021B8C14
 * packet:   pkt_ov067_021B8C14
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf following func_021B8B74 (inside its handed extent), called
 * by func_021B806C. The f54 value is a local read before the f70 store:
 * reading s->f54 inline at each store puts it in r2 instead of r3.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 _0[0x4e];
    u16 f4e;
    u8 _50[0x54 - 0x50];
    u32 f54;
    u8 _58[0x70 - 0x58];
    u32 f70;
    u8 _74[0x84 - 0x74];
    u8 f84;
    u8 f85;
    u8 f86 : 5;
    u8 f86_5 : 3;
    u8 f87;
    u8 _88[0x8c - 0x88];
    u32 f8c;
    u32 f90;
};

void func_021B8C14(struct S *s, u8 a)
{
    u32 v;

    s->f84 = 0;
    s->f87 = a;
    s->f86 = 0;
    v = s->f54;
    s->f70 = 0;
    s->f8c = v;
    s->f90 = v;
    s->f4e = 3;
}
