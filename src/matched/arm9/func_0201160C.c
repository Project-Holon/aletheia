/*
 * function: func_0201160C
 * address:  0x0201160C
 * packet:   pkt_0201160C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (saves nothing, so disasm.py prints the run as ARM
 * data); the +0x10 field getter of the ica_anime accessor family at
 * 0x02011610. Four bytes: ldr r0,[r0,#0x10]; bx lr.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

u32 func_0201160C(void *p)
{
    return *(u32 *)((char *)p + 0x10);
}
