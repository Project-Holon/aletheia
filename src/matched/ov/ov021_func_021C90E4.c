/*
 * function: func_021C90E4
 * address:  0x021C90E4
 * packet:   pkt_ov021_021C90E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct S5 { u32 v[5]; } S5;

struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32, u32 *);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);

void func_021C90E4(u32 a, u32 *q)
{
    *(S5 *)q = *((S5 *)func_021AC1AC(a));
    func_021AC1CC(a, q + 1);
    q[9] = (u32)func_02047400((void *)(((u32 *)q[0])[2]), 0, (void *)(((u32 *)q[0])[2]));
    q[7] = (u32)func_02047564((struct G3dOwner *)q[9], (const struct G3dOwner *)(((u32 *)q[0])[6]), 0);
    q[8] = (u32)func_02047564((struct G3dOwner *)q[9], (const struct G3dOwner *)(((u32 *)q[0])[7]), 0);
    q[6] = (u32)func_0204767C(q[9], q + 7, 2);
    func_020477A4((struct G3dSys *)q[6], 0);
    func_020477A4((struct G3dSys *)q[6], 1);
    q[14] = (u32)func_02047400((void *)(((u32 *)q[0])[4]), 0, (void *)(((u32 *)q[0])[4]));
    q[13] = (u32)func_0204767C(q[14], 0, 0);
}
