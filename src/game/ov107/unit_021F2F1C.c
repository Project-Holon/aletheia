/*
 * file:     unit_021F2F1C.c
 * unit:     yes
 * function: func_021F2F1C, func_021F2FA0, func_021F34CC, MB_RegisterFile, MBi_MakeDownloadFileInfo, func_021F3830, func_021F398C, func_021F3A58, func_021F3B0C, func_021F3BB8
 * address:  0x021F2F1C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02078AEC  0x02078AEC  arm
 *   func_02078B70  0x02078B70  arm
 *   func_02078B44  0x02078B44  arm
 *   CARD_GetOwnRomHeader             0x02075DF8  arm
 *   FS_GetFilePosition               0x02078AEC  arm
 *   FS_ReadFile                      0x02078B70  arm
 *   FS_InitFile                      0x020788AC  arm
 *   FS_FindArchive                   0x02077EB8  arm
 *   FS_OpenFileDirect                0x02078964  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   CARDi_GetOwnSignature            0x020773D0  arm
 *   FS_SeekFile                      0x02078B44  arm
 *   MBi_InitCache                    0x021F636C  arm
 *   MBi_AttachCacheBuffer            0x021F6380  arm
 *   FS_GetFileImageTop               0x0207A7BC  arm
 *   FS_CloseFile                     0x02078A80  arm
 *   MBi_ReadSegmentHeader            0x021F34CC  arm
 *   DC_FlushRange                    0x020862F0  arm
 *   d_021F6E54                       0x021F6E54  data
 *   mbi_seg_header_default           0x021F6D10  data
 *   mbi_seg_header                   0x021F6E50  data
 *   _ZZ14MB_ReadSegmentP6FSFilePvmE18mbi_seg_header_twl  0x021F6D28  data
 *   _start_AutoloadDoneCallback      0x02004EA8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *   OS_DisableInterrupts     0x02087988  arm
 *   MBi_IsStarted            0x021F6314  arm  ov107
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   MBi_MakeGameInfo         0x021F3D04  arm  ov107
 *   MB_AddGameInfo           0x021F3F34  arm  ov107
 *   MBi_IsTaskAvailable      0x021F6610  arm  ov107
 *   MBi_InitTaskInfo         0x021F662C  arm  ov107
 *   MBi_InitTaskThread       0x021F6590  arm  ov107
 *   mbc                      0x021F6FA0  data
 *   _ZZ15MB_RegisterFileP14MBGameRegistryPvE6update  0x021F6EF0  data
 *   MBi_defaultLoadSegList  0x021F6D04  data  a4
 *   func_02088234  0x02088234  arm
 *   _u32_div_f   0x0209C2B0  arm
 *   g_021F6D04     0x021F6D04  data
 */
#define BUFROM(f) (((RomHeader_021F2FA0 *)buf)->f)
#define E(i) ((unsigned char *)mbc + (i) * 0x5D4 + 0x1000)
#define MB_DL_SEGMENT_NUM 3
#define MBC_BLOCK_SIZE_MAX (*(u32 *)(mbc + 0x1318))
#define MBi_GetSegmentInfo(mdfi, i) \
    ((MbSegmentInfo *)((char *)(mdfi) + 0xc + (i) * 16))
struct FSFile;
struct MbDownloadFileInfoHeader;
struct MBGameRegistry;
typedef unsigned char u8;

typedef unsigned long u32_021F2F1C;

typedef struct {
    u8 pad0[0x2C];
    u32_021F2F1C arm9Size;
    u8 pad1[0x0C];
    u32_021F2F1C arm7Size;
} RomHeader_021F2F1C;

typedef signed int     s32;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    void *arc;
    u32_021F2F1C stat;
    void *argument;
    u32_021F2F1C error;
    u8 pad[0x48 - 0x18];
} FSFile;

