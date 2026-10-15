/*
 * function: FS_ClearOverlayImage
 * address:  0x02078CCC
 * packet:   pkt_02078CCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_ClearOverlayImage (libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   IC_InvalidateRange  0x0208632C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct FSOverlayInfoHeader
{
    u32 id;
    u8 *ram_address;
    u32 ram_size;
    u32 bss_size;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo
{
    FSOverlayInfoHeader header;
} FSOverlayInfo;

extern void IC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);

void FS_ClearOverlayImage(FSOverlayInfo *p_ovi)
{
    u8 *const addr = p_ovi->header.ram_address;
    const u32 image_size = p_ovi->header.ram_size;
    const u32 total_size = p_ovi->header.ram_size + p_ovi->header.bss_size;

    IC_InvalidateRange(addr, total_size);
    DC_InvalidateRange(addr, total_size);
    MI_CpuFill8(addr + image_size, 0, total_size - image_size);
}
