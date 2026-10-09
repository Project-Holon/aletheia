/*
 * file:     unit_0217576C_p03.c
 * unit:     yes
 * function: func_02175AA4, func_02175BFC, func_02175C64, func_02175D10, func_02175EB4
 * address:  0x02175AA4
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
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_0219F00C                0x0219F00C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02171C08                0x02171C08 arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 *   gpIsBuddy                    0x021861A8 arm   ov009
 *   func_021719D0                0x021719D0 arm   ov009
 *   func_0216F770                0x0216F770 arm   ov009
 *   func_02173D9C                0x02173D9C arm   ov009
 *   func_020870D0  0x020870D0  arm
 *   func_0216CB90  0x0216CB90  arm  ov009
 *   func_021768EC  0x021768EC  arm  ov009
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   func_02176344  0x02176344  arm  ov009
 *   func_021758C4  0x021758C4  arm  ov009
 *   _ll_udiv       0x0209C00C  arm
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_0216BA08  0x0216BA08  arm  ov009
 */
typedef unsigned char u8;

struct DWCstMatchControl {
	void **connection;
	unsigned char pad4[0x9];
	unsigned char f0d;
	unsigned char pade[0x2];
	void *qr2Obj;
	unsigned char pad14[0x1];
	unsigned char qr2MatchTypeExt;
	unsigned char hostState;
	unsigned char pad17[0x5];
	unsigned int suspendBitmap;
	unsigned long long f20;
	unsigned char pad28[0x8];
	unsigned char suspendSent;
	unsigned char pad31[0x523];
	int f554;
	unsigned char pad558[0x50];
	int lastStateBeforeStopMeshMaking;
	unsigned char  tempNodeInfoBeforeStopMeshMaking[0x28];
	unsigned char pad5d4[0xc];
	void *sbObj;
	unsigned char pad5e4[0x38];
	int f61c;
	unsigned char pad620[0x58];
	unsigned int f678;
	int f67c;
	unsigned char pad680[0x118];
	int f798;
	unsigned char pad79c[0x4];
	unsigned long long f7a0;
	unsigned char pad7a8[0x20];
	unsigned int f7c8;
	unsigned long long f7cc;
};

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

struct DWCstNodeInfo {
	int profileID;
	unsigned int ip;
	unsigned int privateInetAddress;
	unsigned short port;
	unsigned short privateQueryPort;
	unsigned int gt2IP;
	unsigned short gt2Port;
	unsigned char aid;
	unsigned char hasPrivateAddress;
	int nnTryCount;
	unsigned long long nextMeshMakeTryTick;
	unsigned char connUserData[4];
};

extern int func_02175F3C(void);
extern void func_0219F00C(char *p);
extern void func_02175F4C(int state);
extern int func_02171C08(int delay, int init, int resendPid);
extern int func_021719A4(int error);
extern int gpIsBuddy(void **connection, int profile);
extern int func_021719D0(int profileID, int delay);
extern int func_0216F770(int profileID);
extern int func_02173D9C(int error);
extern unsigned long long func_020870D0(void);
extern int func_0216CB90(void);
extern void func_021768EC(int result);
extern unsigned char func_02175FB8(void);
extern struct DWCstNodeInfo *func_02176344(void);
extern int func_021758C4(u8 AID, int suspend, int immediate);
extern char *func_0217637C(int index);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_0216BA08(void);
/* * sdk: DWCi_StartMatch (libdwcmatch.TWL.HYB.a dwc_match.o) */ int func_02175AA4(void);
/* * sdk: DWCi_RequestSuspendMatchInit (dwc_match.o) */ void func_02175BFC(int suspend, void *callback, void *suspendResultParam);
/* * sdk: DWCi_RequestSuspendMatchProcess (dwc_match.o) */ int func_02175C64(void);
/* * sdk: DWCi_RequestSuspendMatch (libdwcmatch.TWL.HYB.a(dwc_match.o)) * * The object reads the tick before it calls DWCi_GetMatchCnt for the store, which * a block-local copy reproduces (the DWARF lists no tick variable). */ static int func_02175D10(int suspend);
/* * sdk: DWCi_IsServerSuspendEnabled (dwc_match.o) */ int func_02175EB4(void);



