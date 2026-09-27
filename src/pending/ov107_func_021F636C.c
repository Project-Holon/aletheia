/*
 * function: MBi_InitCache
 * address:  0x021F636C
 * packet:   pkt_ov107_021F636C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_cache.o).  decl_line 33.
 */
typedef unsigned long u32;

extern void MI_CpuFill8(void *dst, int val, u32 len);

void MBi_InitCache(void *pl)
{
    MI_CpuFill8(pl, 0, 0x70);
}
