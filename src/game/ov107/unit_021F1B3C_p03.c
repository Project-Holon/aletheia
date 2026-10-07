/*
 * file:     unit_021F1B3C_p03.c
 * unit:     yes
 * function: func_021F2938, func_021F2A44
 * address:  0x021F2938
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
 *   func_02077EB8 0x02077EB8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02075E04 0x02075E04 arm
 *   func_020788AC 0x020788AC arm
 *   func_02078964 0x02078964 arm
 *   func_02078B70 0x02078B70 arm
 *   func_02078A80 0x02078A80 arm
 *   g_021F6E4C 0x021F6E4C data
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
#define pPwork ((MB_CommPWork *)mbc)
struct FSArchive;
struct FSFile;
typedef unsigned char u8;

typedef unsigned long u32;

typedef struct {
    u32 src;
    u32 len;
    u8 *ptr;
    u32 state;
} CacheInfo;

typedef struct {
    u32 lifetime;
    u32 recent;
    CacheInfo *p_list;
    u32 size;
    char arc_name[4];
    u32 arc_name_len;
    void *arc_pointer;
} CacheList;

typedef struct {
    void *next;
    u32 busy;
    void *task;
    void *callback;
    u32 param[4];
} TaskInfo;

typedef struct {
    char pad[0x1e0];
    u32 ntr_off;
    u32 ntr_len;
    u32 ltd_off;
    u32 ltd_len;
} RomHeader;

typedef signed int     s32;

typedef unsigned short u16;

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

extern struct FSArchive *func_02077EB8(const char *name, int name_len);
extern int func_02085D3C(void);
extern RomHeader *func_02075E04(void);
extern void func_020788AC(void *file);
extern int func_02078964(void *file, void *arc, u32 top, u32 bottom, u32 id);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern int func_02078A80(void *file);
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
void func_021F2938(TaskInfo *p_task);
int MBi_CommParentSendBlock(void);
extern char g_021F6E4C[];
extern MB_CommCommonWork *mbc;


/*
 * sdk:      MBi_ReloadCache (libmb.TWL.HYB.a(mb_parent.o))
 */
void func_021F2938(TaskInfo *p_task)
{
    CacheInfo *p_info;
    CacheList *p_list;
    u32 file[18];
    void *arc;
    u32 length;
    RomHeader *header;
    u32 boundary_ntr;
    u32 boundary_ltd;

    p_list = (CacheList *)p_task->param[1];
    p_info = (CacheInfo *)p_task->param[0];
    length = p_info->len;
    arc = func_02077EB8(p_list->arc_name, p_list->arc_name_len);
    if (arc == 0) {
        arc = p_list->arc_pointer;
    }
    if (func_02085D3C() && arc == func_02077EB8(g_021F6E4C, 3)) {
        header = func_02075E04();
        boundary_ntr = header->ntr_off + header->ntr_len;
        boundary_ltd = header->ltd_off + header->ltd_len;
        if (p_info->src < boundary_ntr && p_info->src + length > boundary_ntr) {
            length = boundary_ntr - p_info->src;
        } else if (p_info->src < boundary_ltd && p_info->src + length > boundary_ltd) {
            length = boundary_ltd - p_info->src;
        }
    }
    func_020788AC(file);
    if (func_02078964(file, arc, p_info->src, p_info->src + length, 0xffffffff)) {
        if (length == func_02078B70((struct FSFile *)file, p_info->ptr, length)) {
            p_info->state = 2;
        }
        func_02078A80(file);
    }
    if (p_info->state != 2) {
        p_info->src = 0;
        p_info->state = 2;
    }
}


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
