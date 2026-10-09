/*
 * file:     unit_0217576C_p01.c
 * unit:     yes
 * function: func_0217576C
 * address:  0x0217576C
 * packet:   pkt_ov009_0217576C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendServerPolling (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_0216BA08                0x0216BA08 arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   _ll_udiv                     0x0209C00C arm
 *   func_0216B908                0x0216B908 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_02176344                0x02176344 arm   ov009
 *   func_0216FF2C                0x0216FF2C arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

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

extern int func_0216BA08(void);
extern int func_02175F3C(void);
extern u64 func_020870D0(void);
extern int func_0216B908(void);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern struct DWCstNodeInfo *func_02176344(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int error);

int func_0217576C(int immediate)
{
    u32 sendData[3];
    struct DWCstNodeInfo *pNodeInfo;
    int result;
    int i;
    u64 tick;

    if (!func_0216BA08())
        return 1;
    if (((struct DWCstMatchControl *)func_02175F3C())->f61c == 0x13 || ((struct DWCstMatchControl *)func_02175F3C())->f61c == 0x14)
        return 1;
    if (immediate == 0) {
        tick = func_020870D0();
        if (((tick - ((struct DWCstMatchControl *)func_02175F3C())->f7a0) * 64) / 33514 <= 15000)
            goto done;
    }
    sendData[0] = ((struct DWCstMatchControl *)func_02175F3C())->f678;
    sendData[1] = func_0216B908();
    sendData[2] = ((struct DWCstMatchControl *)func_02175F3C())->f7c8;
    for (i = 0; i < func_0217603C(); i++) {
        pNodeInfo = (struct DWCstNodeInfo *)func_0217637C(i);
        if (pNodeInfo != func_02176344()) {
            result = func_0216FF2C(0x83, pNodeInfo->profileID, pNodeInfo->ip, pNodeInfo->port, (const unsigned int *)sendData, 3);
            if (func_021719A4(result))
                return -1;
        }
    }
    tick = func_020870D0();
    ((struct DWCstMatchControl *)func_02175F3C())->f7a0 = tick;
done:
    return 1;
}
