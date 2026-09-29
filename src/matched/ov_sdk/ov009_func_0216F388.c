/*
 * function: DWCi_ResetMatchParam
 * address:  0x0216F388
 * packet:   pkt_ov009_0216F388
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     the seven adjacent word-pair clears (0x600/0x604, 0x608/0x60c,
 *           0x63c/0x640, 0x648/0x64c, 0x658/0x65c, 0x668/0x66c, 0x670/0x674)
 *           each emit ONE DWCi_GetMatchCnt() call in the original: they are
 *           single `u64` zero stores, not two `u32` stores. A misaligned
 *           pair like 0x63c still works because mwccarm aligns long long to
 *           four and lowers a u64 store to two `str` with no LDRD/STRD on
 *           this proc.
 *
 * sdk:      DWCi_ResetMatchParam (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_GetMatchCnt              0x02175F3C  arm  ov009
 *   DWCi_GetMathRand32            0x021685CC  arm  ov009
 *   MIi_CpuClear32                0x02082A7C  arm
 *   DWCi_ClearMeshMakingTempInfo  0x02176870  arm  ov009
 *   DWCi_GetHostStatus            0x02175FB8  arm  ov009
 *   DWCi_SetMatchStatus           0x02175F4C  arm  ov009
 *   DWCi_NodeInfoList_Clear       0x0217601C  arm  ov009
 *   DWCi_TempNewNodeInfo_Clear    0x0217653C  arm  ov009
 *   MI_CpuFill8                   0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

extern char *DWCi_GetMatchCnt(void);
extern u32 DWCi_GetMathRand32(u32 max);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern int DWCi_GetHostStatus(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_NodeInfoList_Clear(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);

#define MCP DWCi_GetMatchCnt()

void DWCi_ResetMatchParam(int level)
{
	*(u8 *)(MCP + 0xc) = 0;
	*(u8 *)(MCP + 0x5f8) = 0;
	*(u16 *)(MCP + 0x5fa) = DWCi_GetMathRand32(0x10000);
	*(u32 *)(MCP + 0x5fc) = 0;
	*(u64 *)(MCP + 0x600) = 0;
	*(u64 *)(MCP + 0x608) = 0;
	*(u8 *)(MCP + 0x620) = 0;
	*(u8 *)(MCP + 0x62a) = 0;
	*(u8 *)(MCP + 0x62b) = 0;
	*(u8 *)(MCP + 0x62c) = 0;
	*(u8 *)(MCP + 0x62d) = 0;
	*(u8 *)(MCP + 0x628) = 0;
	*(u8 *)(MCP + 0x629) = 0;
	*(u16 *)(MCP + 0x632) = 0;
	*(u64 *)(MCP + 0x658) = 0;
	*(u64 *)(MCP + 0x668) = 0;
	MIi_CpuClear32(0, MCP + 0x6d8, 0x98);
	*(u32 *)(MCP + 0x5a4) = 0;
	DWCi_ClearMeshMakingTempInfo();
	if (level == 2) {
		if (DWCi_GetHostStatus() == 2) {
			DWCi_SetMatchStatus(0xd);
			return;
		}
		if (DWCi_GetHostStatus() == 1)
			DWCi_SetMatchStatus(1);
		return;
	}
	*(u8 *)(MCP + 0x18) = 0;
	*(u32 *)(MCP + 0x5dc) = 0;
	*(u32 *)(MCP + 0x5e4) = 0;
	*(u16 *)(MCP + 0x630) = 0;
	*(u8 *)(MCP + 0x621) = 0;
	*(u32 *)(MCP + 0x638) = 0;
	*(u64 *)(MCP + 0x63c) = 0;
	*(u32 *)(MCP + 0x644) = 0;
	*(u64 *)(MCP + 0x648) = 0;
	*(u32 *)(MCP + 0x650) = 0;
	*(u32 *)(MCP + 0x67c) = 0;
	MIi_CpuClear32(0, MCP + 0x610, 0xc);
	*(u32 *)(MCP + 0x788) = 0;
	*(u32 *)(MCP + 0x78c) = 0;
	*(u8 *)(MCP + 0x794) = 0;
	*(u8 *)(MCP + 0x7a8) = 1;
	*(u32 *)(MCP + 0x7ac) = 0;
	*(u8 *)(MCP + 0x16) = 0;
	*(u8 *)(MCP + 0xd) = 0;
	*(u32 *)(MCP + 0x7b8) = 0;
	*(u32 *)(MCP + 0x7c0) = 0;
	DWCi_NodeInfoList_Clear();
	DWCi_TempNewNodeInfo_Clear();
	*(u32 *)(MCP + 0x57c) = 0;
	if (level == 1) {
		if (*(u8 *)(MCP + 0x15) == 0 || *(u8 *)(MCP + 0x15) == 1)
			DWCi_SetMatchStatus(0x16);
		return;
	}
	*(u8 *)(MCP + 0x14) = 0;
	*(u8 *)(MCP + 0x17) = 0;
	*(u8 *)(MCP + 0x4c) = 0;
	*(u32 *)(MCP + 0x680) = 0;
	*(u8 *)(MCP + 0x62e) = 0;
	*(u64 *)(MCP + 0x670) = 0;
	*(u32 *)(MCP + 0x778) = 0;
	*(u32 *)(MCP + 0x77c) = 0;
	MI_CpuFill8(MCP + 0x7bc, 0, 4);
}
