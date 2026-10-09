/*
 * file:     unit_02078C40.c
 * unit:     yes
 * function: func_02078C40, func_02078CB0, func_02078CCC, func_02078D08, func_02078D34, func_02078EB0, func_02078F30, func_0207902C, func_02079164, func_02079254, func_02079264, func_020792B8
 * address:  0x02078C40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_GetBootType  0x02087B04  arm
 *   FS_FindArchive  0x02077EB8  arm
 *   fsi_def_digest_key  0x020A19C4  data
 *   _ZZ15FS_StartOverlayP13FSOverlayInfoE4once  0x02150D20  data
 *   .bss  0x02150D20  data
 *   FSiOverlayContext  0x02150D24  data
 *   fsi_str_rom  0x020A84A4  data
 *   IC_InvalidateRange  0x0208632C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   FS_InitFile  0x020788AC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   FS_OpenFileFast  0x020789A4  arm
 *   CARD_GetOwnRomHeader  0x02075DF8  arm
 *   FS_CreateFileFromRom  0x0207ACD4  arm
 *   FS_ReadFile  0x02078B70  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_GetFileImageTop  0x0207A7BC  arm
 *   FS_GetFileLength  0x02078A94  arm
 *   SDK_OVERLAY_NUMBER  0x000000ED  data
 *   func_0209125C  0x0209125C  thumb
 *   OS_Terminate  0x02088234  arm
 *   MIi_UncompressBackward  0x02004DF4  arm
 *   DC_FlushRange  0x020862F0  arm
 *   SDK_LTDAUTOLOAD_LTDMAIN_START  0x02700000  data
 *   SDK_LTDAUTOLOAD_LTDMAIN_BSS_END  0x02735B40  data
 *   SDK_OVERLAY_DIGEST_END  0x020A9E64  data
 *   SDK_OVERLAY_DIGEST  0x020A8BE0  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021542B8     0x021542B8  data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive FSArchive;

typedef struct FSFile
{
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32 stat;
    void *argument;
    int error;
    OSThreadQueue queue[1];
    u8 prop[16];
    u8 arg[24];
} FSFile;

typedef struct FSFileID
{
    FSArchive *arc;
    u32 file_id;
} FSFileID;

typedef struct CARDRomRegion
{
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct CARDRomHeader
{
    u8 pad00[0x50];
    CARDRomRegion main_ovt;
    CARDRomRegion sub_ovt;
} CARDRomHeader;

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
    CARDRomRegion file_pos;
} FSOverlayInfo;

typedef struct FSOverlaySource
{
    u8 *buffer;
    u32 length;
} FSOverlaySource;

typedef struct FSiOverlayContext
{
    FSArchive *arc;
    FSOverlaySource source[2];
    const u8 *digest_key;
    u32 digest_key_len;
} FSiOverlayContextType;

typedef struct Node02079164
{
    struct Node02079164 *next;
    void (*fn)(void *);
    void *arg;
} Node02079164;

extern u16 OS_GetBootType(void);
extern BOOL OS_IsRunOnTwl(void);
extern FSArchive *FS_FindArchive(const char *name, int name_len);
extern void IC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_FlushRange(void *startAddr, u32 nBytes);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void FS_InitFile(FSFile *file);
extern BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
extern const CARDRomHeader *CARD_GetOwnRomHeader(void);
extern BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size);
extern s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
extern BOOL FS_CloseFile(FSFile *file);
extern u32 FS_GetFileImageTop(FSFile *file);
extern u32 FS_GetFileLength(FSFile *file);
extern void func_02082BCC(void *, int, u32);
extern void func_02082D44(u32, void *, u32);
extern void func_0209125C(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len);
extern u32 func_0208139C(u32);
extern void func_020816FC(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len);
extern void OS_Terminate(void);
extern void MIi_UncompressBackward(void *bottom);
extern u32 func_02087988(void);
extern void func_0208799C(u32 e);
extern const u8 fsi_def_digest_key[64];
extern const char fsi_str_rom[];
extern u8 SDK_OVERLAY_NUMBER[];
extern u8 SDK_LTDAUTOLOAD_LTDMAIN_START[];
extern u8 SDK_LTDAUTOLOAD_LTDMAIN_BSS_END[];
extern u8 SDK_OVERLAY_DIGEST_END[];
extern u8 SDK_OVERLAY_DIGEST[];
extern Node02079164 *g_021542B8;

void func_02078C40(void);
u32 func_02078CB0(FSOverlayInfo *p);
void func_02078CCC(FSOverlayInfo *p_ovi);
FSFileID func_02078D08(FSOverlayInfo *p_ovi);
BOOL func_02078D34(FSOverlayInfo *p_ovi, u32 target, u32 id);
BOOL func_02078EB0(FSOverlayInfo *p_ovi);
BOOL func_02078F30(const u8 *spec_digest, void *src, int len, BOOL table_mode);
void func_0207902C(FSOverlayInfo *p_ovi);
void func_02079164(FSOverlayInfo *p_ovi);
BOOL func_02079254(FSOverlayInfo *p_ovi);
BOOL func_02079264(int target, u32 id);
int func_020792B8(int target, u32 id);

/* .bss of the object: FS_StartOverlay's function-static `once` at +0, then
 * FSiOverlayContext at +4 */
