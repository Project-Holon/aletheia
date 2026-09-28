/*
 * function: func_0216D8B0
 * address:  0x0216D8B0
 * packet:   pkt_0216D8B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 12-byte record from p + 0x50 into q.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef struct S12 { u32 a, b, c; } S12;


void func_0216D8B0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x50);
}

