/*
 * function: func_02078360
 * address:  0x02078360
 * packet:   pkt_02078360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: FS_InitArchive (TwlSDK libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);

void func_02078360(u8 *p_arc)
{
    MI_CpuFill8(p_arc, 0, 0x5c);
    *(u32 *)(p_arc + 0x10) = 0;
    *(u32 *)(p_arc + 0xc) = 0;
}
