/*
 * function: func_021D11F4
 * address:  0x021D11F4
 * packet:   pkt_ov021_021D11F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0204384C  0x0204384C  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049238  0x02049238  arm
 *   d_021DB97C     0x021DB97C  data    ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012944(u32 a);
extern u32 func_02008550(u32 a);
extern u32 func_0204384C(u32 a, u32 b, u32 c, u32 d);
extern void func_02049BDC(u32 h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049238(u32 h);
extern const u32 d_021DB97C[];

void func_021D11F4(u32 *p, u32 b)
{
    void *h = func_020490F4(200, b);
    u32 idx;

    idx = func_02008550(func_02012944(func_020120F4(func_02188C80(p[0]))));
    p[4] = func_0204384C(200, 0, 0, b);
    func_02049BDC(h, 1, 0, d_021DB97C[idx] << 5, 0x120, 0x20, b);
    func_02049238(h);
}
