/*
 * function: func_021BB2F8
 * address:  0x021BB2F8
 * packet:   pkt_ov021_021BB2F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490A8  0x020490A8  arm
 *   func_02030734  0x02030734  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_021BB278  0x021BB278  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DE2D0     0x021DE2D0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_020490A8(u32 a, u32 b);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_021BB278(u32, void *, u32);
extern void func_020307B0(void *);
extern int d_021DE2D0;

void func_021BB2F8(u32 a, u32 b, u32 c)
{
    int n = func_020490A8(0x6d, b);
    void *p = func_02030734((u16)(((u16)c & 0x7FFF) | 0x8000), n, 1, (const char *)&d_021DE2D0, 0xdd);

    func_02048F4C(p, 0x6d, b);
    func_021BB278(a, p, c);
    func_020307B0(p);
}
