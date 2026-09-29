/*
 * function: func_021656D0
 * address:  0x021656D0
 * packet:   pkt_ov009_021656D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_UpdateOption (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Merges new option bits into the WCM option word under a critical section and returns the previous word.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12D4];
    unsigned long option;
} WCMWork;

typedef struct WCMState {
    long pad0;
    WCMWork *work;
} WCMState;

extern WCMState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

unsigned long func_021656D0(unsigned long option)
{
    unsigned long e;
    unsigned long filter;
    unsigned long old_option;

    e = OS_DisableInterrupts();
    filter = 0;
    old_option = g_021AA7D4.work->option;
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    if ((option & 0x8000) != 0) {
        filter |= 0x3FFE;
        if ((option & 0x3FFE) == 0) {
            option |= 0xA082;
        }
    }
    if ((option & 0x20000) != 0) {
        filter |= 0x10000;
    }
    if ((option & 0x80000) != 0) {
        filter |= 0x40000;
    }
    if ((option & 0x200000) != 0) {
        filter |= 0x100000;
    }
    if ((option & 0x800000) != 0) {
        filter |= 0x400000;
    }
    g_021AA7D4.work->option = option | (old_option & ~filter);
    OS_RestoreInterrupts(e);
    return old_option;
}
