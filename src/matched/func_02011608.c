/*
 * function: func_02011608
 * address:  0x02011608
 * packet:   pkt_02011608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (saves nothing, so disasm.py prints the run as ARM
 * data); the +0x0C field getter of the ica_anime accessor family at
 * 0x02011610. Four bytes: ldr r0,[r0,#0xC]; bx lr.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

u32 func_02011608(void *p)
{
    return *(u32 *)((char *)p + 0xC);
}
