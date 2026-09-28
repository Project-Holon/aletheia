/*
 * function: func_021E0138
 * address:  0x021E0138
 * packet:   pkt_ov119_021E0138
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
 *   func_02012EBC  0x02012EBC  thumb
 *   sub_02009454  0x02009454  thumb
 *   func_02009470  0x02009470  thumb
 *   d_021E8130     0x021E8130  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *file, u32 line);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern void *func_02012EBC(void *sys);
extern u32 sub_02009454(void);
extern void *func_02009470(void *p);
extern const char d_021E8130[];

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void *func_021E0138(void *sys, u16 heapId)
{
    void *h = func_02012EBC(sys);
    void *buf = sub_02030734(heapId, sub_02009454(), 0, d_021E8130, 0x1A0);

    GFL_STD_MemCopy(func_02009470(h), buf, sub_02009454());
    return buf;
}
