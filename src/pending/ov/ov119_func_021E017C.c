/*
 * function: func_021E017C
 * address:  0x021E017C
 * packet:   pkt_ov119_021E017C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   sub_02009454   0x02009454  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_020307B0(void *);
extern void *func_02012EBC(void *sys);
extern u32 sub_02009454(void);
extern void *func_02009470(void *p);

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void func_021E017C(void *sys, void *buf)
{
    void *h = func_02012EBC(sys);

    GFL_STD_MemCopy(func_02009470(h), buf, sub_02009454());
    func_020307B0(buf);
}