static int once_slot = 0;

static FSiOverlayContextType FSiOverlayContext = { 0 };


/*
 * sdk:      FSi_InitOverlay (libfs.TWL.HYB.a fs_overlay.o)
 */
void func_02078C40(void)
{
    if (OS_GetBootType() == 2)
    {
        FSiOverlayContext.source[0].buffer = (u8 *)0xFFFFFFFF;
        FSiOverlayContext.source[0].length = 0;
        FSiOverlayContext.source[1].buffer = (u8 *)0xFFFFFFFF;
        FSiOverlayContext.source[1].length = 0;
    }
    else
    {
        FSiOverlayContext.source[0].buffer = 0;
        FSiOverlayContext.source[0].length = 0;
        FSiOverlayContext.source[1].buffer = 0;
        FSiOverlayContext.source[1].length = 0;
    }
    FSiOverlayContext.digest_key = fsi_def_digest_key;
    FSiOverlayContext.digest_key_len = sizeof(fsi_def_digest_key);
    FSiOverlayContext.arc = FS_FindArchive(fsi_str_rom, 3);
}



u32 func_02078CB0(FSOverlayInfo *p)
{
    if (p->header.flag & 1)
        return p->header.compressed;
    return p->header.ram_size;
}



/*
 * sdk:      FS_ClearOverlayImage (libfs.TWL.HYB.a fs_overlay.o)
 */
void func_02078CCC(FSOverlayInfo *p_ovi)
{
    u8 *const addr = p_ovi->header.ram_address;
    const u32 image_size = p_ovi->header.ram_size;
    const u32 total_size = p_ovi->header.ram_size + p_ovi->header.bss_size;

    IC_InvalidateRange(addr, total_size);
    DC_InvalidateRange(addr, total_size);
    MI_CpuFill8(addr + image_size, 0, total_size - image_size);
}


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


/*
 * sdk:      FS_LoadOverlayInfo (libfs.TWL.HYB.a fs_overlay.o)
 */
/*
 * notes:    bytes identical; SDK_OVERLAY_NUMBER (0xED) resolves under the `linker` class (undefined in fs_overlay.o and in libfs; value = layout.json counts.overlays)
 *
 * sdk:      FS_LoadOverlayInfo (libfs.TWL.HYB.a fs_overlay.o)
 */
