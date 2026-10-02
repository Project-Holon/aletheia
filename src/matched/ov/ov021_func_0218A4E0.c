/*
 * function: func_0218A4E0
 * address:  0x0218A4E0
 * packet:   pkt_ov021_0218A4E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills the 0x40 byte field input record for one frame: pad trigger and held
 * keys, the held d-pad direction, the player object's position, facing and
 * movement state, and the request bitfield at 0x3C (talk on A, menu on X,
 * registered item on Y, no-input, step, surf and push flags).
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A2FE4  0x021A2FE4  thumb
 *   func_021A3080  0x021A3080  thumb
 *   func_021A308C  0x021A308C  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02014478  0x02014478  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021A3584  0x021A3584  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
    u32 trg;
    u32 cont;
    u16 dir;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
};

extern void func_02082BCC(void *p, int v, u32 n);
extern u16 func_02188C84(u8 *p);
extern void *func_020120F4(void *p);
extern void *func_02012844(void *p);
extern u16 func_02188C9C(u8 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void *func_02188CB4(u8 *p);
extern void func_021A2FE4(void *v);
extern u32 func_021A3080(void *v);
extern u32 func_021A308C(void *v);
extern void *func_021A3074(void *p);
extern u16 func_0216D5F8(void *p);
extern u32 func_0216D888(void *p);
extern void *func_02012B38(void *p);
extern u16 func_02014478(void *p);
extern u32 func_021A30C8(void *v);
extern int func_021A3584(void *v);

void func_0218A4E0(struct FieldInput *p, void *sys, u8 *pos)
{
    void *obj;

    func_02082BCC(p, 0, 0x40);
    p->f0 = func_02188C84(pos);
    p->sys = sys;
    p->f8 = func_020120F4(sys);
    p->fC = func_02012844(p->f8);
    p->f10 = func_02188C9C(pos);
    p->trg = func_020362DC();
    p->cont = func_0203630C();
    p->dir = 9;
    if (p->cont & 0x40)
        p->dir = 0;
    else if (p->cont & 0x80)
        p->dir = 1;
    else if (p->cont & 0x20)
        p->dir = 2;
    else if (p->cont & 0x10)
        p->dir = 3;
    p->pos = pos;
    p->f18 = func_02188CB4(pos);
    func_021A2FE4(p->f18);
    p->f20 = func_021A3080(p->f18);
    p->f1C = func_021A308C(p->f18);
    obj = func_021A3074(p->f18);
    p->f24 = func_0216D5F8(obj);
    p->f34 = func_0216D888(obj);
    p->f26 = func_02014478(func_02012B38(p->f8));
    p->f38 = func_021A30C8(p->f18);

    if (p->f1C == 3 || p->f1C == 0) {
        u8 n;

        p->b10 = 1;
        p->b0 = (p->trg & 1) ? 1 : 0;
        p->b1 = (p->trg & 0x400) ? 1 : 0;
        p->b6 = (p->trg & 0x800) ? 1 : 0;
        n = 0;
        n += p->b0;
        n += p->b1;
        n += p->b6;
        if (n == 0)
            p->b7 = 1;
    }
    p->b2 = 0;
    p->b9 = 0;
    if (p->f20 == 1)
        p->b2 = (p->f1C == 3) ? 1 : 0;
    if (func_021A3584(p->f18))
        p->b9 = 1;
    p->b3 = (p->f1C == 3) ? 1 : 0;
    p->b4 = 0;
    if (p->f1C != 3 && p->f20 == 2)
        p->b4 = 1;
    if ((p->f24 == 0 && (p->cont & 0x40)) || (p->f24 == 1 && (p->cont & 0x80))
        || (p->f24 == 2 && (p->cont & 0x20)) || (p->f24 == 3 && (p->cont & 0x10)))
        p->b5 = 1;
    else
        p->b5 = 0;
}
