/*
 * function: MBi_MakeDownloadFileInfo
 * address:  0x021F37BC
 * packet:   pkt_ov107_021F37BC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_fileinfo.o).  Rebuilt from the SDK source
 * (mb_fileinfo.c) plus the Rom object's DWARF (decl_line 669) and the ROM
 * disassembly.
 *
 * symbols:
 *   MBi_defaultLoadSegList  0x021F6D04  data  a4
 */

typedef unsigned long u32;
typedef unsigned short u16;

typedef struct
{
    u32 size;
    u32 load_addr;
    u32 recv_addr;
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

extern void MBi_SetSegmentInfo(const void *mbRomHeaderp, const void *loadSegListp,
                               MbSegmentInfo *seg_infop, u32 *child_recv_buff_addr);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern const u32 MBi_defaultLoadSegList[];

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
        MBi_SetSegmentInfo(buf, loadSegListp, seg_infop, &child_recv_buff_addr);
        seg_infop++;
        loadSegListp++;
    }

    MI_CpuCopy8((const char *)buf + 0x160, (char *)mbdlFileInfop + 0x3c, 0x88);
}
