/*
 * function: func_0200AB2C
 * address:  0x0200AB2C
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   (none - no data references)
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082BCC(void *p, int c, u32 n);

void func_0200AB2C(void *a0)
{
    func_02082BCC(a0, 0, 0x34c);
    *(u32 *)((u8 *)a0 + 0x348) = (*(u32 *)((u8 *)a0 + 0x348) & ~0xff) | 0x7f;
}
