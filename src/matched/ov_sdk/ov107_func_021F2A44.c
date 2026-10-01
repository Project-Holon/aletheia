/*
 * function: MBi_CommParentSendBlock
 * address:  0x021F2A44
 * packet:   pkt_ov107_021F2A44
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_CommParentSendBlock (libmb.TWL.HYB.a(mb_parent.o))
 *
 * vendor DWARF of mb_parent.o (Metrowerks 4.0.0.1024), reverse declaration order:
 *   static int MBi_CommParentSendBlock(void);
 *   int i r0; MBiCacheInfo *trg r5; MBiCacheInfo *pi r2; MBiTaskInfo *p_task r4;
 *   MBiCacheList *pl r7; u32 card_addr r6; MB_BlockInfo bi [fb+8]; u8 i r1;
 *   u8 *databuf r0; MBCommParentBlockHeader hd [fb+0]
 *   This body compiled with -g gives the identical local list and registers.
 *
 * wave3 lane23 (2026-10-01): EXACT, 632 bytes, 10/10 relocs.  The old 12 B
 *   card_addr residue (mbc/idx/base in r7/r6/r2 against the image's r6/r2/r6) was
 *   not an allocator wall: the work area is reached through a cast macro,
 *   `#define pPwork ((MB_CommPWork *)mbc)`, over an `mbc` of a different pointer
 *   type (MB_CommCommonWork *).  With mbc declared as the work type itself the
 *   same source keeps the residue; the conversion node is what recolours the
 *   temporaries.  Earlier notes (declaration order, named idx/base locals,
 *   operand orders, self-assignments) are superseded.
 *
 * symbols:
 *   MBi_calc_sendblock           0x021F2E58  arm  ov107
 *   MBi_get_blockinfo            0x021F3A58  arm  ov107
 *   MBi_MakeParentSendBuffer     0x021F6890  arm  ov107
 *   MBi_ReadFromCache            0x021F63E8  arm  ov107
 *   MBi_IsTaskBusy               0x021F6640  arm  ov107
 *   OS_Terminate                 0x02088234  arm
 *   MBi_SetTask                  0x021F6658  arm  ov107
 *   MBi_BlockHeaderEnd           0x021F3C80  arm  ov107
 *   MBi_ReloadCache              0x021F2938  arm  ov107
 *   mbc                          0x021F6FA0  data  a4
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
	u32 child_address;
	u32 size;
	u32 offset;
	u8 segment_no;
	u8 pad[3];
} MB_BlockInfo;

typedef struct {
	u32 src;
	u32 len;
	u8 *ptr;
	u32 state;
} MBiCacheInfo;

typedef struct {
	u32 lifetime;
	u32 recent;
	MBiCacheInfo *p_list;
	u32 size;
	char arc_name[4];
	u32 arc_name_len;
	void *arc_pointer;
	u8 reserved[20];
	MBiCacheInfo list[4];
} MBiCacheList;

typedef struct {
	u32 seg_src_offset[3];
	u16 seg_head_blockno[3];
	u16 block_num;
} MB_BlockInfoTable;

typedef struct {
	u32 arm9EntryAddr;
	u32 arm7EntryAddr;
	u32 reserved;
} MbDownloadFileInfoHeader;

typedef struct {
	u8 type;
	u8 pad1[1];
	u16 fid;
	u16 seqno;
} MBCommParentBlockHeader;

typedef struct MBiTaskInfo_tag {
	struct MBiTaskInfo_tag *next;
	u32 priority;
	void (*task)(struct MBiTaskInfo_tag *);
	void (*callback)(struct MBiTaskInfo_tag *);
	u32 param[4];
} MBiTaskInfo;

/* per-file parent state, 0x5d4 bytes */
typedef struct {
	MbDownloadFileInfoHeader header;
	u8 pad0[0x5a4 - 12];
	MB_BlockInfoTable blockinfo_table;
	u8 pad1[0x5c0 - 0x5a4 - sizeof(MB_BlockInfoTable)];
	u16 currentb;
	u16 nextb;
	u16 pollbmp;
	u16 pad2[2];
	u8 active;
	u8 update;
	MBiCacheList *cache_list;
	u32 *card_mapping;
} MBiParentFileInfo;

