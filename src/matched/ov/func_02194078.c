/*
 * function: FIELD_WFBC_BLOCK_ClearRand
 * address:  0x02194078
 * packet:   pkt_02194078
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 36.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuFill8();

void FIELD_WFBC_BLOCK_ClearRand(u32 a)
{
    MI_CpuFill8(a, 0, 36);
}
