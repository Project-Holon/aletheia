/*
 * function: GFL_NET_HANDLE_IsBitSet
 * address:  0x0203A2F0
 * packet:   pkt_0203A2F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   file_020A7A68  0x020A7A68  data
 *   file_020A7AB0  0x020A7AB0  data
 *
 * Tests one bit of a channel mask, the 0xFF argument being a non-fatal
 * report at line 0x3AB (939).  The mask is truncated to a byte before the
 * `tst`, which is the `(u8)` cast in the shift expression, and the result is
 * materialised as 1/0 in r0 rather than left as the `tst` flags.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_IsBitSet.c \
 *       --func GFL_NET_HANDLE_IsBitSet --addr 0x0203A2F0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02034714(const char *file, u32 line, const char *msg);
extern const char file_020A7A68[];
extern const char file_020A7AB0[];

u32 GFL_NET_HANDLE_IsBitSet(u32 a0, u32 a1)
{
    if (a1 == 0xFF)
        func_02034714(file_020A7A68, 0x3AB, file_020A7AB0);
    return (a0 & (u8)(1 << a1)) != 0;
}
