/*
 * function: func_0218C08C
 * address:  0x0218C08C
 * packet:   pkt_ov021_0218C08C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_0218BD24  0x0218BD24  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dSys;
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern u8 *func_0218BCAC(u8 *p);
extern u8 func_0218BD24(u8 *p);

void func_0218C08C(u8 *a, void **b)
{
    int i;
    u32 m;

    func_0218BCAC(*(void **)b[1]);
    m = func_0218BD24(a + 8);
    for (i = 0; i < 4; i++) {
        if (i != m) {
            b[2 + i] = 0;
        } else {
            func_020477A4(b[0], (u16)i);
            func_02047804(b[0], i);
            b[2 + i] = (void *)1;
        }
    }
}
