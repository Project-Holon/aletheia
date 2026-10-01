/*
 * function: func_0218DBAC
 * address:  0x0218DBAC
 * packet:   pkt_ov021_0218DBAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02169848  0x02169848  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02169848(void *out, u32 a, u32 b, u32 c);

int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d)
{
    u32 buf[0x41];
    func_02169848(buf, *(u32 *)(*(u8 **)(a + 0x24) + idx * 0x28), c, *(u32 *)(a + 4));
    *(u32 *)(d + 8) = buf[2];
    *(u32 *)(d + 0xc) = buf[3];
    return 1;
}
