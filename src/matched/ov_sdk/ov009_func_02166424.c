/*
 * function: func_02166424
 * address:  0x02166424
 * packet:   pkt_ov009_02166424
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_SetRecvDCFCallback (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA7DC  0x021AA7DC  data ov009
 *
 * Installs the DCF receive callback in the CPS interface work under a critical section.
 */

typedef struct WCMCpsifWork {
    unsigned char pad0[0x28];
    void (*recvCb)(unsigned char *, unsigned char *, unsigned char *, long);
} WCMCpsifWork;

extern WCMCpsifWork g_021AA7DC;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long))
{
    unsigned long e;

    e = OS_DisableInterrupts();
    g_021AA7DC.recvCb = callback;
    OS_RestoreInterrupts(e);
}
