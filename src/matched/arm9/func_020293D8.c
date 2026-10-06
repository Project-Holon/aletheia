/*
 * function: func_020293D8
 * address:  0x020293D8
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

extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
struct S;
extern void func_02028BDC(struct S *s, u32 mask);

void func_020293D8(struct T *p)
{
    u32 n;

    if (p->f20 <= 0) {
        return;
    }
    func_02005E9C();
    func_02005DE4(0);
    n = p->f20 - 1;
    p->f20 = n;
    p->f08 = *(u32 *)((char *)p + 0x24 + n * 4);
    if (n == 0) {
        func_02028BDC((struct S *)p, 1);
    }
}
