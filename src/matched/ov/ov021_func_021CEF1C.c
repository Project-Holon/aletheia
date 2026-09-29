/*
 * function: func_021CEF1C
 * address:  0x021CEF1C
 * packet:   pkt_ov021_021CEF1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   func_02190A6C  0x02190A6C  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02008534  0x02008534  thumb
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_02045808  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x26];
    u8 on;
    u8 pad27[5];
} Ent;

typedef struct {
    u32 f0, f4, f8;
    u8 padc[0x13c - 0xc];
    u32 f13c;
    u32 f140;
    Ent ents[16];
    u8 pad404[0x40e - 0x404];
    u8 f40e;
    u8 pad40f[0x528 - 0x40f];
    u16 f528;
} S;

extern u16 func_02045A98(void);
extern void func_02190A6C(u32 a);
extern u32 func_020457B0(u32 n, u32 heap);
extern void func_02045CAC(u32 a, u32 b, u32 c);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F02C(u32 a, u32 b, void *c);
extern u32 func_02008534(void *a);
extern void func_02045924(u32 s, u16 *str);
extern void func_0201EE0C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(u32 a);

void func_021CEF1C(S *p)
{
    u16 ch;
    u32 c, a, b, d;
    int i;

    ch = func_02045A98();
    if (p->f40e == 1) {
        func_02190A6C(p->f13c);
    }
    a = func_020457B0(0x40, p->f528);
    b = func_020457B0(0x40, p->f528);
    c = func_020457B0(0x40, p->f528);
    d = func_020457B0(4, p->f528);
    func_02045CAC(p->f8, 0x1a, a);
    func_02045CAC(p->f8, 0x1b, b);
    for (i = 0; i < 16; i++) {
        func_0201EFA4(p->f4, 0, i + 1, 2, 2, 1);
        if (p->ents[i].on == 1) {
            func_0201F02C(p->f4, 1, &p->ents[i]);
            func_0201EFA4(p->f4, 2, func_02008534(&p->ents[i]), 5, 2, 1);
            func_0201F250(p->f4, c, b);
        } else {
            func_02045924(d, &ch);
            func_0201EE0C(p->f4, 1, d, 0, 1, 2);
            func_0201EE0C(p->f4, 2, d, 0, 1, 2);
            func_0201F250(p->f4, c, a);
        }
        func_02190A64(p->f13c, c, i, p->f528);
    }
    func_02045808(b);
    func_02045808(a);
    func_02045808(c);
    func_02045808(d);
    p->f40e = 1;
}
