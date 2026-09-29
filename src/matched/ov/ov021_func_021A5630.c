/*
 * function: func_021A5630
 * address:  0x021A5630
 * packet:   pkt_ov021_021A5630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3920  0x021A3920  thumb  ov021
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021A55DC  0x021A55DC  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D8A24  0x021D8A24  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3920(u32);
extern int func_021A5788(u32, u32, u32 *);
extern void func_021AB0F0(u32);
extern int func_021A55DC(void);
extern int func_021AB11C(u32);
extern const u16 d_021D8A24[4];

u32 func_021A5630(u32 a)
{
    u32 v;
    u16 t[4];
    u16 i;
    u32 x;
    u16 *p = t;
    t[0] = d_021D8A24[0];
    t[1] = d_021D8A24[1];
    t[2] = d_021D8A24[2];
    t[3] = d_021D8A24[3];
    x = func_021A3920(*(u32 *)(a + 12));
    i = 0;
    do {
        if (func_021A5788(a, x, &v) == 1) {
            func_021AB0F0(v);
            if (func_021A55DC() == 0) {
                if (func_021AB11C(v) == 0) {
                    return x;
                }
            }
        }
        i = i + 1;
        x = p[x];
    } while (i < 4);
    return 9;
}
