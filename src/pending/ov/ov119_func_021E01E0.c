/*
 * function: func_021E01E0
 * address:  0x021E01E0
 * packet:   pkt_ov119_021E01E0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * symbols:
 *   func_0200C9EC  0x0200C9EC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_020307B0(void *);
extern u32 func_0200C9EC(void);
extern void *func_0200CA1C(void *p);

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void func_021E01E0(void *src, void *buf)
{
    GFL_STD_MemCopy(func_0200CA1C(src), buf, func_0200C9EC());
    func_020307B0(buf);
}
