/*
 * function: func_0217FC08
 * address:  0x0217FC08
 * packet:   pkt_ov019_0217FC08
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0217FD88  0x0217FD88  thumb  ov019
 *   func_0217FC64  0x0217FC64  thumb  ov019
 *   d_02180814     0x02180814  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *a, u32 b, const char *c);
extern u32 func_0217FD88(char *p);
extern void func_0217FC64(char *p, u32 a, u32 b, u32 c, u32 d);
extern u32 d_02180814[];

void func_0217FC08(char *p, u32 a1, u32 a2)
{
    if (*(u32 *)(p + 0xc8) == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (*(u32 *)(p + 0xcc) == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_0217FC64(p, func_0217FD88(p), a1, *(u16 *)(p + 0xd0), a2);
    *(u16 *)(p + 0xd0) = *(u16 *)(p + 0xd0) + 1;
}
