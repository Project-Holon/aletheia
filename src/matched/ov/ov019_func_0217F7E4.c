/*
 * function: func_0217F7E4
 * address:  0x0217F7E4
 * packet:   pkt_ov019_0217F7E4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02012AD0  0x02012AD0  thumb
 *   d_02180718     0x02180718  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct P16 { short x; short z; };
extern u32 func_02188CB4(u32 a);
extern void func_02188C80(u32 a);
extern u32 func_020120F8(void);
extern void func_021A3038(u32 a, int *v);
extern void func_02012AD0(u32 a);
extern struct P16 d_02180718[];

int func_0217F7E4(u32 arg)
{
    int v[3];
    u32 h5, r4;
    u32 i;
    int x, z;

    h5 = func_02188CB4(arg);
    func_02188C80(arg);
    r4 = func_020120F8();
    func_021A3038(h5, v);
    v[0] = (v[0] >> 4) / 4096;
    v[2] = (v[2] >> 4) / 4096;
    func_02012AD0(r4);
    x = v[0];
    z = v[2];
    for (i = 0; i < 1; i++) {
        if (x == d_02180718[i].x && z == d_02180718[i].z) {
            return 1;
        }
    }
    return 0;
}
