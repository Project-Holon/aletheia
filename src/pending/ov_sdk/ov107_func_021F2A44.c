/*
 * function: MBi_CommParentSendBlock
 * address:  0x021F2A44
 * packet:   pkt_ov107_021F2A44
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  size is right (632) and everything except one 6-instruction
 *           straight-line block is byte-identical: the two `goto ret15`
 *           guards now share the SetTask `return 0x15` tail, the 4-element
 *           cash-selection loop is byte-exact (base in r2, int cursor in r3),
 *           MBi_ReadFromCache(...,bi.size) and MBi_BlockHeaderEnd(bi.size+6)
 *           are right. Residue: the `card_addr` base computation at +0128..
 *           +0148 rotates scratch registers only -- the original loads mbc
 *           into r6, idx into r2, base (`mla r6,r2,r4,r6`) into r6; mwc 1.1p1
 *           loads mbc into r7, idx into r6, base into r2. Same 632 bytes,
 *           same semantics. Both permute.py (150) and permuter.py (400)
 *           plateau here; declaration/statement order, a named base local
 *           and a pinned segment_no local all fail to move the transient.
 *
 * lane W7 (2026-09-30): re-measured 632/632, 10/10 relocations, 12 concrete
 * bytes at +0128..+0148.  The base `mbc + C[0x525]*0x5d4` lands in r2 (and the
 * following two adds swap) against the image's r6; the mla result register and
 * the two independent adds are the only difference.  No new source shape was
 * found this wave; the declared/statement-order and named-base-local attempts
 * in the blocker above still stand as the search of record.  Compiler wall.
 *
 * lane 6 (wave 10): still 12 B. Also measured, all no better: a typed MBFI struct overlay for the
 *           card_addr/pl reads (52-54 B), a named idx local at nine declaration positions (12 B,
 *           inert), a named base pointer (264 B) and an `MBC *m = mbc` local (314 B).
 *
 * wave 8 (2026-10-01): confirmed the residue is a pure allocator tie, not a source shape. The
 *           defining-object DWARF (scratch/u70/obj_021F2A44.txt) homes `card_addr` in r6 and has
 *           NO base/local temporary, so the mla base temp coalescing into r6 is the tie. Measured
 *           and all worse or inert: reassigning the base into card_addr via a pointer cast (290 B),
 *           a raw `(u32)mbc + C[0x525]*0x5d4` base in card_addr (36 B), named `srcoff`/`segtbl`
 *           temporaries (12 B, inert), `card_addr = card_addr;` self-assignment (12 B, inert), and
 *           emitting the pl read before card_addr (32 B). Stop column remains public.
 *
 * sdk:      MBi_CommParentSendBlock (libmb.TWL.HYB.a(mb_parent.o))
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
} MB_BlockInfo;

typedef struct {
	u32 src;
	u32 len;
	void *ptr;
	u32 state;
} MBiCacheInfo;

typedef struct {
	u32 lifetime;
	u8 pad[0x2c];
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
	u8 pad1;
	u16 fid;
	u16 seqno;
} MBCommParentBlockHeader;

typedef struct MBiTaskInfo_tag {
	struct MBiTaskInfo_tag *next;
	u32 priority;
	void (*task)(struct MBiTaskInfo_tag *);
	void (*callback)(struct MBiTaskInfo_tag *);
	u32 param[4];
} MBiTaskInfo_tag;

typedef struct {
	u8 _pad[0x1000];
	u8 cache[0x8000];
} MBC;

extern MBC *mbc;
extern void MBi_calc_sendblock(u8 file_id);
extern int MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table,
                             u32 block, MbDownloadFileInfoHeader *mdfi);
extern u8 *MBi_MakeParentSendBuffer(MBCommParentBlockHeader *hdr, u8 *sendbuf);
extern int MBi_ReadFromCache(MBiCacheList *pl, u32 src, void *dst, u32 len);
extern int MBi_IsTaskBusy(MBiTaskInfo_tag *pt);
extern void OS_Terminate(void);
extern void MBi_SetTask(MBiTaskInfo_tag *pt, void (*task)(MBiTaskInfo_tag *),
                        void (*callback)(MBiTaskInfo_tag *), u32 priority);
extern int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf);
extern void MBi_ReloadCache(MBiTaskInfo_tag *p_task);

#define C mbc->cache

int MBi_CommParentSendBlock(void)
{
	u8 i;
	u32 card_addr;
	MB_BlockInfo bi;
	MBCommParentBlockHeader hd;
	MBiCacheList *pl;
	MBiTaskInfo_tag *p_task;
	MBiCacheInfo *trg;
	MBiCacheInfo *pi;
	u8 *databuf;

	if (C[0x524] == 0)
		return 0x15;

	i = 0;
	do {
		C[0x525] = (C[0x525] + 1) % 16;
		if (*(u8 *)(C + C[0x525] * 0x5d4 + 0xd52) != 0
		    && *(u16 *)(C + C[0x525] * 0x5d4 + 0xd4c) != 0)
			break;
		i++;
	} while (i < 0x10);
	if (i == 0x10)
		return 0x15;

	MBi_calc_sendblock(C[0x525]);

	if (!MBi_get_blockinfo(&bi, (MB_BlockInfoTable *)(C + C[0x525] * 0x5d4 + 0xd2c),
	                       *(u16 *)(C + C[0x525] * 0x5d4 + 0xd48),
	                       (MbDownloadFileInfoHeader *)(C + C[0x525] * 0x5d4 + 0x788)))
		return 0x15;

	hd.type = 4;
	hd.fid = C[0x525];
	hd.seqno = *(u16 *)(C + C[0x525] * 0x5d4 + 0xd48);
	databuf = MBi_MakeParentSendBuffer(&hd, (u8 *)mbc);

	card_addr = (bi.offset - *(u32 *)(C + C[0x525] * 0x5d4 + 0xd2c + bi.segment_no * 4))
	            + ((u32 *)*(u32 **)(C + C[0x525] * 0x5d4 + 0xd58))[bi.segment_no];
	pl = *(MBiCacheList **)(C + C[0x525] * 0x5d4 + 0xd54);

	if (MBi_ReadFromCache(pl, card_addr, databuf, bi.size) == 0) {
		p_task = (MBiTaskInfo_tag *)(C + 0x6ce0);
		if (MBi_IsTaskBusy(p_task))
			goto ret15;
		if (pl->lifetime != 0) {
			pl->lifetime--;
			goto ret15;
		}

		trg = 0;
		pi = pl->list;
		{
			int j;
			for (j = 0; j < 4; j++) {
				if (pi[j].state == 2) {
					if (trg == 0 || trg->src > pi[j].src)
						trg = &pi[j];
				}
			}
		}
		if (trg == 0)
			OS_Terminate();

		pl->lifetime = 2;
		trg->state = 1;
		trg->src = card_addr & ~0x1f;
		p_task->param[0] = (u32)trg;
		p_task->param[1] = (u32)pl;
		MBi_SetTask(p_task, MBi_ReloadCache, 0, 4);
	ret15:
		return 0x15;
	}
	return MBi_BlockHeaderEnd(bi.size + 6,
	                          *(u16 *)(C + C[0x525] * 0x5d4 + 0xd4c),
	                          (u32 *)mbc);
}
