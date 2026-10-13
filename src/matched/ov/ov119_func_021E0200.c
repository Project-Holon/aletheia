/*
 * function: func_021E0200
 * address:  0x021E0200
 * packet:   pkt_ov119_021E0200
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   sub_02009D9C  0x02009D9C  thumb
 *   GAME_DATA_GetSaveBlock1F  0x02012F14  thumb
 *   d_021E8130     0x021E8130  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u32 sub_02009D9C(void);
extern void *GAME_DATA_GetSaveBlock1F(void **h);
extern const char d_021E8130[];

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void *func_021E0200(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02009D9C(), 0, d_021E8130, 0x1DA);

    GFL_STD_MemCopy(GAME_DATA_GetSaveBlock1F(sys), buf, sub_02009D9C());
    return buf;
}
