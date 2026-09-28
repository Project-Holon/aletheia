/*
 * function: FS_StartOverlay
 * address:  0x0207902C
 * packet:   pkt_0207902C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * TwlSDK libfs fs_overlay.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Starts a loaded overlay: notes once when it sits in the TWL-limited main
 * area, checks its SHA-1 digest against the overlay digest table unless the
 * game booted from ROM (clearing the image and stopping on a mismatch),
 * decompresses it in place when compressed, flushes it, then runs its static
 * initialisers.
 *
 * symbols:
 *   FSi_GetOverlayBinarySize         0x02078CB0  arm
 *   OS_IsRunOnTwl                    0x02085D3C  arm
 *   OS_GetBootType                   0x02087B04  arm
 *   FSi_CompareDigest                0x02078F30  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   OS_Terminate                     0x02088234  arm
 *   MIi_UncompressBackward           0x02004DF4  arm
 *   DC_FlushRange                    0x020862F0  arm
 *   SDK_LTDAUTOLOAD_LTDMAIN_START    0x02700000  data
 *   SDK_LTDAUTOLOAD_LTDMAIN_BSS_END  0x02735B40  data
 *   FS_StartOverlay_once             0x02150D20  data
 *   SDK_OVERLAY_DIGEST_END           0x020A9E64  data
 *   SDK_OVERLAY_DIGEST               0x020A8BE0  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

#define OS_BOOTTYPE_ROM        1
#define FS_OVERLAY_FLAG_COMP   0x0001
#define FS_OVERLAY_FLAG_AUTH   0x0002
#define DIGEST_HASH_SIZE_SHA1  20

typedef void (*FSOverlayInitFunc)(void);

typedef struct FSOverlayInfoHeader {
    u32 id;
    u8 *ram_address;
    u32 ram_size;
    u32 bss_size;
    FSOverlayInitFunc *sinit_init;
    FSOverlayInitFunc *sinit_init_end;
    u32 file_id;
    u32 compressed:24;
    u32 flag:8;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo {
    FSOverlayInfoHeader header;
} FSOverlayInfo;

extern u8 SDK_LTDAUTOLOAD_LTDMAIN_START[];
extern u8 SDK_LTDAUTOLOAD_LTDMAIN_BSS_END[];
extern u8 SDK_OVERLAY_DIGEST[];
extern u8 SDK_OVERLAY_DIGEST_END[];
extern BOOL FS_StartOverlay_once;

extern u32 FSi_GetOverlayBinarySize(const FSOverlayInfo *p_ovi);
extern BOOL OS_IsRunOnTwl(void);
extern int OS_GetBootType(void);
extern BOOL FSi_CompareDigest(const u8 *spec_digest, void *src, int len);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void OS_Terminate(void);
extern void MIi_UncompressBackward(void *bottom);
extern void DC_FlushRange(const void *startAddr, u32 nBytes);

void FS_StartOverlay(FSOverlayInfo *p_ovi)
{
    u32 rare_size = FSi_GetOverlayBinarySize(p_ovi);

    if (((u32)p_ovi->header.ram_address >= (u32)SDK_LTDAUTOLOAD_LTDMAIN_START) &&
        ((u32)p_ovi->header.ram_address < (u32)SDK_LTDAUTOLOAD_LTDMAIN_BSS_END) && OS_IsRunOnTwl()) {
        if (!FS_StartOverlay_once) {
            FS_StartOverlay_once = 1;
        }
    }

    if (OS_GetBootType() != OS_BOOTTYPE_ROM) {
        BOOL ret = 0;
        if ((p_ovi->header.flag & FS_OVERLAY_FLAG_AUTH) != 0) {
            const u32 odt_max = (u32)((SDK_OVERLAY_DIGEST_END - SDK_OVERLAY_DIGEST) / DIGEST_HASH_SIZE_SHA1);
            if (p_ovi->header.id < odt_max) {
                const u8 *digest = SDK_OVERLAY_DIGEST + DIGEST_HASH_SIZE_SHA1 * p_ovi->header.id;
                ret = FSi_CompareDigest(digest, p_ovi->header.ram_address, (int)rare_size);
            }
        }
        if (!ret) {
            MI_CpuFill8(p_ovi->header.ram_address, 0x00, rare_size);
            OS_Terminate();
            return;
        }
    }

    if ((p_ovi->header.flag & FS_OVERLAY_FLAG_COMP) != 0) {
        MIi_UncompressBackward(p_ovi->header.ram_address + rare_size);
    }
    DC_FlushRange(p_ovi->header.ram_address, p_ovi->header.ram_size);
    {
        FSOverlayInitFunc *p = p_ovi->header.sinit_init;
        FSOverlayInitFunc *q = p_ovi->header.sinit_init_end;
        for (; p < q; ++p) {
            if (*p) {
                (**p)();
            }
        }
    }
}
