/*
 * function: CARDi_InitRomHash
 * address:  0x0272EA74
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   data_02732DA0 0x02732DA0 data twl
 *   data_02732DA4 0x02732DA4 data twl
 *   data_02732DC4 0x02732DC4 data twl
 *   data_02150200 0x02150200 data
 *   data_02150840 0x02150840 data
 *   OS_GetArenaLo 0x02086580 arm
 *   OS_GetArenaHi 0x0208656C arm
 *   func_02075E04 0x02075E04 arm
 *   CARD_CalcRomHashBufferLength 0x0272EBDC arm twl
 *   OS_Terminate 0x02088234 arm
 *   OS_SetArenaLo 0x02086774 arm
 *   OS_GetBootType 0x02087B04 arm
 *   OS_GetLockID 0x02084EB8 arm
 *   CARD_LockRom 0x02075E10 arm
 *   CARD_UnlockRom 0x02075E80 arm
 *   OS_ReleaseLockID 0x02084F10 arm
 *   CARD_InitRomHashContext 0x0272F0BC arm twl
 *   func_02076E4C 0x02076E4C arm
 *   CARDi_ReadCardWithHashInternalAsync 0x0272EA04 arm twl
 *   CARDi_ReadCardWithHash 0x0272E9E8 arm twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct SysState {
    char pad[0x508];
    int state;
};
struct Hook {
    int f0;
    void *callback;
};

extern struct SysState data_02150200;
extern struct Hook data_02150840;
extern u32 data_02732DA0, data_02732DA4;
extern u8 data_02732DC4[];
extern u32 OS_GetArenaLo(int arena);
extern u32 OS_GetArenaHi(int arena);
extern void OS_SetArenaLo(int arena, u32 addr);
extern void *func_02075E04(void);
extern u32 CARD_CalcRomHashBufferLength(void *hdr);
extern void OS_Terminate(void);
extern int OS_GetBootType(void);
extern int OS_GetLockID(void);
extern void CARD_LockRom(u16 id);
extern void CARD_UnlockRom(u16 id);
extern void OS_ReleaseLockID(u16 id);
extern int func_02076E4C(void *, void *, u32, u32);
extern u32 CARDi_ReadCardWithHashInternalAsync(u32, u32, u32, u32);
extern int CARDi_ReadCardWithHash(int, int, int, int);
extern void CARD_InitRomHashContext(void *, void *, u32, u32, void *, void *, void *);

void CARDi_InitRomHash(void)
{
    u32 lo = (OS_GetArenaLo(0) + 0x1f) & ~0x1f;
    u32 hi = OS_GetArenaHi(0);
    u32 size;
    u16 lock;

    size = CARD_CalcRomHashBufferLength(func_02075E04());
    if (lo + size > (hi & ~0x1f)) {
        OS_Terminate();
        return;
    }
    OS_SetArenaLo(0, lo + size);
    data_02732DA0 = lo;
    data_02732DA4 = size;
    if (OS_GetBootType() != 1) {
        return;
    }
    if (!(*(u8 *)0x02FFE01C & 1)) {
        return;
    }
    data_02150200.state = -1;
    data_02150840.callback = CARDi_ReadCardWithHash;
    lock = OS_GetLockID();
    CARD_LockRom(lock);
    CARD_InitRomHashContext(data_02732DC4, func_02075E04(), data_02732DA0, data_02732DA4, func_02076E4C, CARDi_ReadCardWithHashInternalAsync, data_02732DC4);
    data_02732DA0 = 0;
    data_02732DA4 = 0;
    CARD_UnlockRom(lock);
    OS_ReleaseLockID(lock);
}
