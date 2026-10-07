/*
 * file:     unit_0216F014_p13.c
 * unit:     yes
 * function: func_02172B08, func_02172BB8
 * address:  0x02172B08
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
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   DWCi_FinishCancelMatch        0x02172A58  arm  ov009
 *   DWCi_ResetMatchParam          0x0216F388  arm  ov009
 *   DWCi_GetMatchCnt              0x02175F3C  arm  ov009
 *   DWCi_GetFriendListIndex       0x02169038  arm  ov009
 *   DWCi_SetHostStatus            0x02175F84  arm  ov009
 *   DWCi_SetMatchStatus           0x02175F4C  arm  ov009
 *   DWCi_SBUpdateAsync            0x0216F770  arm  ov009
 *   DWCi_HandleSBError            0x02173D9C  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct DWCstMatchControl {
	u8 _00[0xd];
	u8 f0D;
	u8 _0E[0x15 - 0x0e];
	u8 f15;
	u8 _16[0x678 - 0x16];
	u32 f678;
	u32 f67C;
	u32 f680;
	u8 _684[0x770 - 0x684];
	void (*f770)(u32, u32, u32, u32, u32, u32);
	u32 f774;
	u8 _778[0x798 - 0x778];
	u32 f798;
} DWCstMatchControl;

extern int func_02175F3C(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern void func_0217653C(void);
extern void DWCi_FinishCancelMatch(void);
extern void DWCi_ResetMatchParam(int level);
extern DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int DWCi_GetFriendListIndex(int profileID);
extern void DWCi_SetHostStatus(int host);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_SBUpdateAsync(int profileID);
extern int DWCi_HandleSBError(int error);
int func_02172B08(void);
void DWCi_RestartFromCancel(int level);


/*
 * sdk:      DWCi_InvalidateReservation (dwc_match.o)
 */
int func_02172B08(void)
{
    int result;
    unsigned long senddata = 0;

    result = 0;
    if (*(unsigned char *)(func_02175F3C() + 0x18) != 0 && *(int *)(func_02175F3C() + 0x5dc) != 0
        && *(int *)(func_02175F3C() + 0x5dc) != *(int *)(func_02175F3C() + 0x678)) {
        result = func_0216FF2C(12, *(int *)(func_02175F3C() + 0x5dc), *(int *)(func_02175F3C() + 0x558), *(unsigned short *)(func_02175F3C() + 0x560), (const unsigned int *)(&senddata), 1);
        *(unsigned char *)(func_02175F3C() + 0x18) = 0;
        *(int *)(func_02175F3C() + 0x5dc) = 0;
        func_0217653C();
    }
    return result;
}


void DWCi_RestartFromCancel(int level)
{
	int sbError;
	int b;

	if (level == 0) {
		DWCi_FinishCancelMatch();
		return;
	}
	DWCi_ResetMatchParam(level);
	if (DWCi_GetMatchCnt()->f15 == 2 || DWCi_GetMatchCnt()->f15 == 3) {
		b = DWCi_GetMatchCnt()->f680 == 0;
		DWCi_GetMatchCnt()->f770(0, 1, b, 0,
		        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->f680),
		        DWCi_GetMatchCnt()->f774);
		return;
	}
	if (DWCi_GetMatchCnt()->f15 == 0) {
		if (DWCi_GetMatchCnt()->f0D != 0) {
			b = DWCi_GetMatchCnt()->f680 == 0;
			DWCi_GetMatchCnt()->f770(0, 1, b, 0,
			        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->f680),
			        DWCi_GetMatchCnt()->f774);
		}
		if (level == 1) {
			DWCi_SetHostStatus(0);
			DWCi_SetMatchStatus(0x16);
			sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->f678);
			DWCi_HandleSBError(sbError);
		}
		return;
	}
	if (DWCi_GetMatchCnt()->f15 == 1) {
		if (DWCi_GetMatchCnt()->f0D != 0) {
			b = DWCi_GetMatchCnt()->f680 == 0;
			DWCi_GetMatchCnt()->f770(0, 1, b, 0,
			        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->f680),
			        DWCi_GetMatchCnt()->f774);
		}
		if (level == 1) {
			DWCi_SetHostStatus(0);
			DWCi_GetMatchCnt()->f798 = 0;
			DWCi_SetMatchStatus(0x16);
			sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->f678);
			DWCi_HandleSBError(sbError);
		}
		return;
	}
}
