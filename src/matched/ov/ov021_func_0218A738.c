/*
 * function: func_0218A738
 * address:  0x0218A738
 * packet:   pkt_ov021_0218A738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts the pending script (field 0x26) through func_02158768, or else asks
 * func_02158B00 for the default one; returns the result.
 *
 * symbols:
 *   func_02012B38  0x02012B38  thumb
 *   func_02014474  0x02014474  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_02158B00  0x02158B00  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx738 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    char pad0C[0x1A];
    u16 f26;
};

struct BigObj;
struct Sub02014444Obj;
extern void *func_02012B38(const struct BigObj *p);
extern void func_02014474(struct Sub02014444Obj *o, u16 v);
struct Desc;
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_02158B00(void *a, u32 b);

int func_0218A738(struct Ctx738 *c)
{
    int r;

    if (c->f26 != 0) {
        func_02014474(func_02012B38(c->f8), 0);
        return (int)func_02158768((int)c->f4, c->f26, 0, c->f0);
    }
    r = (int)func_02158B00(c->f4, c->f0);
    if (r == 0)
        return 0;
    return r;
}
