/*
 * function: func_021E01A0
 * address:  0x021E01A0
 * packet:   pkt_ov119_021E01A0
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0200C9EC  0x0200C9EC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   d_021E8130     0x021E8130  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *file, u32 line);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u32 func_0200C9EC(void);
extern void *func_0200CA1C(void *p);
extern const char d_021E8130[];

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void *func_021E01A0(void *src, u16 heapId)
{
    void *buf = sub_02030734(heapId, func_0200C9EC(), 0, d_021E8130, 0x1BD);

    GFL_STD_MemCopy(func_0200CA1C(src), buf, func_0200C9EC());
    return buf;
}
