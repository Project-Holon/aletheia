/*
 * file:     unit_02078C40_p01.c
 * unit:     yes
 * function: func_02078C40, func_02078CB0, func_02078CCC, func_02078D08
 * address:  0x02078C40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_GetBootType  0x02087B04  arm
 *   FS_FindArchive  0x02077EB8  arm
 *   fsi_overlay_state  0x02150D20  data
 *   fsi_def_digest_key  0x020A19C4  data
 *   fsi_str_rom  0x020A84A4  data
 *   IC_InvalidateRange  0x0208632C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   _ZZ15FS_StartOverlayP13FSOverlayInfoE4once 0x02150d20 data
 *   .bss                             0x02150d20 data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_02078C40;

typedef struct FSArchive FSArchive;

typedef struct FSiOverlayState
{
    u32_02078C40 once;
    FSArchive *arc;
    u32_02078C40 unk08;
    u32_02078C40 unk0C;
    u32_02078C40 unk10;
    u32_02078C40 unk14;
    const u8 *digest_key;
    u32_02078C40 digest_key_len;
} FSiOverlayState;

typedef unsigned int u32_1;

typedef struct
{
    u32_1 id;
    u32_1 ramAddress;
    u32_1 ramSize;
    u32_1 bssSize;
    u32_1 sinitStart;
    u32_1 sinitEnd;
    u32_1 fileId;
    u32_1 size : 24;
    u32_1 compressed : 8;
} FSOverlayInfo_1;

typedef unsigned long u32_02078CCC;

typedef struct FSOverlayInfoHeader_02078C40
{
    u32_02078CCC id;
    u8 *ram_address;
    u32_02078CCC ram_size;
    u32_02078CCC bss_size;
} FSOverlayInfoHeader_02078C40;

typedef struct FSOverlayInfo_02078CCC
{
    FSOverlayInfoHeader_02078C40 header;
} FSOverlayInfo_02078CCC;

typedef struct FSFileID {
    FSArchive *arc;
    unsigned long file_id;
} FSFileID;

typedef struct FSOverlayInfoHeader_02078D08 {
    unsigned long id;
    void *ram_address;
    unsigned long ram_size;
    unsigned long bss_size;
    void *sinit_init;
    void *sinit_init_end;
    unsigned long file_id;
    unsigned long flag;
} FSOverlayInfoHeader_02078D08;

typedef struct FSOverlayInfo {
    FSOverlayInfoHeader_02078D08 header;
    int target;
    unsigned long file_pos[2];
} FSOverlayInfo;

typedef struct FSiOverlayContextType {
    FSArchive *arc;
    unsigned char rest[24];
} FSiOverlayContextType;

extern u16 OS_GetBootType(void);
extern FSArchive *FS_FindArchive(const char *name, int name_len);
extern void IC_InvalidateRange(void *startAddr, u32_02078CCC nBytes);
extern void DC_InvalidateRange(void *startAddr, u32_02078CCC nBytes);
extern void MI_CpuFill8(void *dstp, u8 data, u32_02078CCC size);
void func_02078C40(void);
u32_1 FSi_GetOverlayBinarySize(FSOverlayInfo_1 *p);
void func_02078CCC(FSOverlayInfo_02078CCC *p_ovi);
FSFileID func_02078D08(FSOverlayInfo *p_ovi);
extern FSiOverlayState fsi_overlay_state;
extern const u8 fsi_def_digest_key[64];
extern const char fsi_str_rom[];



/*
 * sdk:      FSi_InitOverlay (libfs.TWL.HYB.a fs_overlay.o)
 */
void func_02078C40(void)
{
    if (OS_GetBootType() == 2)
    {
        fsi_overlay_state.unk08 = 0xFFFFFFFF;
        fsi_overlay_state.unk0C = 0;
        fsi_overlay_state.unk10 = 0xFFFFFFFF;
        fsi_overlay_state.unk14 = 0;
    }
    else
    {
        fsi_overlay_state.unk08 = 0;
        fsi_overlay_state.unk0C = 0;
        fsi_overlay_state.unk10 = 0;
        fsi_overlay_state.unk14 = 0;
    }
    fsi_overlay_state.digest_key = fsi_def_digest_key;
    fsi_overlay_state.digest_key_len = sizeof(fsi_def_digest_key);
    fsi_overlay_state.arc = FS_FindArchive(fsi_str_rom, 3);
}



u32_1 FSi_GetOverlayBinarySize(FSOverlayInfo_1 *p)
{
    if (p->compressed & 1)
        return p->size;
    return p->ramSize;
}



/*
 * sdk:      FS_ClearOverlayImage (libfs.TWL.HYB.a fs_overlay.o)
 */
void func_02078CCC(FSOverlayInfo_02078CCC *p_ovi)
{
    u8 *const addr = p_ovi->header.ram_address;
    const u32_02078CCC image_size = p_ovi->header.ram_size;
    const u32_02078CCC total_size = p_ovi->header.ram_size + p_ovi->header.bss_size;

    IC_InvalidateRange(addr, total_size);
    DC_InvalidateRange(addr, total_size);
    MI_CpuFill8(addr + image_size, 0, total_size - image_size);
}


/* .bss of the object: FS_StartOverlay's function-static `once` at +0, then
 * FSiOverlayContext at +4 */
static int once_slot = 0;

static FSiOverlayContextType FSiOverlayContext = { 0 };


/*
 * sdk:      FS_GetOverlayFileID (fs_overlay.o)
 */
FSFileID func_02078D08(FSOverlayInfo *p_ovi)
{
    FSFileID ret;

    ret.arc = FSiOverlayContext.arc;
    ret.file_id = p_ovi->header.file_id;
    return ret;
}
