/*
 * function: func_0202939C
 * address:  0x0202939C
 * packet:   pkt_0202939C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u32 pad00;
    u32 f04;
    u32 f08;
    u8  pad0c[0x14];
    int f20;
    u32 f24;
};

extern void func_02028BA0(struct T *p, u32 v);
extern void func_02005DE4(void *p);
extern void func_02005E64(void);

void func_0202939C(struct T *p)
{
    if (p->f08 == 0) {
        return;
    }
    if (p->f20 >= 1) {
        return;
    }
    if (p->f20 == 0) {
        func_02028BA0(p, 1);
    }
    func_02005DE4((void *)1);
    func_02005E64();
    *(u32 *)((char *)p + 0x24 + p->f20 * 4) = p->f08;
    p->f20 = p->f20 + 1;
    p->f08 = 0;
}
