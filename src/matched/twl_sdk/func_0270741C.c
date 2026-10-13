/*
 * function: AESi_SeedRand
 * address:  0x0270741C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WaitResult  0x0270738C  arm twl a2
 *   AESi_PxiSendCmd  0x02707A94  arm twl a2
 *   AESi_TryLock  0x02707B0C  arm twl a2
 *   AESi_Unlock  0x02707BDC  arm twl a2
 */

typedef unsigned int u32;

extern u32 AESi_TryLock(void);
extern void AESi_PxiSendCmd(u32 cmd, u32 data, u32 size);
extern u32 WaitResult(void);
extern void AESi_Unlock(void);

u32 AESi_SeedRand(u32 a) {
    u32 result;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    AESi_PxiSendCmd(1, a, 0x14);
    result = WaitResult();
    AESi_Unlock();
    return result;
}
