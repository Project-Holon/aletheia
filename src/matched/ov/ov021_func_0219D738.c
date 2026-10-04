/*
 * function: func_0219D738
 * address:  0x0219D738
 * packet:   pkt_ov021_0219D738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u16 func_0216D5F8(void *p);
extern void func_0219E784(u32, u32, s16 *);
extern void func_0207CDB8(s16 *, s16 *);
extern int func_0207CFB8(int, int);
extern u8 d_021D80E4[];

u32 func_0219D738(u32 a, int b)
{
    s16 v[4];
    int r;
    func_0219E784(a, func_0216D5F8((void *)a), v);
    v[1] = 0;
    func_0207CDB8(v, v);
    r = func_0207CFB8(v[0], v[2]) - b;
    if (r < 0) {
        r += 0x10000;
    }
    return d_021D80E4[r >> 12];
}
