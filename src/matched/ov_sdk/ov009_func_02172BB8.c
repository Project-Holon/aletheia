/*
 * function: DWCi_RestartFromCancel
 * address:  0x02172BB8
 * packet:   pkt_ov009_02172BB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RestartFromCancel (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
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

extern void DWCi_FinishCancelMatch(void);
extern void DWCi_ResetMatchParam(int level);
extern DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int DWCi_GetFriendListIndex(int profileID);
extern void DWCi_SetHostStatus(int host);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_SBUpdateAsync(int profileID);
extern int DWCi_HandleSBError(int error);

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
