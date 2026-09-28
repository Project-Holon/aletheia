/*
 * function: MBi_get_blockinfo
 * address:  0x021F3A58
 * packet:   pkt_ov107_021F3A58
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_fileinfo.o).  Rebuilt from the SDK source
 * (mb_fileinfo.c) plus the Rom object's DWARF (decl_line 926) and the ROM
 * disassembly.
 *
 * symbols:
 *   mbc   0x021F6FA0  data  a4
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef int BOOL;

typedef struct
{
    u32 child_address;
    u32 size;
    u32 offset;
    u8 segment_no;
}
MB_BlockInfo;

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

#define MB_DL_SEGMENT_NUM 3
#define MBi_GetSegmentInfo(mdfi, i) \
    ((MbSegmentInfo *)((char *)(mdfi) + 0xc + (i) * 16))

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
