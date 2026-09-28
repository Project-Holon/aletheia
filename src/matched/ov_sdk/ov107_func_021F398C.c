/*
 * function: MBi_MakeBlockInfoTable
 * address:  0x021F398C
 * packet:   pkt_ov107_021F398C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_fileinfo.o).  Rebuilt from the SDK source
 * (mb_fileinfo.c) plus the Rom object's DWARF (decl_line 871) and the ROM
 * disassembly.
 *
 * symbols:
 *   mbc          0x021F6FA0  data  a4
 *   _u32_div_f   0x0209C2B0  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef struct
{
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
}
MB_BlockInfoTable;

typedef struct
{
    u32 recv_addr;
    u32 load_addr;
    u32 size;
    u32 target;
}
MbSegmentInfo;

typedef struct
{
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 reserved;
}
MbDownloadFileInfoHeader;

extern char *mbc;
extern BOOL IsAbleToLoad(u8 segment_no, u32 address, u32 size);

#define MB_DL_SEGMENT_NUM 3
#define MBi_GetSegmentInfo(mdfi, i) \
    ((MbSegmentInfo *)((char *)(mdfi) + 0xc + (i) * 16))
#define MBC_BLOCK_SIZE_MAX (*(u32 *)(mbc + 0x1318))

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