BOOL func_02078D34(FSOverlayInfo *p_ovi, u32 target, u32 id)
{
    BOOL retval = 0;
    const u32 pos = id * 32;
    FSOverlaySource *const src = (target == 0) ? &FSiOverlayContext.source[0] : &FSiOverlayContext.source[1];

    if ((id < (u32)SDK_OVERLAY_NUMBER) || OS_IsRunOnTwl())
    {
        if (src->buffer)
        {
            if (pos < src->length)
            {
                FSFile file[1];

                FS_InitFile(file);
                MI_CpuCopy8(src->buffer + pos, p_ovi, 32);
                p_ovi->target = target;
                if (FS_OpenFileFast(file, func_02078D08(p_ovi)))
                {
                    p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                    p_ovi->file_pos.length = FS_GetFileLength(file);
                    (void)FS_CloseFile(file);
                    retval = 1;
                }
            }
        }
        else
        {
            const CARDRomRegion *const pr = (target == 0) ? &CARD_GetOwnRomHeader()->main_ovt : &CARD_GetOwnRomHeader()->sub_ovt;

            if (pos < pr->length)
            {
                FSFile file[1];

                FS_InitFile(file);
                if (FS_CreateFileFromRom(file, pr->offset + pos, pr->offset + pr->length))
                {
                    if (FS_ReadFile(file, p_ovi, 32) != 32)
                    {
                        (void)FS_CloseFile(file);
                    }
                    else
                    {
                        (void)FS_CloseFile(file);
                        p_ovi->target = target;
                        if (FS_OpenFileFast(file, func_02078D08(p_ovi)))
                        {
                            p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                            p_ovi->file_pos.length = FS_GetFileLength(file);
                            (void)FS_CloseFile(file);
                            retval = 1;
                        }
                    }
                }
            }
        }
    }
    return retval;
}


/*
 * sdk:      FS_LoadOverlayImage (libfs.TWL.HYB.a fs_overlay.o)
 */
BOOL func_02078EB0(FSOverlayInfo *p_ovi)
{
    BOOL retval = 0;
    FSFile p_file[1];

    FS_InitFile(p_file);
    if (FS_OpenFileFast(p_file, func_02078D08(p_ovi)))
    {
        s32 size = (s32)func_02078CB0(p_ovi);

        func_02078CCC(p_ovi);
        if (FS_ReadFile(p_file, p_ovi->header.ram_address, size) == size)
        {
            retval = 1;
        }
        (void)FS_CloseFile(p_file);
    }
    return retval;
}


/*
 * sdk:      FSi_CompareDigest (libfs.TWL.HYB.a fs_overlay.o)
 */
/*
 * DRAFT: compiles the whole 252-byte range; verdict pending.
 */
BOOL func_02078F30(const u8 *spec_digest, void *src, int len, BOOL table_mode)
{
    u8 buf[0x14];
    u8 tmp[0x40];
    u32 handle;
    u32 i;

    MI_CpuFill8(buf, 0, 0x14);
    MI_CpuCopy8(FSiOverlayContext.digest_key, tmp, FSiOverlayContext.digest_key_len);

    if (table_mode == 0 && OS_IsRunOnTwl() != 0) {
        func_0209125C(buf, src, len, tmp, FSiOverlayContext.digest_key_len);
    } else {
        handle = 0;
        if (table_mode != 0) {
            handle = func_0208139C(1);
        }
        func_020816FC(buf, src, len, tmp, FSiOverlayContext.digest_key_len);
        if (table_mode != 0) {
            func_0208139C(handle);
        }
    }

    i = 0;
    while (i < 0x14) {
        if (*(u32 *)(buf + i) != *(u32 *)(spec_digest + i)) {
            break;
        }
        i += 4;
    }
    return i == 0x14;
}


/*
 * notes:    bytes identical; SDK_LTDAUTOLOAD_LTDMAIN_START and _BSS_END resolve under the `linker` class (undefined in fs_overlay.o and in libfs; values = layout.json twl ram_start / bss_end)
 *
 * sdk:      FS_StartOverlay (libfs.TWL.HYB.a fs_overlay.o)
 */