typedef struct RomHeader_021F2FA0 {
    u8 pad0[0x12];
    u8 machine_code;
    u8 pad1[0x20 - 0x13];
    u32_021F2F1C main_rom_offset;
    u32_021F2F1C main_entry;
    u32_021F2F1C main_ram_address;
    u32_021F2F1C main_size;
    u32_021F2F1C sub_rom_offset;
    u32_021F2F1C sub_entry;
    u32_021F2F1C sub_ram_address;
    u32_021F2F1C sub_size;
    u8 pad2[0x60 - 0x40];
    u32_021F2F1C flags;
    u8 pad3[0x80 - 0x64];
    u32_021F2F1C own_size;
} RomHeader_021F2FA0;

typedef struct CARDRomRegion {
    u32_021F2F1C offset;
    u32_021F2F1C length;
} CARDRomRegion;

typedef struct MBiCacheList {
    u32_021F2F1C lifetime;
    u32_021F2F1C recent;
    void *p_list;
    u32_021F2F1C size;
    char arc_name[4];
    u32_021F2F1C arc_name_len;
    void *arc_pointer;
    u8 reserved[0x48 - 0x1c];
    u8 *p_buf;
} MBiCacheList;

typedef struct SegmentHeaderInfo_021F2F1C {
    u32_021F2F1C target;
    u8 *src;
    u8 *dst;
    u32_021F2F1C size;
} SegmentHeaderInfo_021F2F1C;

typedef struct {
    u32_021F2F1C target;
    u8 *src;
    u8 *dst;
    u32_021F2F1C size;
} SegmentHeaderInfo_021F34CC;

typedef unsigned short u16;

typedef unsigned int   u32_021F3544;

typedef unsigned long u32;

typedef struct MbSegmentInfo
{
    u32 recv_addr;
    u32 load_addr;
    u32 size;
    u32 target : 1;
}
MbSegmentInfo;

typedef struct MbDownloadFileInfoHeader
{
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 reserved;
}
MbDownloadFileInfoHeader;

typedef signed char s8;

typedef int BOOL;

typedef struct {
    u32 offset;
    u32 entry;
    u32 ram_address;
    u32 size;
} RomRegion;

typedef struct {
    u8 pad0[0x20];
    RomRegion main;
    RomRegion sub;
} RomHeader;

typedef struct
{
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
}
MB_BlockInfoTable;

typedef struct
{
    u32 child_address;
    u32 size;
    u32 offset;
    u8 segment_no;
}
MB_BlockInfo;

typedef enum {
    SEG_A = 0,
    SEG_B = 1,
    SEG_C = 2
} SegType;

