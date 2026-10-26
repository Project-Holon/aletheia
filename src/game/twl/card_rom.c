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
 *   DC_FlushRange  0x020862F0  arm
 *   CARDi_ReadRomWithDMA  0x02077008  arm
 *   CARD_NotifyRomHashReadAsync  0x0272EE2C  arm twl
 *   cardi_common  0x02150200  data
 *   data_02732DA8  0x02732DA8  data twl
 *   OS_GetArenaLo  0x02086580  arm
 *   OS_GetArenaHi  0x0208656C  arm
 *   OS_SetArenaLo  0x02086774  arm
 *   CARD_GetOwnRomHeaderTWL  0x02075E04  arm
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
 *   cardi_rom_base  0x02150840  data
 */
#include "../types.h"

struct SysState {
    char pad[0x508];
    int state;
};
struct Hook {
    int pad0;
    void *callback;
};

#include "../arm9/card_rom.h"

extern struct SysState cardi_common;
extern struct CARDTransferInfo data_02732DA8;
#include "../arm9/os_cache.h"
extern struct Hook cardi_rom_base;
extern u8 *data_02732DA0;
extern u32 data_02732DA4;
extern u8 data_02732DC4[];
#include "../arm9/os_arena.h"
#include "../arm9/card_api.h"
#include "card_hash.h"
#include "../arm9/os_terminate_processor.h"
#include "../arm9/os_systemwork.h"
#include "../arm9/os_spinlock.h"
#include "../arm9/card_pullout.h"

int CARDi_ReadCardWithHash(void *userdata, void *buffer, u32 offset, u32 length) {
    CARD_ReadRomHashImage((CardHash *)data_02732DC4, buffer, offset, length);
    return length;
}

int CARDi_ReadCardWithHashInternalAsync(void *userdata, void *buffer, u32 offset, u32 length)
{
    if (cardi_common.state == -1) {
        length = 0;
    } else {
        DC_FlushRange(buffer, length);
        data_02732DA8.callback = CARD_NotifyRomHashReadAsync;
        data_02732DA8.userdata = userdata;
        data_02732DA8.src = offset;
        data_02732DA8.dst = (uptr)buffer;
        data_02732DA8.len = length;
        data_02732DA8.command = 0;
        data_02732DA8.work = 0;
        CARDi_ReadRomWithDMA(&data_02732DA8);
    }
    return length;
}

void CARDi_InitRomHash(void)
{
    uptr lo = ((uptr)OS_GetArenaLo(0) + 0x1f) & ~0x1f;
    uptr hi = (uptr)OS_GetArenaHi(0);
    u32 size;
    u16 lock;

    size = CARD_CalcRomHashBufferLength(CARD_GetOwnRomHeaderTWL());
    if (lo + size > (hi & ~0x1f)) {
        OS_Terminate();
        return;
    }
    OS_SetArenaLo(0, (void *)(lo + size));
    data_02732DA0 = (u8 *)lo;
    data_02732DA4 = size;
    if (OS_GetBootType() != 1) {
        return;
    }
    if (!(*(u8 *)0x02FFE01C & 1)) {
        return;
    }
    cardi_common.state = -1;
    cardi_rom_base.callback = CARDi_ReadCardWithHash;
    lock = OS_GetLockID();
    CARD_LockRom(lock);
    CARD_InitRomHashContext((CardHash *)data_02732DC4, (const RomHdr *)CARD_GetOwnRomHeaderTWL(), data_02732DA0, data_02732DA4, CARDi_ReadRomWithCPU, CARDi_ReadCardWithHashInternalAsync, data_02732DC4);
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
