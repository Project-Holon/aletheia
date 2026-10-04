/*
 * function: func_021AD82C
 * address:  0x021AD82C
 * packet:   pkt_ov021_021AD82C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *
 * Lever: func_0204767C takes three arguments (see ov019_func_0217FA10); the
 * third is b->f88, which is what keeps the loop bound in r2.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);

typedef struct A {
    u32 f0;
    u32 f4[4];
    u32 f14;
} A;

typedef struct B {
    u8 pad0[8];
    u32 f8[4];
    u32 f18[28];
    u8 f88;
} B;

void func_021AD82C(A *a, B *b, int c)
{
    int i = 0;

    a->f14 = (u32)func_02047400((void *)b->f8[c], 0, (void *)b->f8[c]);
    for (; i < b->f88; i++)
        a->f4[i] = (u32)func_02047564((struct G3dOwner *)a->f14, (const struct G3dOwner *)b->f18[c * b->f88 + i], 0);
    a->f0 = (u32)func_0204767C(a->f14, a->f4, b->f88);
    for (i = 0; i < b->f88; i++)
        func_020477A4((struct G3dSys *)a->f0, (u16)i);
}