void func_0207902C(FSOverlayInfo *p_ovi)
{
    u32 rare_size = func_02078CB0(p_ovi);

    if (((u32)p_ovi->header.ram_address >= (u32)SDK_LTDAUTOLOAD_LTDMAIN_START) &&
        ((u32)p_ovi->header.ram_address < (u32)SDK_LTDAUTOLOAD_LTDMAIN_BSS_END) && OS_IsRunOnTwl())
    {
        if (!once_slot)
        {
            once_slot = 1;
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
                ret = func_02078F30(SDK_OVERLAY_DIGEST + p_ovi->header.id * 20,
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


/*
 * 0x02079164..0x02079264: the callback-flush worker and its one-line
 * wrapper.
 *
 * func_02079164 repeatedly detaches, inside the 0x02087988/0x0208799C
 * critical section, every node of the global list g_021542B8 whose
 * callback argument (+8) falls in the overlay's byte range, or whose
 * callback function (+4) does when the argument is null, then runs the
 * detached callbacks with interrupts restored and starts over.  The
 * branch back to the function header is that restart: a callback may
 * queue new nodes, so the list is rescanned until a pass detaches
 * nothing.  The range is [ram_address, ram_address + ram_size + bss_size).
 *
 * Three things the byte match pinned down, in the order they cost time:
 *
 *  - 0x02087988's result is live in r0 across the whole scan loop and is
 *    0x0208799C's argument (the SDK disable/restore-interrupts pair).
 *    Spelling both as `void f(void)` leaves r0 free, and the allocator
 *    then has one spare register and picks a different colouring for
 *    every local in the function.
 *  - `cur->arg` and `cur->fn` are read into locals before the test, not
 *    referenced inside it: the original loads +4 unconditionally, ahead
 *    of the branch that only one arm of the test needs.
 *  - which locals live in the function scope and which in the `for` body
 *    block decides the colouring outright.  `prev` and `list` outlive the
 *    loop body's declarations here; moving either one inside the block
 *    moves eight or more bytes.
 */
void func_02079164(FSOverlayInfo *p_ovi)
{
    Node02079164 *prev;
    Node02079164 *list;

    for (;;) {
        Node02079164 *head;
        Node02079164 *tail;
        Node02079164 *cur;
        Node02079164 *next;
        u32 lo;
        u32 hi;
        u32 arg;
        u32 fn;
        u32 e;

        head = 0;
        tail = 0;
        lo = (u32)p_ovi->header.ram_address;
        hi = lo + (p_ovi->header.ram_size + p_ovi->header.bss_size);

        e = func_02087988();

        list = g_021542B8;
        prev = 0;
        cur = list;
        while (cur != 0) {
            arg = (u32)cur->arg;
            next = cur->next;
            fn = (u32)cur->fn;
            if ((arg == 0 && fn >= lo && fn < hi) || (arg >= lo && arg < hi)) {
                if (tail != 0) {
                    tail->next = cur;
                } else {
                    head = cur;
                }
                if (list == cur) {
                    g_021542B8 = next;
                    list = next;
                }
                cur->next = 0;
                tail = cur;
                if (prev != 0) {
                    prev->next = next;
                }
            } else {
                prev = cur;
            }
            cur = next;
        }

        func_0208799C(e);

        if (head == 0) {
            return;
        }

        do {
            next = head->next;
            if (head->fn != 0) {
                head->fn(head->arg);
            }
            head = next;
        } while (head != 0);

    }
}

BOOL func_02079254(FSOverlayInfo *p_ovi)
{
    func_02079164(p_ovi);
    return 1;
}


/*
 * sdk:      FS_LoadOverlay (libfs.TWL.HYB.a fs_overlay.o)
 */
BOOL func_02079264(int target, u32 id)
{
    BOOL retval = 0;
    FSOverlayInfo ovi;

    if (func_02078D34(&ovi, target, id) && func_02078EB0(&ovi))
    {
        func_0207902C(&ovi);
        retval = 1;
    }
    return retval;
}


/*
 * Builds the 44-byte overlay info on the stack from (target, id) and, if
 * that succeeded, runs func_02079254 on it once; the result is normalised
 * to 0/1.
 */
/*
 * Builds a 44-byte iterator/descriptor on the stack from (a, b) and, if
 * that succeeded, runs it once; the result is normalised to 0/1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020792B8.c \
 *       --func func_020792B8 --addr 0x020792B8 --cc 1.1p1 --arm
 */
int func_020792B8(int target, u32 id)
{
    FSOverlayInfo ovi;

    if (func_02078D34(&ovi, target, id) != 0 && func_02079254(&ovi) != 0) {
        return 1;
    }
    return 0;
}
