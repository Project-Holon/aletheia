/*
 * function: func_021AA0A0
 * address:  0x021AA0A0
 * packet:   pkt_ov021_021AA0A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_02188C6C  0x02188C6C  thumb
 *   func_021A1BF4  0x021A1BF4  thumb
 *   func_021A9350  0x021A9350  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02013090  0x02013090  thumb
 *   func_021AA490  0x021AA490  thumb
 *   func_02013144  0x02013144  thumb
 *   func_0216E7C8  0x0216E7C8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 pad8[8];
    u8 b10;
    u8 pad11[0x17];
} Opts;

typedef struct {
    u8 b[0x2c];
} Buf;

typedef struct {
    int f0;
    int f4;
    int f8;
} S;

extern void func_02188CB4(int a);
extern int func_02188C6C(int a);
extern int func_021A1BF4(int a);
extern void func_021A9350(Buf *buf, int a, int b, int c, int d);
extern void func_02082BCC(void *p, int v, int n);
extern int func_02013090(int a);
extern void func_021AA490(S *s, Buf *buf, int h, int n, Opts *o);
extern void func_02013144(int h, int v);
extern void func_0216E7C8(int a, int b, int h, int c, int d);

void func_021AA0A0(S *s, u16 a, u8 b, u32 flags)
{
    Opts opts;
    Buf buf;
    int h;
    Opts *o;

    func_02188CB4(s->f0);
    func_021A9350(&buf, s->f8, 0xff, 0, func_021A1BF4(func_02188C6C(s->f0)));
    o = &opts;
    func_02082BCC(o, 0, 0x28);
    opts.h0 = a;
    o->b4 = b;
    if (flags & 4) {
        o->h2 = 0xffff;
    }
    if (flags & 2) {
        o->b6 = 1;
    } else if (flags & 0x10) {
        o->b6 = 2;
    } else {
        o->b6 = 0;
    }
    if (flags & 8) {
        o->b7 = 1;
    }
    if (flags & 0x20) {
        o->b10 = 1;
    } else if (flags & 0x40) {
        o->b10 = 2;
    }
    h = func_02013090(4);
    func_021AA490(s, &buf, h, 4, &opts);
    if (flags & 1) {
        func_02013144(h, 4);
    } else if (flags & 0x80) {
        func_02013144(h, 0x80);
    }
    if (flags & 0x100) {
        func_02013144(h, 0x200);
    }
    func_0216E7C8(s->f4, s->f0, h, 1, 0);
}
