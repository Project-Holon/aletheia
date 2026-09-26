/*
 * function: func_021DFB4C
 * address:  0x021DFB4C
 * packet:   pkt_ov119_021DFB4C
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02015C30   0x02015C30  thumb
 *   MI_CpuCopy8     0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_02015C30(u32, void *);
extern void MI_CpuCopy8(const void *, void *, u32);

void func_021DFB4C(void *p, void *a1, void *a2)
{
    u8 buf[12];

    func_02015C30(*(u32 *)p, buf);
    *(u32 *)((char *)p + 8) = 0;
    *(u32 *)((char *)p + 4) = (u32)a1;
    MI_CpuCopy8(a2, (char *)p + 0x28, 0xC);
    MI_CpuCopy8(buf, (char *)p + 0x1C, 0xC);
}
