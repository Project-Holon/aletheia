/*
 * file:     unit_0216F014_p02.c
 * unit:     yes
 * function: func_0216F20C, func_0216F334, func_0216F370, func_0216F388
 * address:  0x0216F20C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A207C  0x021A207C  data
 *   d_021A2080  0x021A2080  data
 *   d_021A2084  0x021A2084  data
 *   d_021A2088  0x021A2088  data
 *   d_021A208C  0x021A208C  data
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   OS_SNPrintf  0x02084F80  arm
 *   func_02168454  0x02168454  arm  ov009
 *   func_0216848C  0x0216848C  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_021767F4  0x021767F4  arm  ov009
 *   func_021690D0  0x021690D0  arm  ov009
 *   DWCi_SetMatchCnt         0x02175F1C arm
 *   DWC_Free                 0x0205A1B0 arm
 *   DWCi_ClearGameMatchKeys  0x02173B18 arm
 *   s_bInNNThink             0x021AAA20 data
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
#define MCP DWCi_GetMatchCnt()
typedef unsigned char u8;

struct NNThinkGlobal
{
    int  f0;
    int  f4;
    int  f8;
    void *pC;
};

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

extern int func_02175F3C(void);
extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
extern int func_02168454(const char *key, const char *value, char *string, char sep);
extern int func_0216848C(const char *key, const char *value, char *string, char sep);
extern int func_0217603C(void);
extern int func_021767F4(void);
extern int func_021690D0(int status, const char *statusString, const char *locString);
extern void DWCi_SetMatchCnt(void *pCnt);
extern void DWC_Free(int name, void *ptr, int flag);
extern void DWCi_ClearGameMatchKeys(void);
extern char *DWCi_GetMatchCnt(void);
extern u32 DWCi_GetMathRand32(u32 max);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern int DWCi_GetHostStatus(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_NodeInfoList_Clear(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
int func_0216F20C(int status);
void DWCi_ShutdownMatch(void);
int func_0216F370(void);
void DWCi_ResetMatchParam(int level);
extern char d_021A207C[];
extern char d_021A2080[];
extern char d_021A2084[];
extern char d_021A2088[];
extern char d_021A208C[];
extern struct NNThinkGlobal s_bInNNThink;


/*
 * Builds the match key-value status string and hands it to DWCi_SetGPStatus.
 */
int func_0216F20C(int status)
{
    char value[12];
    char str[0x27];
    int n;

    OS_SNPrintf(value, 12, d_021A207C, *(unsigned char *)(func_02175F3C() + 0x17) + 1);
    func_02168454(d_021A2080, value, str, '/');
    n = func_0217603C();
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 2 && n == 0) {
        n = 1;
    }
    OS_SNPrintf(value, 12, d_021A207C, n);
    func_0216848C(d_021A2084, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, 0x5a);
    func_0216848C(d_021A2088, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, func_021767F4() ? 1 : 0);
    func_0216848C(d_021A208C, value, str, '/');
    return func_021690D0(status, str, 0);
}


void DWCi_ShutdownMatch(void)
{
    DWCi_SetMatchCnt(0);
    if (s_bInNNThink.pC != 0) {
        DWC_Free(4, s_bInNNThink.pC, 0);
        s_bInNNThink.pC = 0;
    }
    DWCi_ClearGameMatchKeys();
}


/*
 * Set when the module block is absent.
 */
int func_0216F370(void)
{
    return func_02175F3C() == 0;
}


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