/*
 * sdk:      DWCi_StartMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02175AA4(void)
{
    int result;
    int sbError;

    if (((struct DWCstMatchControl *)func_02175F3C())->sbObj != 0)
        func_0219F00C(((struct DWCstMatchControl *)func_02175F3C())->sbObj);
    if (((struct DWCstMatchControl *)func_02175F3C())->f798 != 0) {
        func_02175F4C(0xc);
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 1) {
        func_02175F4C(3);
        result = 1;
        if (func_021719A4(func_02171C08(0, 1, 0)))
            result = 0;
        return result;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 2) {
        func_02175F4C(0xd);
        ((struct DWCstMatchControl *)func_02175F3C())->f0d = 1;
        return 1;
    } else if (((struct DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
        if (gpIsBuddy(((struct DWCstMatchControl *)func_02175F3C())->connection, ((struct DWCstMatchControl *)func_02175F3C())->f554)) {
            func_02175F4C(3);
            result = func_021719A4(func_021719D0(((struct DWCstMatchControl *)func_02175F3C())->f554, 0));
            if (result)
                return 0;
        }
        return 1;
    }
    ((struct DWCstMatchControl *)func_02175F3C())->f67c = 0;
    sbError = func_02173D9C(func_0216F770(((struct DWCstMatchControl *)func_02175F3C())->f67c));
    result = 0;
    if (sbError == 0)
        result = 1;
    return result;
}



/*
 * sdk:      DWCi_RequestSuspendMatchInit (dwc_match.o)
 */
void func_02175BFC(int suspend, void *callback, void *suspendResultParam)
{
    *(char *)(func_02175F3C() + 0x30) = 0;
    *(int *)(func_02175F3C() + 0x2c) = suspend;
    *(void **)(func_02175F3C() + 0x34) = callback;
    *(void **)(func_02175F3C() + 0x38) = suspendResultParam;
    *(unsigned long long *)(func_02175F3C() + 0x20) = 0;
    {
        unsigned long long tick = func_020870D0();
        *(unsigned long long *)(func_02175F3C() + 0x3c) = tick;
    }
    *(int *)(func_02175F3C() + 0x48) = 1;
}



/*
 * sdk:      DWCi_RequestSuspendMatchProcess (dwc_match.o)
 */
int func_02175C64(void)
{
    int ret;
    int suspend;

    if (*(int *)(func_02175F3C() + 0x48) == 0)
        return 0;
    if (*(int *)(func_02175F3C() + 0x44) != 0) {
        func_02175BFC(*(int *)(func_02175F3C() + 0x2c), *(void **)(func_02175F3C() + 0x34), *(void **)(func_02175F3C() + 0x38));
        *(int *)(func_02175F3C() + 0x44) = 0;
    }
    suspend = *(int *)(func_02175F3C() + 0x2c);
    if (suspend == 0xff)
        return 0;
    ret = func_0216CB90();
    if ((suspend != 0 && ret != 0) || (suspend == 0 && ret == 0)) {
        func_021768EC(0);
        return 1;
    }
    func_02175D10(suspend);
    return 1;
}



/*
 * sdk:      DWCi_RequestSuspendMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The object reads the tick before it calls DWCi_GetMatchCnt for the store, which
 * a block-local copy reproduces (the DWARF lists no tick variable).
 */
static int func_02175D10(int suspend)
{
    struct DWCstNodeInfo *pServerNodeInfo;
    struct DWCstNodeInfo *pMyNodeInfo;
    u32 senddata[4];
    int result;

    if (func_02175FB8() == 2)
        return func_021758C4(func_02176344()->aid, suspend, 0);
    if (((struct DWCstMatchControl *)func_02175F3C())->f61c != 1)
        return 1;
    if (((struct DWCstMatchControl *)func_02175F3C())->suspendSent) {
        if (((func_020870D0() - ((struct DWCstMatchControl *)func_02175F3C())->f20) * 64) / 33514 < ((struct DWCstMatchControl *)func_02175F3C())->f7cc)
            return 1;
    }
    if (((func_020870D0() - ((struct DWCstMatchControl *)func_02175F3C())->f20) * 64) / 33514 > 3000) {
        pMyNodeInfo = func_02176344();
        pServerNodeInfo = (struct DWCstNodeInfo *)func_0217637C(0);
        senddata[0] = ((struct DWCstMatchControl *)func_02175F3C())->f678;
        senddata[1] = 0;
        senddata[2] = suspend;
        senddata[3] = pMyNodeInfo->aid;
        result = func_0216FF2C(0x82, pServerNodeInfo->profileID, pServerNodeInfo->ip,
                               pServerNodeInfo->port, (const unsigned int *)senddata, 4);
        if (func_021719A4(result))
            return 0;
        {
            u64 now = func_020870D0();
            ((struct DWCstMatchControl *)func_02175F3C())->f20 = now;
        }
        ((struct DWCstMatchControl *)func_02175F3C())->f7cc = 3000;
    }
    return 1;
}



/*
 * sdk:      DWCi_IsServerSuspendEnabled (dwc_match.o)
 */
int func_02175EB4(void)
{
    if (func_0216BA08()) {
        if (*(int *)(func_02175F3C() + 0x61c) == 13 || *(int *)(func_02175F3C() + 0x61c) == 22)
            return 1;
        return 0;
    }
    return 1;
}
