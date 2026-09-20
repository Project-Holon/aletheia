/*
 * function: func_0201D768
 * address:  0x0201D768
 * packet:   pkt_0201D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

u8 *func_0201D768(u16 *p, u8 *dst, u32 len, u32 n)
{
    u32 total = 0;
    u8 *base = (u8 *)p;
    u16 start;
    base = base + 0x18;
    start = p[0];

    if (len > 0) {
        do {
            u16 head = p[0];
            MI_CpuCopy8(dst, base + head, n);
            head = (u16)(head + n);
            if (head >= p[2]) {
                head = 0;
            }
            p[0] = head;
            dst += n;
            total = (u16)(total + n);
        } while (total < len);
    }
    return base + start;
}
