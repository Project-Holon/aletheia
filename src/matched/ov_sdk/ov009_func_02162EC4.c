/*
 * function: CPSi_SslPeriodical
 * address:  0x02162EC4
 * packet:   pkt_ov009_02162EC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslPeriodical (ssl.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   gCpsSslSessionCache     0x021AA664  data
 *   gMslRefToken     0x02150FEC  data
 */

struct CPSSslSession {
    unsigned char sessionID[32];
    unsigned char master_secret[48];
    unsigned long when;
    unsigned long ip;
    unsigned short port;
    unsigned char valid;
    unsigned char padding;
};
struct _CPSSslConnection {
    char pad0[0x455];
    unsigned char state;
};
struct _CPSSoc {
    struct _OSThread *thread;
    unsigned long block_type;
    unsigned char state;
    unsigned char ssl;
    char pad0[0xc - 0xa];
    void *con;
    unsigned long when;
};
struct _OSThread {
    char pad0[0x68];
    struct _OSThread *next;
    char pad1[0xa4 - 0x6c];
    void *specific[3];
};
struct OSiThreadInfo {
    char pad0[8];
    struct _OSThread *list;
};

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern struct CPSSslSession gCpsSslSessionCache[4];
extern struct OSiThreadInfo gMslRefToken;

void CPSi_SslPeriodical(unsigned long now)
{
    int i;
    struct _CPSSoc *soc;
    struct _OSThread *t;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    for (i = 0; i < 4; i++) {
        struct CPSSslSession *p = &gCpsSslSessionCache[i];
        if (p->valid && (long)(now - p->when) > 957)
            p->valid = 0;
    }
    OS_RestoreInterrupts(enabled);

    for (t = gMslRefToken.list; t != 0; t = t->next) {
        soc = (struct _CPSSoc *)t->specific[0];
        if (soc && soc->thread && soc->ssl && soc->state == 4 &&
            ((struct _CPSSslConnection *)soc->con)->state < 8 &&
            (long)(now - soc->when) > 239 && soc->block_type == 2) {
            soc->state = 0;
            soc->block_type = 0;
            OS_WakeupThreadDirect(soc->thread);
        }
    }
}
