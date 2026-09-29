/*
 * function: func_02164D74
 * address:  0x02164D74
 * packet:   pkt_ov009_02164D74
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      WCM_InitEx (libwcm.TWL.HYB.a system.o)
 *
 * near miss: 364 B both; only the +0x18..+0x28 schedule differs (original loads
 * the 0x021AA7D4 pool word before `mov r1,#0`, ours after).
 *
 * symbols:
 *   OS_DisableInterrupts 02087988 arm
 *   OS_RestoreInterrupts 0208799C arm
 *   MI_CpuFill8          02082BCC arm
 *   func_02165B68        0x02165B68 arm ov009
 *   func_02164F38        0x02164F38 arm ov009
 *   func_021658F8        0x021658F8 arm ov009
 *   func_02166304        0x02166304 arm ov009
 *   func_02087058        0x02087058 arm
 *   func_02086FE8        0x02086FE8 arm
 *   func_02087244        0x02087244 arm
 *   func_02087208        0x02087208 arm
 *   func_02087254        0x02087254 arm
 *   g_021AA7D4           0x021AA7D4 data ov009
 */

typedef struct WCMWork {
    unsigned char pad0[0x1294];
    unsigned char alarm[0x12D8 - 0x1294];
    unsigned short maxScanTime;
    unsigned short wmState;
    unsigned char resetting0;
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

typedef struct WCMSysState {
    unsigned char overridedDeviceId;
    WCMWork *wcmw;
} WCMSysState;

extern WCMSysState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char func_02165B68(void);
extern long func_02164F38(long *size, unsigned char deviceId);
extern void func_021658F8(void);
extern void func_02166304(void);
extern long func_02087058(void);
extern void func_02086FE8(void);
extern long func_02087244(void);
extern void func_02087208(void);
extern void func_02087254(void *alarm);

long func_02164D74(void *buf, long len, unsigned char deviceId)
{
    long expectLen;
    unsigned long e;

    e = OS_DisableInterrupts();
    expectLen = 0;
    if (g_021AA7D4.wcmw != 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (buf == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (((unsigned long)buf & 0x1f) != 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    MI_CpuFill8(buf, 0, len);
    if (deviceId == 0) {
        deviceId = g_021AA7D4.overridedDeviceId;
        if (deviceId == 0) {
            deviceId = func_02165B68();
        }
    }
    if (func_02164F38(&expectLen, deviceId) == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (len < expectLen) {
        OS_RestoreInterrupts(e);
        return 6;
    }
    g_021AA7D4.wcmw = buf;
    ((WCMWork *)buf)->phase = 1;
    g_021AA7D4.wcmw->wmState = 0;
    g_021AA7D4.wcmw->maxScanTime = 0;
    g_021AA7D4.wcmw->resetting0 = 0;
    g_021AA7D4.wcmw->resetting = 0;
    g_021AA7D4.wcmw->deviceId = deviceId;
    func_021658F8();
    func_02166304();
    if (func_02087058() == 0) {
        func_02086FE8();
    }
    if (func_02087244() == 0) {
        func_02087208();
    }
    func_02087254(g_021AA7D4.wcmw->alarm);
    OS_RestoreInterrupts(e);
    return 0;
}
