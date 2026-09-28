/*
 * function: func_0218A784
 * address:  0x0218A784
 * packet:   pkt_ov021_0218A784
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unless the tile attribute under the object's position blocks it
 * (func_021AB188), asks ov010 func_02162928 for a message id and shows it
 * through func_02158768; returns 0 otherwise.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB188  0x021AB188  thumb
 *   func_02162928  0x02162928  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx784 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
};

extern void *func_0201210C(void *p);
extern void *func_0201296C(void *p);
extern void func_021A3038(void *p, u32 *out);
extern void *func_02188C98(void *p);
extern u32 func_021AB0D4(void *a, u32 *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u32 func_02162928(void *p, void *q, u32 *pos, int a);
extern int func_02158768(void *a0, u32 a1, int a2, u16 a3);

int func_0218A784(struct Ctx784 *c, int a)
{
    void *x = func_0201210C(c->f4);
    void *y = func_0201296C(c->f8);
    u32 pos[3];
    u32 msg;

    func_021A3038(c->f18, pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4(func_02188C98(x), pos))) == 1)
        return 0;
    msg = func_02162928(c->fC, y, pos, a);
    if (msg != 0xFFFF)
        return func_02158768(c->f4, msg, 0, c->f0);
    return 0;
}
