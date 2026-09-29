/*
 * function: func_0215CB24
 * address:  0x0215CB24
 * region:   ov009
 * status:   MATCH (near miss, lane w8_s5, no shard)
 * note:     SOCLi_StartupCPS, about 160 B differ: mss/rwin register order (target keeps mtu in r2), the dhcp branch is conditional-executed in the target but a branch in ours, one extra pool word. Anchor struct at g_021AA440 (cps at +0x10) reproduces the base-relative stores.
 */
typedef unsigned long long u64;

typedef struct {
    int use_dhcp;
    char pad0[0x14];
    void *(*alloc)(unsigned long);
    void (*free)(void *);
    unsigned long cmd_packet_max;
    unsigned long lan_buffer_size;
    void *lan_buffer;
    long cps_thread_prio;
    long mtu;
    long rwin;
} SOCLConfig;

typedef struct {
    unsigned long mode;
    void *(*alloc)(unsigned long);
    void (*free)(void *);
    void (*dhcp_callback)(void);
    int (*link_is_on)(void);
    u64 random_seed;
    unsigned char *lan_buf;
    unsigned long lan_buflen;
    unsigned long mymss;
    unsigned long requested_ip;
    unsigned long yield_wait;
} CPSConfig;

typedef struct {
    SOCLConfig *config;
    unsigned long defaultLanBufferSize;
} ConfigPtr;

typedef struct {
    unsigned long yieldWait;
    unsigned long requestedIp;
    unsigned long dhcpState;
    unsigned long udpSendSocket;
    CPSConfig cps;
} Anchor;

extern ConfigPtr g_021A1CD8;
extern CPSConfig g_021AA450;
extern Anchor g_021AA440;
extern unsigned short g_021A1CFC[3];
extern unsigned long g_021A82BC;

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_021576C8(unsigned long new_prio);
extern void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
extern void func_02157630(void (*f)(void));
extern void func_02157280(int (*f)(void));
extern void func_021573C4(CPSConfig *config);
extern int func_0215CD24(void);
extern void func_0215CCA0(void);
extern void func_0215CD0C(void);
extern void func_02157C28(unsigned char *, unsigned char *, unsigned char *, long);
extern void func_0215EBB4(void);
extern int func_0215F1D4(void);

static void func_0215CB24(void)
{
    CPSConfig *cps_config;
    SOCLConfig *socl_config;
    long mss;

    cps_config = &g_021AA450;
    socl_config = g_021A1CD8.config;
    func_02082BCC(cps_config, 0, sizeof(CPSConfig));
    g_021AA440.cps.alloc = socl_config->alloc;
    g_021AA440.cps.free = socl_config->free;
    g_021AA440.cps.link_is_on = func_0215CD24;
    g_021AA440.cps.random_seed = 0;
    g_021AA440.cps.yield_wait = g_021AA440.yieldWait;
    cps_config->lan_buflen = socl_config->lan_buffer_size != 0 ? socl_config->lan_buffer_size
                                                                : g_021A1CD8.defaultLanBufferSize;
    cps_config->lan_buf = socl_config->lan_buffer != 0 ? socl_config->lan_buffer
                                                       : g_021A1CD8.config->alloc(cps_config->lan_buflen);

    mss = socl_config->mtu;
    if (mss == 0)
        mss = 0x240;
    if (mss > 1500)
        mss = 1500;
    else if (mss < 0x240)
        mss = 0x240;
    {
        long rwin = socl_config->rwin;
        if (rwin == 0)
            rwin = 0x10C0;
        g_021A1CFC[1] = (unsigned short)rwin;
    }
    g_021A1CFC[2] = (unsigned short)((mss - 0x28) * 2);
    cps_config->mymss = mss - 0x28;
    g_021A82BC = 0;
    if (socl_config->use_dhcp == 0) {
        g_021AA440.dhcpState = 0;
        cps_config->mode = 1;
        cps_config->dhcp_callback = func_0215CCA0;
    } else {
        cps_config->mode = 0;
        cps_config->dhcp_callback = func_0215CD0C;
        g_021AA440.dhcpState = 1;
        cps_config->requested_ip = g_021AA440.requestedIp;
    }
    func_021576C8(socl_config->cps_thread_prio == 0 ? 0xB : socl_config->cps_thread_prio);
    func_02166424(func_02157C28);
    func_02157630(func_0215EBB4);
    func_02157280(func_0215F1D4);
    func_021573C4(cps_config);
}
