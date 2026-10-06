/*
 * function: func_021D0648
 * address:  0x021D0648
 * packet:   pkt_ov021_021D0648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046F50  0x02046F50  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DB95C     0x021DB95C  data  a4
 *   d_021DB950     0x021DB950  data  ov021  a4
 *   d_021DB954     0x021DB954  data  ov021  a4
 */

typedef unsigned short u16;

typedef struct S {
    int f0;
    int a[3];
    int f10;
    int b[2];
    int f1c;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct G3dOwner;
struct G3dRec;
struct Tagged;
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
struct G3dSys;
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);

extern int d_021DB95C[3];
extern int d_021DB950;
extern int d_021DB954[2];

void func_021D0648(S *p)
{
    int h;
    int i;
    int j;
    int k;

    h = func_021ABE24((u8 *)p->f0);
    for (i = 0; i < 3; i++) {
        p->a[i] = (int)func_02046E24(h, d_021DB95C[i]);
        if (func_02046F50((struct Tagged *)p->a[i], 2)) {
            func_02046FF8((int *)p->a[i]);
        }
    }
    j = 0;
    p->f10 = (int)func_02047400((void *)p->a[d_021DB950], 0, (void *)p->a[d_021DB950]);
    k = j;
    for (i = 0; i < 2; i++) {
        p->b[i] = (int)func_02047564((struct G3dOwner *)p->f10, (const struct G3dOwner *)p->a[d_021DB954[i]], k);
    }
    p->f1c = (int)func_0204767C((int)p->f10, (u32 *)p->b, 2);
    for (k = 0; k < 2; k++) {
        func_020477A4((struct G3dSys *)p->f1c, (u16)k);
    }
}
