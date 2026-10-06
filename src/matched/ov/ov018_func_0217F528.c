/*
 * function: func_0217F528
 * address:  0x0217F528
 * packet:   pkt_ov018_0217F528
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02034714  0x02034714  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   d_02183B2C     0x02183B2C  data
 */

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
} Ov018Obj;

typedef unsigned short u16;

extern unsigned char d_02183B2C[];

struct Ctx;
void *func_0201210C(const struct Ctx *p);
typedef unsigned int   u32;
struct Fx;
void func_02034714(const char *expr, u32 line, const char *file);
void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);

void func_0217F528(Ov018Obj *p, int a, int b, int c, int d, int e)
{
    func_0201210C((void *)a);
    if (p->f20 != 0) {
        func_02034714((const char *)d_02183B2C, (int)0, (const char *)d_02183B2C);
    }
    p->f20 = func_02190708(p->f24, (u32)p->f0C, (u16)b, (u16)c, d, e);
}
