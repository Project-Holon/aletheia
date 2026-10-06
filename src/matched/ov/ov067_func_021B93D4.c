/*
 * unit:     yes
 * function: func_021B93D4, func_021B940C, func_021B941C
 * address:  0x021B93D4
 * packet:   pkt_ov067_021B93D4
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The handed 460-byte extent is this 56-byte function, two unlabelled
 * 16-byte tail-call stubs into func_021B92F0 (0x021B940C, 0x021B941C), and
 * rodata from 0x021B942C on. tu reproduces 0x021B93D4..0x021B942C.
 *
 * symbols:
 *   func_021B92F0  0x021B92F0  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ops {
    void *f0;
    void (*f4)(void *obj, int pos, int flag);
};

struct S {
    u8 _0[0x20];
    struct Ops *f20;
    void *f24;
    u8 _28[0x5c - 0x28];
    s16 f5c;
    u8 _5e[0x60 - 0x5e];
    s16 f60;
    s16 f62;
};

extern void func_021B92F0(struct S *p, u32 a1, u32 a2);

void func_021B93D4(struct S *s, int v)
{
    s->f60 = s->f5c;
    s->f5c = v;
    func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
    s->f20->f4(s->f24, s->f5c + s->f62, 1);
}

void func_021B940C(struct S *s)
{
    func_021B92F0(s, (u16)s->f5c, (u16)0xff);
}

void func_021B941C(struct S *s)
{
    func_021B92F0(s, (u16)0xff, (u16)s->f5c);
}
