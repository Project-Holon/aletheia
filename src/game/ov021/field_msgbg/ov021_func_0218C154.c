/*
 * function: func_0218C154
 * address:  0x0218C154
 * packet:   pkt_ov021_0218C154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts slot i of a four-slot effect set, or resets it.
 *
 * symbols:
 *   func_0218BD24  0x0218BD24  thumb  ov021
 *   func_0218BD20  0x0218BD20  thumb  ov021
 *   func_0218C388  0x0218C388  thumb  ov021
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_02047910  0x02047910  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_0218BD24(u8 *p);
extern u32 func_0218BD20(u8 *p);
extern void func_0218C388(u32 *st);
struct G3dSys;
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern int func_02047910(void *a, int idx, int amount);

void func_0218C154(u8 *a, u32 *st)
{
    int i = func_0218BD24(a + 8);

    if (func_0218BD20(a + 8) != 0) {
        func_0218C388(st);
        func_020477A4((struct G3dSys *)st[0], (u16)i);
        func_02047804((struct AnmCtl *)st[0], i);
        (st + i)[2] = 1;
    } else {
        func_02047910((void *)st[0], (u16)i, 0x1000);
    }
}
