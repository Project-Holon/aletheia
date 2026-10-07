/*
 * file:     unit_021F2F1C_p03.c
 * unit:     yes
 * function: func_021F3A58, func_021F3B0C, func_021F3BB8
 * address:  0x021F3A58
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
 *   mbc   0x021F6FA0  data  a4
 *   g_021F6D04     0x021F6D04  data
 */
#define MB_DL_SEGMENT_NUM 3
#define MBi_GetSegmentInfo(mdfi, i) \
    ((MbSegmentInfo *)((char *)(mdfi) + 0xc + (i) * 16))
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

typedef enum {
    SEG_A = 0,
    SEG_B = 1,
    SEG_C = 2
} SegType;

BOOL MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table, u32 block, MbDownloadFileInfoHeader *mdfi);
int func_021F3B0C(u8 segment_no, u32 address, u32 size);
int func_021F3BB8(u8 segment_no, u32 address, u32 size);
extern char *mbc;
extern SegType g_021F6D04[3];


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
