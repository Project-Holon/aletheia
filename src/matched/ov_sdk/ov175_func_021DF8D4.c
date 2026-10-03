/*
 * function: func_021DF8D4
 * address:  0x021DF8D4
 * packet:   pkt_021DF8D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0730  0x021E0730  arm
 *   func_020923B0  0x020923B0  arm
 *
 * Reset the owner: release it, blank the two 0x28-byte parameter blocks, put
 * the 0xadde signature on the front of each and clear the live flag.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021E0730(char *p);
extern void *func_020923B0(void *p, int c, u32 n);

void func_021DF8D4(char *p)
{
    u32 z = 0;
    u32 n = 0x28;

    func_021E0730(p);
    func_020923B0(p + 0x5c, z, n);
    func_020923B0(p + 0x84, z, n);
    *(u8 *)(p + 0x5c) = 0xde;
    *(u8 *)(p + 0x5d) = 0xad;
    *(u8 *)(p + 0x84) = 0xde;
    *(u8 *)(p + 0x85) = 0xad;
    *(u32 *)(p + 0x50) = z;
}
