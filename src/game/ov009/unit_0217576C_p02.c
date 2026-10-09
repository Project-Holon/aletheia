/*
 * file:     unit_0217576C_p02.c
 * unit:     yes
 * function: func_021758C4
 * address:  0x021758C4
 * packet:   pkt_ov009_021758C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessRequestMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * lever:    the broadcast arm is a separate `if (bRet)`, not the `else` of
 *           `if (immediate == 1)`.  Both spellings are the same CFG here (the
 *           immediate arm falls through), but only the separate-if spelling
 *           predicates the error return's epilogue.  Under `else if` 1.1p1
 *           keeps `beq` + `add sp` / `mov r0,#0` / `pop {.. pc}` at 0x021759EC
 *           (484 bytes, 171 concrete out) and reuses r7 for the immediate
 *           arm's pNodeInfo; under two `if`s it emits the image's
 *           `addne sp` / `movne r0,#0` / `popne {.. pc}` with pNodeInfo in sl
 *           (the register AID dies in), 480 bytes, 0 out.
 *
 * symbols:
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02175EB4  0x02175EB4  arm  ov009
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_0216CB90  0x0216CB90  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct DWCstNodeInfo {
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
} DWCstNodeInfo;

typedef struct DWCstMatchControl {
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
} DWCstMatchControl;

extern char *func_0217637C(int index);
extern int func_02175F3C(void);
extern int func_0216F20C(int status);
extern int func_02175EB4(void);
extern u8 func_0216B838(void);
extern int func_0216CB90(void);
extern char *func_02176410(unsigned char aid);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int error);
extern int func_0217603C(void);

static int func_021758C4(u8 AID, int suspend, int immediate)
{
    int i;
    u32 sendlen;
    u32 oldbitmap;
    u32 senddata[4];
    int result;
    int sm;
    u32 bitmap;
    DWCstNodeInfo *pServerNodeInfo;
    int bRet;

    result = 1;
    sendlen = 0;
    pServerNodeInfo = (DWCstNodeInfo *)func_0217637C(0);
    oldbitmap = ((DWCstMatchControl *)func_02175F3C())->suspendBitmap;
    if (suspend)
        ((DWCstMatchControl *)func_02175F3C())->suspendBitmap |= result << AID;
    else
        ((DWCstMatchControl *)func_02175F3C())->suspendBitmap &= ~(result << AID);
    if (oldbitmap != ((DWCstMatchControl *)func_02175F3C())->suspendBitmap)
        func_0216F20C(-1);
    bitmap = ((DWCstMatchControl *)func_02175F3C())->suspendBitmap;
    if (!func_02175EB4())
        bitmap &= ~(result << func_0216B838());
    sm = func_0216CB90();
    bRet = 1;
    if (!((suspend && sm) || (!suspend && !sm)))
        bRet = 0;
    if (immediate == 1) {
        DWCstNodeInfo *pNodeInfo;

        pNodeInfo = (DWCstNodeInfo *)func_02176410(AID);
        senddata[sendlen++] = ((DWCstMatchControl *)func_02175F3C())->f678;
        senddata[sendlen++] = result;
        if (bRet) {
            if (((DWCstMatchControl *)func_02175F3C())->suspendSent != 0) {
                senddata[sendlen++] = suspend;
                senddata[sendlen++] = bitmap;
            }
        }
        result = func_0216FF2C(0x82, pNodeInfo->profileID, pNodeInfo->ip,
                               pNodeInfo->port, (const unsigned int *)senddata, sendlen);
        if (func_021719A4(result))
            return 0;
    }
    if (bRet) {
        if (((DWCstMatchControl *)func_02175F3C())->suspendSent != 1) {
            ((DWCstMatchControl *)func_02175F3C())->suspendSent = 1;
            senddata[0] = ((DWCstMatchControl *)func_02175F3C())->f678;
            senddata[1] = 1;
            senddata[2] = suspend;
            senddata[3] = bitmap;
            for (i = 0; i < func_0217603C(); i++) {
                DWCstNodeInfo *pNodeInfo = (DWCstNodeInfo *)func_0217637C(i);

                if (pNodeInfo != pServerNodeInfo) {
                    result = func_0216FF2C(0x82, pNodeInfo->profileID, pNodeInfo->ip,
                                           pNodeInfo->port, (const unsigned int *)senddata, 4);
                    if (func_021719A4(result))
                        return 0;
                }
            }
        }
    }
    return 1;
}
