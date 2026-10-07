/*
 * file:     unit_021F2F1C_p02.c
 * unit:     yes
 * function: func_021F3830, func_021F398C
 * address:  0x021F3830
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
 *   func_02088234  0x02088234  arm
 *   mbc          0x021F6FA0  data  a4
 *   _u32_div_f   0x0209C2B0  arm
 */
#define MB_DL_SEGMENT_NUM 3
#define MBi_GetSegmentInfo(mdfi, i) \
    ((MbSegmentInfo *)((char *)(mdfi) + 0xc + (i) * 16))
#define MBC_BLOCK_SIZE_MAX (*(u32_021F398C *)(mbc + 0x1318))
typedef unsigned char u8;

typedef unsigned int u32_021F3830;

typedef struct {
    u32_021F3830 offset;
    u32_021F3830 entry;
    u32_021F3830 ram_address;
    u32_021F3830 size;
} RomRegion;

typedef struct {
    u8 pad0[0x20];
    RomRegion main;
    RomRegion sub;
} RomHeader;

typedef struct {
    u32_021F3830 recv_addr;
    u32_021F3830 load_addr;
    u32_021F3830 size;
    u32_021F3830 target : 1;
} SegInfo;

enum SegType { SEG_A, SEG_B, SEG_C };

typedef unsigned long u32_021F398C;

typedef unsigned short u16;

typedef int BOOL;

typedef struct
{
    u32_021F398C seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
}
MB_BlockInfoTable;

typedef struct
{
    u32_021F398C recv_addr;
    u32_021F398C load_addr;
    u32_021F398C size;
    u32_021F398C target;
}
MbSegmentInfo;

typedef struct
{
    u32_021F398C arm9EntryAddr;
    u32_021F398C arm7EntryAddr;
    u32_021F398C reserved;
}
MbDownloadFileInfoHeader;

extern void func_02088234(void);
extern BOOL IsAbleToLoad(u8 segment_no, u32_021F398C address, u32_021F398C size);
void MBi_SetSegmentInfo(const RomHeader *hdr, enum SegType *list, SegInfo *seg, u32_021F3830 *child_recv);
BOOL MBi_MakeBlockInfoTable(MB_BlockInfoTable *table, MbDownloadFileInfoHeader *mdfi);
extern char *mbc;



void MBi_SetSegmentInfo(const RomHeader *hdr, enum SegType *list, SegInfo *seg, u32_021F3830 *child_recv)
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
        u32_021F3830 load_last_addr;

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
    u32_021F398C *seg_src = table->seg_src_offset;
    u8 i;
    u32_021F398C src_ofs = 0;

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
