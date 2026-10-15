/*
 * file:     card_rom.c
 * unit:     yes
 * function: CARDi_ReadCardWithHash, CARDi_ReadCardWithHashInternalAsync, CARDi_InitRomHash, data_0272EB9C
 * address:  0x0272E9E8
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libcard.TWL.HYB.a card_rom.o
 *
 * symbols:
 *   data_02732DC4  0x02732DC4  data twl
 *   CARD_ReadRomHashImage  0x0272F740  arm twl
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   CARDi_ReadRomWithDMA  0x02077008  arm
 *   CARD_NotifyRomHashReadAsync  0x0272EE2C  arm twl
 *   data_02150200  0x02150200  data
 *   data_02732DA8  0x02732DA8  data twl
 *   OS_GetArenaLo  0x02086580  arm
 *   OS_GetArenaHi  0x0208656C  arm
 *   OS_SetArenaLo  0x02086774  arm
 *   func_02075E04  0x02075E04  arm
 *   CARD_CalcRomHashBufferLength  0x0272EBDC  arm twl
 *   OS_Terminate  0x02088234  arm
 *   OS_GetBootType  0x02087B04  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   CARD_LockRom  0x02075E10  arm
 *   CARD_UnlockRom  0x02075E80  arm
 *   OS_ReleaseLockID  0x02084F10  arm
 *   CARDi_ReadRomWithCPU  0x02076E4C  arm
 *   CARD_InitRomHashContext  0x0272F0BC  arm twl
 *   data_02732DA0  0x02732DA0  data twl
 *   data_02732DA4  0x02732DA4  data twl
 *   data_02150840  0x02150840  data
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

struct Request {
    int f0;
    void (*callback)(void *);
    u32 a;
    u32 c;
    u32 b;
    u32 d;
    int f18;
};

extern struct SysState data_02150200;
extern struct Request data_02732DA8;
extern void DWCi_ScreenDC_FlushRange(u32, u32);
extern void CARDi_ReadRomWithDMA(struct Request *);
extern void CARD_NotifyRomHashReadAsync(void *);
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
extern int CARDi_ReadRomWithCPU(void *, void *, u32, u32);
extern void CARD_InitRomHashContext(void *, void *, u32, u32, void *, void *, void *);

void CARD_ReadRomHashImage(void *obj, u8 *buf, u32 off, u32 len);

int CARDi_ReadCardWithHash(int a0, int a1, int a2, int a3) {
    CARD_ReadRomHashImage(data_02732DC4, (u8 *)a1, a2, a3);
    return a3;
}

u32 CARDi_ReadCardWithHashInternalAsync(u32 a, u32 b, u32 c, u32 d)
{
    if (data_02150200.state == -1) {
        d = 0;
    } else {
        DWCi_ScreenDC_FlushRange(b, d);
        data_02732DA8.callback = CARD_NotifyRomHashReadAsync;
        data_02732DA8.a = a;
        data_02732DA8.c = c;
        data_02732DA8.b = b;
        data_02732DA8.d = d;
        data_02732DA8.f0 = 0;
        data_02732DA8.f18 = 0;
        CARDi_ReadRomWithDMA(&data_02732DA8);
    }
    return d;
}

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
    CARD_InitRomHashContext(data_02732DC4, func_02075E04(), data_02732DA0, data_02732DA4, CARDi_ReadRomWithCPU, CARDi_ReadCardWithHashInternalAsync, data_02732DC4);
    data_02732DA0 = 0;
    data_02732DA4 = 0;
    CARD_UnlockRom(lock);
    OS_ReleaseLockID(lock);
}

/*
 * 64 bytes of key data inside the code range of this unit
 * (0x0272EB9C..0x0272EBDC), read by CARD_InitRomHashContext as data_0272EB9C. The
 * bytes come from the user's own ROM: tools/gendata.py writes the
 * initializer to build/gen/twl_0272EB9C.inc (gitignored); run it before the
 * build. dcd lays the words out in .text, no prologue or epilogue.
 */
/* hand-written in the original: data words laid out in .text between functions, not compiled code */
asm void data_0272EB9C(void)
{
#include "../../../build/gen/twl_0272EB9C.inc"
}
