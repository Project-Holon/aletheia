/*
 * function: OS_GetTick
 * address:  0x020870D0
 * packet:   pkt_020870D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_tick.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The
 * object's .bss is addressed section-relative from one pool word (OsTickBss):
 * OSi_UseTick (u16) at +0 and OSi_TickCounter (u64) at +8; the word at +4 is
 * taken to be OSi_NeedResetTimer, the object's other 4-byte datum.  The
 * counter is volatile in the vendor header (it is written by the timer
 * interrupt): the plain declaration hoists the section load above countL.
 *
 * symbols:
 *   g_02151330            0x02151330  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef u32 OSIntrMode;
typedef u64 OSTick;

typedef struct OsTickBss {
    u16 OSi_UseTick;
    u32 OSi_NeedResetTimer;
    vu64 OSi_TickCounter;
} OsTickBss;

extern OsTickBss g_02151330;
#define OSi_TickCounter (g_02151330.OSi_TickCounter)

#define reg_OS_IF (*(vu32 *)0x04000214)

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

OSTick OS_GetTick(void)
{
    vu16 countL;
    vu64 countH;

    OSIntrMode prev = OS_DisableInterrupts();
    countL = *(vu16 *)0x04000100;
    countH = OSi_TickCounter & 0xffffffffffffULL;

    if ((reg_OS_IF & 0x8) && !(countL & 0x8000)) {
        countH++;
    }
    (void)OS_RestoreInterrupts(prev);

    return (countH << 16) | countL;
}
