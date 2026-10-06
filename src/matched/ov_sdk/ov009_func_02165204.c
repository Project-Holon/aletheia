/*
 * function: func_02165204
 * address:  0x02165204
 * packet:   pkt_ov009_02165204
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_EndSearchAsync (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Ends an AP search: only valid in the search phases, moves to the search-ending phase and reports pending.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[2];
    unsigned char phase;
} WCMWork;

typedef struct WCMState {
    long pad0;
    WCMWork *work;
} WCMState;

extern WCMState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_02165A4C(unsigned char phase);

long func_02165204(int a, int b)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (g_021AA7D4.work->phase) {
    case 6:
        func_02165A4C(7);
        g_021AA7D4.work->notify = 4;
        break;
    case 7:
        OS_RestoreInterrupts(e);
        return 2;
    case 3:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    }
    OS_RestoreInterrupts(e);
    return 3;
}
