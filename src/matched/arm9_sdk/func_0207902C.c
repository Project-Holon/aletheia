/*
 * function: FS_StartOverlay
 * address:  0x0207902C
 * packet:   pkt_0207902C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    bytes identical; SDK_LTDAUTOLOAD_LTDMAIN_START and _BSS_END resolve under the `linker` class (undefined in fs_overlay.o and in libfs; values = layout.json twl ram_start / bss_end)
 *
 * sdk:      FS_StartOverlay (libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   FSi_GetOverlayBinarySize  0x02078CB0  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetBootType  0x02087B04  arm
 *   FSi_CompareDigest  0x02078F30  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_Terminate  0x02088234  arm
 *   MIi_UncompressBackward  0x02004DF4  arm
 *   DC_FlushRange  0x020862F0  arm
 *   SDK_LTDAUTOLOAD_LTDMAIN_START  0x02700000  data
 *   SDK_LTDAUTOLOAD_LTDMAIN_BSS_END  0x02735B40  data
 *   fsi_overlay_state  0x02150D20  data
 *   SDK_OVERLAY_DIGEST_END  0x020A9E64  data
 *   SDK_OVERLAY_DIGEST  0x020A8BE0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

typedef void (*FSOverlayFunc)(void);

typedef struct FSOverlayInfoHeader
{
    u32 id;
    u8 *ram_address;
    u32 ram_size;
    u32 bss_size;
    FSOverlayFunc *sinit_init;
    FSOverlayFunc *sinit_init_end;
    u32 file_id;
    u32 compressed : 24;
    u32 flag : 8;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo
{
    FSOverlayInfoHeader header;
    int target;
    u32 file_pos[2];
} FSOverlayInfo;

typedef struct FSiOverlayState
{
    BOOL once;
} FSiOverlayState;

extern u8 SDK_LTDAUTOLOAD_LTDMAIN_START[];
extern u8 SDK_LTDAUTOLOAD_LTDMAIN_BSS_END[];
extern FSiOverlayState fsi_overlay_state;
extern u8 SDK_OVERLAY_DIGEST_END[];
extern u8 SDK_OVERLAY_DIGEST[];

extern u32 FSi_GetOverlayBinarySize(FSOverlayInfo *p_ovi);
extern BOOL OS_IsRunOnTwl(void);
extern u16 OS_GetBootType(void);
extern BOOL FSi_CompareDigest(const u8 *spec_digest, void *src, int len, BOOL table_mode);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void OS_Terminate(void);
extern void MIi_UncompressBackward(void *bottom);
extern void DC_FlushRange(void *startAddr, u32 nBytes);

void FS_StartOverlay(FSOverlayInfo *p_ovi)
{
    u32 rare_size = FSi_GetOverlayBinarySize(p_ovi);

    if (((u32)p_ovi->header.ram_address >= (u32)SDK_LTDAUTOLOAD_LTDMAIN_START) &&
        ((u32)p_ovi->header.ram_address < (u32)SDK_LTDAUTOLOAD_LTDMAIN_BSS_END) && OS_IsRunOnTwl())
    {
        if (!fsi_overlay_state.once)
        {
            fsi_overlay_state.once = 1;
        }
    }
    if (OS_GetBootType() != 1)
    {
        BOOL ret = 0;

        if ((p_ovi->header.flag & 2) != 0)
        {
            const u32 max = (u32)((SDK_OVERLAY_DIGEST_END - SDK_OVERLAY_DIGEST) / 20);

            if (p_ovi->header.id < max)
            {
                ret = FSi_CompareDigest(SDK_OVERLAY_DIGEST + p_ovi->header.id * 20,
                                        p_ovi->header.ram_address, (int)rare_size, 0);
            }
        }
        if (!ret)
        {
            MI_CpuFill8(p_ovi->header.ram_address, 0, rare_size);
            OS_Terminate();
            return;
        }
    }
    if ((p_ovi->header.flag & 1) != 0)
    {
        MIi_UncompressBackward(p_ovi->header.ram_address + rare_size);
    }
    DC_FlushRange(p_ovi->header.ram_address, p_ovi->header.ram_size);
    {
        FSOverlayFunc *p = p_ovi->header.sinit_init;
        FSOverlayFunc *q = p_ovi->header.sinit_init_end;

        for (; p < q; ++p)
        {
            if (*p)
            {
                (**p)();
            }
        }
    }
}
