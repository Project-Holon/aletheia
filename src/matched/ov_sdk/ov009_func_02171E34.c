/*
 * function: DWCi_RetryReserving
 * address:  0x02171E34
 * packet:   pkt_ov009_02171E34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RetryReserving (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   DWCi_TempNewNodeInfo_Clear                0x0217653C arm   ov009
 *   DWCi_SetMatchStatus                0x02175F4C arm   ov009
 *   func_0216F770                0x0216F770 arm   ov009
 *   DWCi_HandleSBError                0x02173D9C arm   ov009
 *   func_02171C08                0x02171C08 arm   ov009
 *   DWCi_HandleMatchCommandError                0x021719A4 arm   ov009
 *   DWCi_StopMatch                0x0216EB68 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned long long u64;

struct DWCstMatchControl {
    u8 pad0[0x15];
    u8 qr2MatchTypeExt;
    u8 pad1[0x5e4 - 0x16];
    int f5e4;
    u64 f5e8;
    u8 pad2[0x628 - 0x5f0];
    u8 f628;
    u8 pad3[0x648 - 0x629];
    u64 f648;
    u8 pad4[0x67c - 0x650];
    int f67c;
    u8 pad5[0x798 - 0x680];
    int f798;
};

extern int func_02175F3C(void);
extern u64 func_020870D0(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern void DWCi_SetMatchStatus(int state);
extern int func_0216F770(int profileID);
extern int DWCi_HandleSBError(int error);
extern int func_02171C08(int delay, int init, int resendPid);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_StopMatch(int error, int errorCode);

int DWCi_RetryReserving(int resendPid)
{
    int result;
    int sbError;
    u64 tick;

    ((struct DWCstMatchControl *)func_02175F3C())->f67c = 0;
    ((struct DWCstMatchControl *)func_02175F3C())->f628 = 0;
    tick = func_020870D0();
    ((struct DWCstMatchControl *)func_02175F3C())->f648 = tick;
    DWCi_TempNewNodeInfo_Clear();
    if (((struct DWCstMatchControl *)func_02175F3C())->f798 != 0) {
        DWCi_SetMatchStatus(0xc);
        sbError = DWCi_HandleSBError(func_0216F770(0));
        if (sbError != 0)
            return 0;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 0) {
        DWCi_SetMatchStatus(2);
        if (resendPid != 0) {
            ((struct DWCstMatchControl *)func_02175F3C())->f5e4 = 1;
            tick = func_020870D0();
            ((struct DWCstMatchControl *)func_02175F3C())->f5e8 = tick;
        } else {
            sbError = DWCi_HandleSBError(func_0216F770(0));
            if (sbError != 0)
                return 0;
        }
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 1) {
        result = DWCi_HandleMatchCommandError(func_02171C08(1, 0, resendPid));
        if (result != 0)
            return 0;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
        DWCi_StopMatch(6, -80410);
        return 0;
    }
    return 1;
}
