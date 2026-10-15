/*
 * function: MYSTERY_ClearScroll
 * address:  0x021D9228
 * packet:   pkt_021D9228
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *, int, int);

void MYSTERY_ClearScroll(void *p)
{
    MI_CpuFill8(p, 0, 0x128);
}
