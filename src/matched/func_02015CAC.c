/*
 * function: func_02015CAC
 * address:  0x02015CAC
 * packet:   pkt_02015CAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xEC. The inverse of func_02015C94.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015CAC(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0xEC) = src[0];
    *(u32 *)((char *)p + 0xF0) = src[1];
    *(u32 *)((char *)p + 0xF4) = src[2];
}
