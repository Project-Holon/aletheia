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

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct BigObj;
struct Desc;
extern u32 func_0201296C(const struct BigObj *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u16 func_02162928(void *p, void *q, int key, int mode);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);

int func_0218A784(struct Ctx784 *c, int a)
{
    void *x = func_0201210C(c->f4);
    void *y = (void *)func_0201296C(c->f8);
    u32 pos[3];
    u32 msg;

    func_021A3038(c->f18, (struct VecFx32 *)pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(x), pos))) == 1)
        return 0;
    msg = func_02162928(c->fC, y, (int)pos, a);
    if (msg != 0xFFFF)
        return (int)func_02158768((int)c->f4, msg, 0, c->f0);
    return 0;
}
