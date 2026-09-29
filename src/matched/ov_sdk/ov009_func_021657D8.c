/*
 * function: func_021657D8
 * address:  0x021657D8
 * packet:   pkt_ov009_021657D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmConfigure (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   g_021AA7D4     0x021AA7D4  data ov009
 *
 * Static: stores the DMA number, the word-aligned neighbour-descriptor buffer (zero-filled) and the notify callback into the WCM work area. The state block at 0x021AA7D4 holds the work pointer at +4.
 */

typedef struct WCMConfig {
    long dmano;
    void *pbdbuffer;
    long nbdbuffer;
    long nbdmode;
} WCMConfig;

typedef struct WCMWork {
    unsigned char pad0[0x12C0];
    WCMConfig config;
    void (*notify)(void *);
} WCMWork;

extern struct WcmState {
    int pad;
    WCMWork *wcmw;
} g_021AA7D4;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void func_021657D8(WCMConfig *config, void (*notify)(void *))
{
    if (config == 0) {
        g_021AA7D4.wcmw->config.dmano = 3;
        g_021AA7D4.wcmw->config.pbdbuffer = 0;
        g_021AA7D4.wcmw->config.nbdbuffer = 0;
        g_021AA7D4.wcmw->config.nbdmode = 0;
    } else {
        g_021AA7D4.wcmw->config.dmano = config->dmano & 3;
        if (((4 - ((unsigned long)config->pbdbuffer & 3)) & 3) + 12 > (unsigned long)config->nbdbuffer) {
            g_021AA7D4.wcmw->config.pbdbuffer = 0;
            g_021AA7D4.wcmw->config.nbdbuffer = 0;
        } else {
            g_021AA7D4.wcmw->config.pbdbuffer = (void *)(((unsigned long)config->pbdbuffer + 3) & ~3UL);
            g_021AA7D4.wcmw->config.nbdbuffer = config->nbdbuffer - ((4 - ((unsigned long)config->pbdbuffer & 3)) & 3);
            MI_CpuFill8(g_021AA7D4.wcmw->config.pbdbuffer, 0, g_021AA7D4.wcmw->config.nbdbuffer);
        }
        g_021AA7D4.wcmw->config.nbdmode = config->nbdmode;
    }
    g_021AA7D4.wcmw->notify = notify;
}
