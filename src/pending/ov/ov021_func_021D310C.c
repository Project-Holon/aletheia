/*
 * function: func_021D310C
 * address:  0x021D310C
 * packet:   pkt_ov021_021D310C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked: abs_id_e1 (0x000000E1, literal-pool ABS32) and d_021BBDE4 both
 * have no witness outside the range (evidence class: none / literal only).
 *
 * symbols:
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021D3164  0x021D3164  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   abs_id_e1      0x000000E1  data
 *   d_021BBDE4    0x021BBDE4  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_020146F8(u32 a, u32 b, const void *c, const char *d, u32 e);
extern unsigned char abs_id_e1[];
extern void func_02012374(u32 a, u32 b);
extern void func_021D3164(u32 *p);
extern void func_020307B0(u32 p);
extern char d_021BBDE4[];

u32 func_021D310C(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        func_02012374(a, func_020146F8(p[0], p[1], abs_id_e1, d_021BBDE4, p[2]));
        st[0]++;
        break;
    case 1:
        func_021D3164(p);
        func_020307B0(p[2]);
        return 1;
    }
    return 0;
}