extern u32_021F2F1C func_02078AEC(struct FSFile *file);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern void *CARD_GetOwnRomHeader(void);
extern u32_021F2F1C FS_GetFilePosition(FSFile *file);
extern long FS_ReadFile(FSFile *file, void *buffer, long length);
extern void FS_InitFile(FSFile *file);
extern void *FS_FindArchive(char *name, int name_len);
extern int FS_OpenFileDirect(FSFile *file, void *arc, u32_021F2F1C image_top, u32_021F2F1C image_bottom, u32_021F2F1C id);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32_021F2F1C size);
extern u8 *CARDi_GetOwnSignature(void);
extern int FS_SeekFile(FSFile *file, long offset, int origin);
extern void MBi_InitCache(MBiCacheList *pl);
extern void MBi_AttachCacheBuffer(MBiCacheList *pl, u32_021F2F1C src, u32_021F2F1C len, void *ptr, u32_021F2F1C state);
extern u32_021F2F1C FS_GetFileImageTop(FSFile *file);
extern int FS_CloseFile(FSFile *file);
extern void MBi_ReadSegmentHeader(SegmentHeaderInfo_021F2F1C *p, u32_021F2F1C top, u32_021F2F1C bottom, int clean);
extern void DC_FlushRange(void *startAddr, u32_021F2F1C nBytes);
extern void _start_AutoloadDoneCallback(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern unsigned long OS_DisableInterrupts(void);
extern int MBi_IsStarted(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MBi_MakeGameInfo(void *, struct MBGameRegistry *, void *);
extern void MB_AddGameInfo(void *);
extern int MBi_IsTaskAvailable(void);
extern void MBi_InitTaskInfo(void *);
extern void MBi_InitTaskThread(void *, unsigned long);
extern void func_02088234(void);
extern BOOL IsAbleToLoad(u8 segment_no, u32 address, u32 size);
u32_021F2F1C func_021F2F1C(void *file);
int MB_ReadSegment(FSFile *file, void *buf, u32_021F2F1C len);
void func_021F34CC(SegmentHeaderInfo_021F34CC *p, u32_021F2F1C top, u32_021F2F1C bottom, int clean);
int MB_RegisterFile(struct MBGameRegistry *game_reg, void *buf);
void MBi_MakeDownloadFileInfo(MbDownloadFileInfoHeader *mbdlFileInfop, const void *buf);
void MBi_SetSegmentInfo(const RomHeader *hdr, SegType *list, MbSegmentInfo *seg, u32 *child_recv);
BOOL MBi_MakeBlockInfoTable(MB_BlockInfoTable *table, MbDownloadFileInfoHeader *mdfi);
BOOL MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table, u32 block, MbDownloadFileInfoHeader *mdfi);
int func_021F3B0C(u8 segment_no, u32 address, u32 size);
int func_021F3BB8(u8 segment_no, u32 address, u32 size);
extern char d_021F6E54[];
extern CARDRomRegion mbi_seg_header_default[3];
extern CARDRomRegion *mbi_seg_header;
extern CARDRomRegion _ZZ14MB_ReadSegmentP6FSFilePvmE18mbi_seg_header_twl[3];
extern unsigned char *mbc;
extern const u32 MBi_defaultLoadSegList[];
extern SegType g_021F6D04[3];






/*
 * sdk:      MB_GetSegmentLength (libmb.TWL.HYB.a mb_fileinfo.o)
 */
u32_021F2F1C func_021F2F1C(void *file)
{
    u8 rom[96];
    RomHeader_021F2F1C *p;
    u32_021F2F1C ret;
    u32_021F2F1C bak_pos;

    p = 0;
    ret = 0;
    if (file) {
        bak_pos = func_02078AEC(file);
        if ((u32_021F2F1C)func_02078B70(file, rom, 96) >= 96)
            p = (RomHeader_021F2F1C *)rom;
        func_02078B44(file, bak_pos, 0);
    } else {
        p = (RomHeader_021F2F1C *)0x02FFFE00;
    }
    if (p) {
        ret = p->arm9Size + 0x268 + p->arm7Size;
        if (ret < 0x10000)
            ret = 0x10000;
    }
    return ret;
}






int MB_ReadSegment(FSFile *file, void *buf, u32_021F2F1C len)
{
    FSFile own_bin[1];
    SegmentHeaderInfo_021F2F1C info;
    int ret;
    int is_own_binary;
    u32_021F2F1C bak_pos;
    RomHeader_021F2FA0 *p_rom;
    u32_021F2F1C rest;
    u8 *dst;
    MBiCacheList *p_cache;
    u32_021F2F1C own_size;
    CARDRomRegion *p_map;
    u32_021F2F1C *p_header;
    int i;
    ret = 0;

    if (file == 0) {
        p_rom = (RomHeader_021F2FA0 *)CARD_GetOwnRomHeader();
        if ((p_rom->machine_code & 2) == 0)
            mbi_seg_header = mbi_seg_header_default;
        else
            mbi_seg_header = _ZZ14MB_ReadSegmentP6FSFilePvmE18mbi_seg_header_twl;
    }

    if (len >= 0x164) {
        p_cache = 0;
        is_own_binary = 0;
        p_header = 0;
        dst = (u8 *)buf + 0x160;
        rest = len - 0x160;

        if (file != 0) {
            bak_pos = FS_GetFilePosition(file);
            if ((long)FS_ReadFile(file, buf, 0x160) < 0x160)
                rest = 0;
            own_size = BUFROM(own_size);
            if (own_size == 0)
                own_size = 0x1000000;
        } else {
            p_rom = (RomHeader_021F2FA0 *)0x02FFFE00;
            own_size = p_rom->own_size;
            is_own_binary = 1;
            if (own_size == 0)
                own_size = 0x1000000;
            file = own_bin;
            FS_InitFile(file);
            if (FS_OpenFileDirect(file, FS_FindArchive(d_021F6E54, 3), 0, own_size + 0x88, (u32_021F2F1C)-1) == 0)
                return 0;
            bak_pos = FS_GetFilePosition(file);
            MI_CpuCopy8((void *)0x02FFFE00, buf, 0x160);
            BUFROM(flags) |= 0x6000;
            BUFROM(flags) |= 0x400000;
        }

        if (rest >= 0x88) {
            if (is_own_binary) {
                MI_CpuCopy8(CARDi_GetOwnSignature(), dst, 0x88);
            } else {
                FS_SeekFile(file, bak_pos + own_size, 0);
                FS_ReadFile(file, dst, 0x88);
            }
            dst += 0x88;
            rest -= 0x88;
        } else {
            rest = 0;
        }

        if (rest >= 0x70) {
            char *arc;

            p_cache = (MBiCacheList *)dst;
            MBi_InitCache(p_cache);
            dst += 0x70;
            rest -= 0x70;
            MBi_AttachCacheBuffer(p_cache, 0, 0x160, buf, 3);
            arc = (char *)file->arc;
            i = 0;
            while (i < 3 && arc[i] != 0)
                i++;
            MI_CpuCopy8(arc, (u8 *)p_cache + 0x10, (u32_021F2F1C)i);
            *(u32_021F2F1C *)((u8 *)p_cache + 0x14) = (u32_021F2F1C)i;
            *(void **)((u8 *)p_cache + 0x18) = arc;
        } else {
            rest = 0;
        }

        if (rest >= 0x10) {
            p_header = (u32_021F2F1C *)dst;
            p_header[0] = 0;
            p_header[1] = BUFROM(main_rom_offset) + (bak_pos + FS_GetFileImageTop(file));
            p_header[2] = BUFROM(sub_rom_offset) + (bak_pos + FS_GetFileImageTop(file));
            dst += 0x10;
            rest -= 0x10;
        } else {
            rest = 0;
        }

        if (rest >= BUFROM(main_size) + BUFROM(sub_size)) {
            u8 *mainBuf;
            u32_021F2F1C mainTop;
            u32_021F2F1C base;
            u32_021F2F1C mainSize;

            base = FS_GetFileImageTop(file);
            mainTop = p_header[1] - base;
            mainBuf = dst;
            mainSize = BUFROM(main_size);
            if (is_own_binary) {
                if (mainTop < 0x8000) {
                    u32_021F2F1C skip = 0x8000 - mainTop;

                    mainSize -= skip;
                    mainBuf += skip;
                    mainTop = 0x8000;
                }
            }
            FS_SeekFile(file, mainTop, 0);
            FS_ReadFile(file, mainBuf, mainSize);
            MBi_AttachCacheBuffer(p_cache, p_header[1], BUFROM(main_size), dst, 3);
            mainSize = BUFROM(main_size);
            FS_SeekFile(file, p_header[2] - base, 0);
            FS_ReadFile(file, dst + mainSize, BUFROM(sub_size));
            MBi_AttachCacheBuffer(p_cache, p_header[2], BUFROM(sub_size), dst + mainSize, 3);
            ret = 1;
        } else if (rest >= 0xcc00) {
            u8 *mainBuf;
            u32_021F2F1C mainTop;
            u32_021F2F1C base;
            u32_021F2F1C mainSize;
            u32_021F2F1C p1;

            base = FS_GetFileImageTop(file);
            p1 = p_header[1];
            mainBuf = dst;
            mainTop = p1 - base;
            mainSize = 0x4400;
            if (is_own_binary) {
                if (mainTop < 0x8000) {
                    u32_021F2F1C skip = 0x8000 - mainTop;

                    mainSize -= skip;
                    mainBuf += skip;
                    mainTop = 0x8000;
                }
            }
            FS_SeekFile(file, mainTop, 0);
            FS_ReadFile(file, mainBuf, mainSize);
            mainSize = 0x4400;
            MBi_AttachCacheBuffer(p_cache, p1, mainSize, dst, 3);
            FS_SeekFile(file, p1 + 0x4400 - base, 0);
            FS_ReadFile(file, dst + 0x4400, mainSize);
            MBi_AttachCacheBuffer(p_cache, p1 + 0x4400, mainSize, dst + 0x4400, 2);
            FS_SeekFile(file, p1 + 0x8800 - base, 0);
            FS_ReadFile(file, dst + 0x8800, mainSize);
            MBi_AttachCacheBuffer(p_cache, p1 + 0x8800, mainSize, dst + 0x8800, 2);
            ret = 1;
        }

        FS_SeekFile(file, bak_pos, 0);
        if (is_own_binary) {
            FS_CloseFile(own_bin);
            if (ret) {
                u8 *dst2;

                info.target = BUFROM(main_rom_offset);
                info.src = (u8 *)(BUFROM(main_ram_address) - info.target);
                info.dst = (u8 *)((u32_021F2F1C)p_cache->p_buf - info.target);
                info.size = len;
                p_map = mbi_seg_header;
                MBi_ReadSegmentHeader(&info, 0x4000, 0x8000, 1);
                while (p_map->length != 0) {
                    u32_021F2F1C *w = (u32_021F2F1C *)p_map;

                    MBi_ReadSegmentHeader(&info, w[0], w[0] + w[1], 0);
                    p_map++;
                }
                dst2 = (u8 *)p_cache->p_buf;
                dst2 += ((u32_021F2F1C)&_start_AutoloadDoneCallback - BUFROM(main_ram_address));
                *(u32_021F2F1C *)dst2 = 0xE12FFF1E;
            }
        }

        if (ret)
            DC_FlushRange(buf, len);
    }
    return ret;
}





/*
 * sdk:      MBi_ReadSegmentHeader (libmb.TWL.HYB.a mb_fileinfo.o)
 */
void func_021F34CC(SegmentHeaderInfo_021F34CC *p, u32_021F2F1C top, u32_021F2F1C bottom, int clean)
{
    if (top < 0x4000)
        top = 0x4000;
    if (bottom > 0x8000)
        bottom = 0x8000;
    if (top < p->target)
        top = p->target;
    if (bottom > p->target + p->size)
        bottom = p->target + p->size;
    if (top >= bottom)
        return;
    if (clean) {
        MI_CpuFill8(p->dst + top, 0, bottom - top);
        return;
    }
    func_02082D44(p->src + top, p->dst + top, bottom - top);
}




int MB_RegisterFile(struct MBGameRegistry *game_reg, void *buf)
{
    struct MbDownloadFileInfoHeader *mdfi;
    static unsigned char update = 0;
    unsigned char i;
    unsigned char fileID = 0xff;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (!MBi_IsStarted())
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (*(unsigned char *)((unsigned char *)mbc + 0x1524) + 1 > 0x10)
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }

    for (i = 0; i < 0x10; i++)
    {
        if (*(struct MBGameRegistry **)(E(i) + 0xd40) == game_reg)
        {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        if (*(u8 *)(E(i) + 0xd52) == 0)
        {
            fileID = i;
            break;
        }
    }
    if (i == 0x10)
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }

    *(u32_021F3544 *)(E(fileID) + 0xd40) = (u32_021F3544)game_reg;
    mdfi = (struct MbDownloadFileInfoHeader *)((unsigned char *)mbc + 0x1788 + fileID * 0x5D4);
    MBi_MakeDownloadFileInfo(mdfi, buf);
    MI_CpuCopy8((unsigned char *)game_reg + 0x1c, (unsigned char *)mdfi + 0xc4, 0x20);
    if (!MBi_MakeBlockInfoTable((MB_BlockInfoTable *)((unsigned char *)mbc + 0x1d2c + fileID * 0x5D4), mdfi))
    {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    MBi_MakeGameInfo((unsigned char *)mbc + 0x186c + fileID * 0x5D4, game_reg,
                     (unsigned char *)mbc + 0x1300);
    *(u8 *)(E(fileID) + 0xd21) = fileID;
    MB_AddGameInfo((unsigned char *)mbc + 0x186c + fileID * 0x5D4);
    *(u8 *)(E(fileID) + 0xd1f) = update++;
    *(u16 *)(E(fileID) + 0xd4e) = 1;
    *(u32_021F3544 *)(E(fileID) + 0xd44) = (u32_021F3544)buf;
    *(u32_021F3544 *)(E(fileID) + 0xd54) = (u32_021F3544)buf + 0x1e8;
    *(u32_021F3544 *)(E(fileID) + 0xd58) = (u32_021F3544)buf + 0x258;
    if (*(u32_021F3544 *)(*(u32_021F3544 *)(E(fileID) + 0xd54) + 0x6c) != 0 && !MBi_IsTaskAvailable())
    {
        MBi_InitTaskInfo((unsigned char *)mbc + 0x7ce0);
        MBi_InitTaskThread((unsigned char *)mbc + 0x74e0, 0x800);
    }
    *(u8 *)(E(fileID) + 0xd52) = 1;
    *(unsigned char *)((unsigned char *)mbc + 0x1524) += 1;
    OS_RestoreInterrupts(enabled);
    return 1;
}



void MBi_MakeDownloadFileInfo(MbDownloadFileInfoHeader *mbdlFileInfop, const void *buf)
{
    const u32 *loadSegListp;
    MbSegmentInfo *seg_infop;
    int seg_num;
    u32 child_recv_buff_addr = 0x022c0000;

    mbdlFileInfop->arm9EntryAddr = *(const u32 *)((const char *)buf + 0x24);
    mbdlFileInfop->arm7EntryAddr = *(const u32 *)((const char *)buf + 0x34);

    seg_infop = (MbSegmentInfo *)(mbdlFileInfop + 1);
    loadSegListp = MBi_defaultLoadSegList;

    for (seg_num = 0; seg_num < 3; seg_num++)
    {
        MBi_SetSegmentInfo((const RomHeader *)buf, (SegType *)loadSegListp, seg_infop, &child_recv_buff_addr);
        seg_infop++;
        loadSegListp++;
    }

    MI_CpuCopy8((const char *)buf + 0x160, (char *)mbdlFileInfop + 0x3c, 0x88);
}





void MBi_SetSegmentInfo(const RomHeader *hdr, SegType *list, MbSegmentInfo *seg, u32 *child_recv)
{
    const RomRegion *romRegp;

    switch (*list) {
    case SEG_A:
        romRegp = &hdr->main;
        if (romRegp->ram_address >= 0x2000000 && romRegp->ram_address < 0x22C0000
            && (romRegp->ram_address + romRegp->size) <= 0x22C0000) {
            seg->size = romRegp->size;
            seg->load_addr = romRegp->ram_address;
            seg->recv_addr = seg->load_addr;
            seg->target = 0;
        } else {
            func_02088234();
        }
        break;
    case SEG_B: {
        int reload_flag;
        int error_flag;
        u32 load_last_addr;

        reload_flag = error_flag = 0;
        romRegp = &hdr->sub;
        load_last_addr = romRegp->ram_address + romRegp->size;
        if (romRegp->ram_address >= 0x2000000 && romRegp->ram_address < 0x23FE800) {
            if (load_last_addr <= 0x2300000) {
            } else if (load_last_addr < 0x23FE800 && romRegp->size <= 0x40000) {
                reload_flag = 1;
            } else {
                error_flag = 1;
            }
        } else if (romRegp->ram_address >= 0x3040000 && romRegp->ram_address < 0x3057000) {
            if (load_last_addr <= 0x3057000)
                reload_flag = 1;
            else
                error_flag = 1;
        } else {
            error_flag = 1;
        }
        if (error_flag == 1)
            func_02088234();
        seg->size = romRegp->size;
        seg->load_addr = romRegp->ram_address;
        if (!reload_flag) {
            seg->recv_addr = seg->load_addr;
        } else {
            seg->recv_addr = *child_recv;
            *child_recv += seg->size;
        }
        seg->target = 1;
        break;
    }
    case SEG_C:
        seg->size = 0x160;
        seg->load_addr = 0x27FFE00;
        seg->recv_addr = seg->load_addr;
        seg->target = 0;
        break;
    }
}




BOOL MBi_MakeBlockInfoTable(MB_BlockInfoTable *table, MbDownloadFileInfoHeader *mdfi)
{
    u16 *seg_headB = table->seg_head_blockno;
    u32 *seg_src = table->seg_src_offset;
    u8 i;
    u32 src_ofs = 0;

    if (!mdfi)
        return 0;

    for (i = 0; i < MB_DL_SEGMENT_NUM; ++i)
    {
        MbSegmentInfo *si = MBi_GetSegmentInfo(mdfi, i);
        seg_src[i] = src_ofs;
        src_ofs += si->size;
    }

    seg_headB[0] = 0;

    for (i = 0; i < MB_DL_SEGMENT_NUM; ++i)
    {
        MbSegmentInfo *si = MBi_GetSegmentInfo(mdfi, i);
        u16 next_block_head =
            (u16)(seg_headB[i] + (u16)((si->size + MBC_BLOCK_SIZE_MAX - 1) / MBC_BLOCK_SIZE_MAX));

        if (!IsAbleToLoad(i, si->load_addr, si->size))
        {
            return 0;
        }

        if (i < MB_DL_SEGMENT_NUM - 1)
        {
            seg_headB[i + 1] = next_block_head;
        }
        else
        {
            table->block_num = next_block_head;
        }
    }

    return 1;
}





BOOL MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table,
                       u32 block, MbDownloadFileInfoHeader *mdfi)
{
    s8 i;
    u32 seg_block, block_adr_offset;

    if (block >= table->block_num)
    {
        return 0;
    }

    for (i = MB_DL_SEGMENT_NUM - 1; i >= 0; i--)
    {
        if (block >= table->seg_head_blockno[i])
        {
            break;
        }
    }

    if (i < 0)
        return 0;

    seg_block = block - table->seg_head_blockno[i];
    block_adr_offset = seg_block * *(u32 *)(mbc + 0x1318);

    {
        MbSegmentInfo *si = MBi_GetSegmentInfo(mdfi, i);
        bi->size = si->size - block_adr_offset;
        if (bi->size > *(u32 *)(mbc + 0x1318))
            bi->size = *(u32 *)(mbc + 0x1318);
        bi->offset = block_adr_offset + table->seg_src_offset[i];
        bi->child_address = block_adr_offset + si->recv_addr;
        bi->segment_no = (u8)i;
    }

    return 1;
}




