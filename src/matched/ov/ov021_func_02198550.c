/*
 * function: func_02198550
 * address:  0x02198550
 * packet:   pkt_ov021_02198550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;

extern u8 *func_0216D6D4(u32);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern void func_02163E7C(int a, int b);
extern void func_0216D568(u32, u32);
extern int *d_021DDBD4[];
extern void func_0216D8C0(u32, Vec *);
extern void func_02163F10(u32);
extern void func_0216D674(u32, u32);
extern void func_0216D7CC(u32);
extern void func_020061E4(u32);

int func_02198550(u32 a)
{
    u8 *h;

    h = func_0216D6D4(a);
    if (*(int *)h != 0) {
        func_02163FC0(a, *(s8 *)(h + 12), *(int *)h);
        func_02164010(a);
        if (*(int *)(h + 4) >= 0x10000) {
            *(int *)(h + 4) = 0;
            func_02163E7C(a, *(s8 *)(h + 12));
            func_0216D568(a, 0x20);
        }
        *(int *)(h + 4) += (*(int *)h < 0) ? -*(int *)h : *(int *)h;
    }
    *(u16 *)(h + 10) += *(u16 *)(h + 8);
    if (*(u16 *)(h + 10) > 0xF00) {
        *(u16 *)(h + 10) = 0xF00;
    }
    {
        Vec v;
        u16 k;
        int i;
        k = *(u16 *)(h + 10) / 256;
        i = *(s8 *)(h + 15);
        v.x = 0;
        v.y = d_021DDBD4[i][k];
        v.z = 0;
        func_0216D8C0(a, &v);
    }
    *(s8 *)(h + 13) = *(s8 *)(h + 13) - 1;
    if (*(s8 *)(h + 13) > 0) {
        return 0;
    }
    {
        Vec v = { 0, 0, 0 };
        func_0216D8C0(a, &v);
    }
    func_0216D568(a, 0x540);
    func_02163F10(a);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    func_020061E4(0x67B);
    return 1;
}