typedef struct {
	u8 sendbuf[0x200];
} MB_CommCommonWork;

typedef struct {
	MB_CommCommonWork common;
	u8 pad0[0x1524 - sizeof(MB_CommCommonWork)];
	u8 file_num;
	u8 cur_fileid;
	u8 pad1[0x1788 - 0x1526];
	MBiParentFileInfo fileinfo[16];
	u8 pad2[0x7ce0 - 0x1788 - 16 * sizeof(MBiParentFileInfo)];
	MBiTaskInfo cur_task;
} MB_CommPWork;

extern MB_CommCommonWork *mbc;
#define pPwork ((MB_CommPWork *)mbc)

extern void MBi_calc_sendblock(u8 file_id);
extern int MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table,
                             u32 block, MbDownloadFileInfoHeader *mdfi);
extern u8 *MBi_MakeParentSendBuffer(MBCommParentBlockHeader *hdr, u8 *sendbuf);
extern int MBi_ReadFromCache(MBiCacheList *pl, u32 src, void *dst, u32 len);
extern int MBi_IsTaskBusy(MBiTaskInfo *pt);
extern void OS_Terminate(void);
extern void MBi_SetTask(MBiTaskInfo *pt, void (*task)(MBiTaskInfo *),
                        void (*callback)(MBiTaskInfo *), u32 priority);
extern int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf);
extern void MBi_ReloadCache(MBiTaskInfo *p_task);

int MBi_CommParentSendBlock(void)
{
	MBCommParentBlockHeader hd;
	u8 *databuf;
	u8 i;
	MB_BlockInfo bi;

	if (pPwork->file_num == 0)
		return 0x15;

	for (i = 0; i < 16; i++) {
		pPwork->cur_fileid = (u8)((pPwork->cur_fileid + 1) % 16);
		if (pPwork->fileinfo[pPwork->cur_fileid].active
		    && pPwork->fileinfo[pPwork->cur_fileid].pollbmp)
			break;
	}
	if (i == 16)
		return 0x15;

	MBi_calc_sendblock(pPwork->cur_fileid);

	if (!MBi_get_blockinfo(&bi, &pPwork->fileinfo[pPwork->cur_fileid].blockinfo_table,
	                       pPwork->fileinfo[pPwork->cur_fileid].currentb,
	                       &pPwork->fileinfo[pPwork->cur_fileid].header))
		return 0x15;

	hd.type = 4;
	hd.fid = pPwork->cur_fileid;
	hd.seqno = pPwork->fileinfo[pPwork->cur_fileid].currentb;
	databuf = MBi_MakeParentSendBuffer(&hd, pPwork->common.sendbuf);

	{
		u32 card_addr = (u32)(bi.offset -
		                      pPwork->fileinfo[pPwork->cur_fileid].blockinfo_table.seg_src_offset[bi.segment_no] +
		                      pPwork->fileinfo[pPwork->cur_fileid].card_mapping[bi.segment_no]);
		MBiCacheList *const pl = pPwork->fileinfo[pPwork->cur_fileid].cache_list;
		if (!MBi_ReadFromCache(pl, card_addr, databuf, bi.size)) {
			MBiTaskInfo *const p_task = &pPwork->cur_task;
			if (!MBi_IsTaskBusy(p_task)) {
				if (pl->lifetime) {
					--pl->lifetime;
				} else {
					MBiCacheInfo *pi = pl->list;
					MBiCacheInfo *trg = 0;
					int i;
					for (i = 0; i < 4; ++i) {
						if (pi[i].state == 2) {
							if (!trg || (trg->src > pi[i].src))
								trg = &pi[i];
						}
					}
					if (!trg)
						OS_Terminate();
					pl->lifetime = 2;
					trg->state = 1;
					trg->src = (card_addr & ~31);
					p_task->param[0] = (u32)trg;
					p_task->param[1] = (u32)pl;
					MBi_SetTask(p_task, MBi_ReloadCache, 0, 4);
				}
			}
			return 0x15;
		}
	}
	return MBi_BlockHeaderEnd((int)(bi.size + sizeof(MBCommParentBlockHeader)),
	                          pPwork->fileinfo[pPwork->cur_fileid].pollbmp,
	                          (u32 *)pPwork->common.sendbuf);
}
