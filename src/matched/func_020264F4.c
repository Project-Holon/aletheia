/*
 * function: func_020264F4
 * address:  0x020264F4
 * packet:   pkt_020264B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dst, u32 value, u32 size);

void func_020264F4(u8 *p)
{
    MI_CpuFill8(p + 0x24, 0, 0x18);
}
