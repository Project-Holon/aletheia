/*
 * function: func_021ADF14
 * address:  0x021ADF14
 * packet:   pkt_ov021_021ADF14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DE120     0x021DE120  data  a2
 */

typedef unsigned short u16;

extern u16 d_021DE120;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern int func_0204767C(int a, int *b, int c);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);

void func_021ADF14(int *p)
{
    int r5 = func_021ABE24((u8 *)p[0]);

    func_02046FF8((int *)(p[1] = (int)func_02046E24(r5, 0x54)));
    p[2] = (int)func_02046E24(r5, d_021DE120);
    p[5] = (int)func_02047400((void *)p[1], 0, (void *)p[1]);
    p[4] = (int)func_02047564((struct G3dOwner *)p[5], (const struct G3dOwner *)p[2], 0);
    p[3] = func_0204767C(p[5], &p[4], 1);
    func_020477A4((struct G3dSys *)p[3], 0);
}