/*
 * sdk:      MBi_IsAbleToRecv (libmb.TWL.HYB.a mb_fileinfo.o)
 */
int func_021F3B0C(u8 segment_no, u32 address, u32 size)
{
    SegType seg_type = g_021F6D04[segment_no];

    switch (seg_type) {
    case SEG_C:
        if (address >= 0x027FFE00 && address + size <= 0x027FFE00 + 0x160)
            return 1;
        break;
    case SEG_A:
        if (address >= 0x02000000 && address + size <= 0x022C0000)
            return 1;
        break;
    case SEG_B:
        if (address >= 0x022C0000 && address + size <= 0x02300000)
            return 1;
        if (address >= 0x02000000 && address + size <= 0x02300000)
            return 1;
        break;
    default:
        return 0;
    }
    return 0;
}




/*
 * sdk:      IsAbleToLoad (libmb.TWL.HYB.a mb_fileinfo.o)
 */
int func_021F3BB8(u8 segment_no, u32 address, u32 size)
{
    SegType seg_type = g_021F6D04[segment_no];
    u32 end_adr;

    switch (seg_type) {
    case SEG_A:
    case SEG_C:
        return func_021F3B0C(segment_no, address, size);
    case SEG_B:
        if (address >= 0x02000000 && address < 0x023FE800) {
            end_adr = address + size;
            if (address < 0x02300000) {
                if (end_adr > 0x02300000)
                    return 0;
            }
            if (end_adr <= 0x02300000)
                return 1;
            if (end_adr < 0x023FE800 && size <= 0x40000)
                return 1;
            return 0;
        }
        if (address >= 0x03040000 && address < 0x03057000) {
            end_adr = address + size;
            if (end_adr <= 0x03057000)
                return 1;
            return 0;
        }
        break;
    default:
        return 0;
    }
    return 0;
}
