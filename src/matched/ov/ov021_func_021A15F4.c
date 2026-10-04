/*
 * function: ov021_func_021A15F4
 * address:  0x021A15F4
 * packet:   pkt_ov021_021A15F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1784  0x021A1784  thumb  ov021
 *   func_021A1934  0x021A1934  thumb  ov021
 *   func_021A195C  0x021A195C  thumb  ov021
 *   func_021A1848  0x021A1848  thumb  ov021
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207D8C4  0x0207D8C4  arm
 *   d_02148B54     0x02148B54  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 w[16]; } S64;
extern S64 d_02148B54;
typedef unsigned char  u8;
extern u8 func_021A1780(u8 *p);
extern void func_021A1784(u32 *, u32 *, u32 *, S64 *);
extern void func_021A1934(u32 *);
extern void func_021A195C(u32 *);
extern void func_021A1848(u32 *);
extern void func_0206DB80(void);
extern void func_0207D8C4(S64 *);

void ov021_func_021A15F4(u32 *p)
{
    S64 buf;
    volatile u32 *r;
    if (p != 0 && p[2] != 0 && func_021A1780((u8 *)(p + 8)) != 0) {
        func_0206DB80();
        *(volatile u32 *)0x04000440 = 0;
        buf = d_02148B54;
        func_0207D8C4(&buf);
        r = (volatile u32 *)0x04000440;
        r[0] = 2;
        r[5] = 0;
        r[1] = 0;
        func_021A1784(p + 11, p, p + 8, &buf);
        func_021A1934(p);
        func_021A195C(p);
        func_021A1848(p + 11);
        r[2] = 1;
    }
}
