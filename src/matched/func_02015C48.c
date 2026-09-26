/*
 * function: func_02015C48
 * address:  0x02015C48
 * packet:   pkt_02015C48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xE0. The inverse of func_02015C30; in the ov118 event state
 * machine (0x021D7130) and func_021D6E04 it is the in-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015C48(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0xE0) = src[0];
    *(u32 *)((char *)p + 0xE4) = src[1];
    *(u32 *)((char *)p + 0xE8) = src[2];
}
