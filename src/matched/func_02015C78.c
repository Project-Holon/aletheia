/*
 * function: func_02015C78
 * address:  0x02015C78
 * packet:   pkt_02015C78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Copies three words
 * into the structure at +0x11C; same shape as func_02015C48 further
 * back.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015C78(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0x11C) = src[0];
    *(u32 *)((char *)p + 0x120) = src[1];
    *(u32 *)((char *)p + 0x124) = src[2];
}
