/*
 * function: MB_ReadSegment
 * address:  0x021F2FA0
 * packet:   pkt_ov107_021F2FA0
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen. Hand-reconstructed from the disassembly; algorithm and
 *   control flow transcribed from the listing.
 *
 * sdk:      MB_ReadSegment (libmb.TWL.HYB.a mb_fileinfo.o)
 *
 * symbols:
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
 *   _start_AutoloadDoneCallback      0x02004EA8  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    void *arc;
    u32 stat;
    void *argument;
    u32 error;
    u8 pad[0x48 - 0x18];
} FSFile;

typedef struct RomHeader {
    u8 pad0[0x12];
    u8 machine_code;
    u8 pad1[0x20 - 0x13];
    u32 main_rom_offset;
    u32 main_entry;
    u32 main_ram_address;
    u32 main_size;
    u32 sub_rom_offset;
    u32 sub_entry;
    u32 sub_ram_address;
    u32 sub_size;
    u8 pad2[0x60 - 0x40];
    u32 flags;
    u8 pad3[0x80 - 0x64];
    u32 own_size;
} RomHeader;

typedef struct CARDRomRegion {
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct MBiCacheList {
    u32 lifetime;
    u32 recent;
    void *p_list;
    u32 size;
    char arc_name[4];
    u32 arc_name_len;
    void *arc_pointer;
    u8 reserved[0x48 - 0x1c];
    u8 *p_buf;
} MBiCacheList;

typedef struct SegmentHeaderInfo {
    u32 target;
    u8 *src;
    u8 *dst;
    u32 size;
} SegmentHeaderInfo;

extern void *CARD_GetOwnRomHeader(void);
extern u32 FS_GetFilePosition(FSFile *file);
extern long FS_ReadFile(FSFile *file, void *buffer, long length);
extern void FS_InitFile(FSFile *file);
extern void *FS_FindArchive(char *name, int name_len);
extern int FS_OpenFileDirect(FSFile *file, void *arc, u32 image_top, u32 image_bottom, u32 id);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern u8 *CARDi_GetOwnSignature(void);
extern int FS_SeekFile(FSFile *file, long offset, int origin);
extern void MBi_InitCache(MBiCacheList *pl);
extern void MBi_AttachCacheBuffer(MBiCacheList *pl, u32 src, u32 len, void *ptr, u32 state);
extern u32 FS_GetFileImageTop(FSFile *file);
extern int FS_CloseFile(FSFile *file);
extern void MBi_ReadSegmentHeader(SegmentHeaderInfo *p, u32 top, u32 bottom, int clean);
extern void DC_FlushRange(void *startAddr, u32 nBytes);

extern char d_021F6E54[];
extern CARDRomRegion mbi_seg_header_default[3];
extern CARDRomRegion *mbi_seg_header;
extern CARDRomRegion _ZZ14MB_ReadSegmentP6FSFilePvmE18mbi_seg_header_twl[3];
extern u32 _start_AutoloadDoneCallback[];

int MB_ReadSegment(FSFile *file, void *buf, u32 len)
{
    FSFile own_bin[1];
    FSFile *afile;
    SegmentHeaderInfo info;
    RomHeader *p_rom;
    u32 *p_header;
    MBiCacheList *p_cache;
    CARDRomRegion *p_map;
    u8 *mainBuf;
    u32 mainSize;
    u32 base;
    u32 own_size;
    u32 rest;
    u32 bak_pos;
    u32 main_size;
    u32 sub_size;
    int is_own_binary;
    int ret;
    int i;

    ret = 0;
    afile = file;

    if (file == 0) {
        p_rom = (RomHeader *)CARD_GetOwnRomHeader();
        if (p_rom->machine_code & 2)
            mbi_seg_header = _ZZ14MB_ReadSegmentP6FSFilePvmE18mbi_seg_header_twl;
        else
            mbi_seg_header = mbi_seg_header_default;
    }

    if (len < 0x164)
        return ret;

    p_cache = 0;
    is_own_binary = 0;
    mainBuf = (u8 *)buf + 0x160;
    rest = len - 0x160;

    if (file != 0) {
        bak_pos = FS_GetFilePosition(file);
        if ((long)FS_ReadFile(file, buf, 0x160) < 0x160)
            rest = 0;
        own_size = ((RomHeader *)buf)->own_size;
        if (own_size == 0)
            own_size = 0x1000000;
    } else {
        p_rom = (RomHeader *)0x02FFFE00;
        own_size = p_rom->own_size;
        is_own_binary = 1;
        if (own_size == 0)
            own_size = 0x1000000;
        afile = own_bin;
        FS_InitFile(afile);
        if (FS_OpenFileDirect(afile, FS_FindArchive(d_021F6E54, 3), 0, own_size + 0x88, (u32)-1) == 0)
            return 0;
        bak_pos = FS_GetFilePosition(afile);
        MI_CpuCopy8((void *)0x02FFFE00, buf, 0x160);
        ((RomHeader *)buf)->flags |= 0x6000;
        ((RomHeader *)buf)->flags |= 0x400000;
    }

    main_size = ((RomHeader *)buf)->main_size;
    sub_size = ((RomHeader *)buf)->sub_size;

    if (rest < 0x88) {
        rest = 0;
        goto l_cache;
    }
    if (is_own_binary) {
        MI_CpuCopy8(CARDi_GetOwnSignature(), mainBuf, 0x88);
    } else {
        FS_SeekFile(afile, bak_pos + own_size, 0);
        FS_ReadFile(afile, mainBuf, 0x88);
    }
    mainBuf += 0x88;
    rest -= 0x88;

l_cache:
    if (rest < 0x70) {
        rest = 0;
        goto l_header;
    }
    p_cache = (MBiCacheList *)mainBuf;
    MBi_InitCache(p_cache);
    MBi_AttachCacheBuffer(p_cache, 0, 0x160, buf, 3);
    mainBuf += 0x70;
    rest -= 0x70;
    {
        char *arc = (char *)afile->arc;
        for (i = 0; i < 3; i++)
            if (arc[i] == 0)
                break;
        MI_CpuCopy8(arc, (u8 *)p_cache + 0x10, (u32)i);
        *(u32 *)((u8 *)p_cache + 0x14) = (u32)i;
        *(void **)((u8 *)p_cache + 0x18) = arc;
    }
    goto l_afterheader;

l_header:
    rest = 0;

l_afterheader:
    if (rest < 0x10) {
        rest = 0;
        goto l_afterinfoheader;
    }
    p_header = (u32 *)mainBuf;
    p_header[0] = 0;
    p_header[1] = ((RomHeader *)buf)->main_rom_offset + (bak_pos + FS_GetFileImageTop(afile));
    p_header[2] = ((RomHeader *)buf)->sub_rom_offset + (bak_pos + FS_GetFileImageTop(afile));
    mainBuf += 0x10;
    rest -= 0x10;

l_afterinfoheader:
    mainSize = main_size + sub_size;
    if (rest < mainSize)
        goto l_big;

    base = FS_GetFileImageTop(afile);
    {
        u32 v1 = p_header[1] - base;
        u32 readlen = main_size;
        u8 *rdst = mainBuf;

        if (is_own_binary && v1 < 0x8000) {
            u32 skip = 0x8000 - v1;
            readlen = main_size - skip;
            rdst = mainBuf + skip;
            v1 = 0x8000;
        }
        FS_SeekFile(afile, v1, 0);
        FS_ReadFile(afile, rdst, readlen);
        MBi_AttachCacheBuffer(p_cache, p_header[1], main_size, mainBuf, 3);
        FS_SeekFile(afile, (long)(p_header[2] - base), 0);
        FS_ReadFile(afile, mainBuf + main_size, sub_size);
        MBi_AttachCacheBuffer(p_cache, p_header[2], sub_size, mainBuf + main_size, 3);
    }
    goto l_done;

l_big:
    if (rest < 0xcc00)
        goto l_restore;
    base = FS_GetFileImageTop(afile);
    {
        u32 v1 = p_header[1] - base;
        u32 readlen = 0x4400;
        u8 *rdst = mainBuf;

        if (is_own_binary && v1 < 0x8000) {
            u32 skip = 0x8000 - v1;
            readlen = 0x4400 - skip;
            rdst = mainBuf + skip;
            v1 = 0x8000;
        }
        FS_SeekFile(afile, v1, 0);
        FS_ReadFile(afile, rdst, readlen);
        MBi_AttachCacheBuffer(p_cache, p_header[1], 0x4400, mainBuf, 3);
        FS_SeekFile(afile, (long)(p_header[1] + 0x4400 - base), 0);
        FS_ReadFile(afile, mainBuf + 0x4400, 0x4400);
        MBi_AttachCacheBuffer(p_cache, p_header[1] + 0x4400, 0x4400, mainBuf + 0x4400, 2);
        FS_SeekFile(afile, (long)(p_header[1] + 0x8800 - base), 0);
        FS_ReadFile(afile, mainBuf + 0x8800, 0x4400);
        MBi_AttachCacheBuffer(p_cache, p_header[1] + 0x8800, 0x4400, mainBuf + 0x8800, 2);
    }

l_done:
    ret = 1;

l_restore:
    FS_SeekFile(afile, bak_pos, 0);
    if (is_own_binary) {
        FS_CloseFile(own_bin);
        if (ret) {
            info.target = ((RomHeader *)buf)->main_rom_offset;
            info.src = (u8 *)(((RomHeader *)buf)->main_ram_address - info.target);
            info.dst = (u8 *)((u32)p_cache->p_buf - info.target);
            info.size = len;
            MBi_ReadSegmentHeader(&info, 0x4000, 0x8000, 1);
            p_map = mbi_seg_header;
            while (p_map->length != 0) {
                MBi_ReadSegmentHeader(&info, p_map->offset, p_map->offset + p_map->length, 0);
                p_map++;
            }
            *(u32 *)(p_cache->p_buf + (0x02004EA8 - ((RomHeader *)buf)->main_ram_address)) = 0xE12FFF1E;
        }
    }

    if (ret)
        DC_FlushRange(buf, len);
    return ret;
}
