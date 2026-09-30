/*
 * function: SOCLi_StartupCPS
 * address:  0x0215CB24
 * packet:   pkt_ov009_0215CB24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss, 162 B; 17/17 relocations resolved, literal pool identical
 *                 in content and order, code identical to +0x5C; three coupled register
 *                 allocation differences from +0x60, 388 vs 380 B compiled)
 *
 * sdk:      SOCLi_StartupCPS (libsoc.TWL.HYB.a(socl_startup.o))
 *
 * symbols:
 *   MI_CpuFill8                 0x02082BCC arm
 *   CPS_SetThreadPriority       0x021576C8 arm
 *   WCM_SetRecvDCFCallback      0x02166424 arm
 *   CPS_SetScavengerCallback    0x02157630 arm
 *   CPS_SetCheckNConfigCallback 0x02157280 arm
 *   CPS_Startup                 0x021573C4 arm
 *   SOCL_LinkIsOn               0x0215CD24 arm
 *   SOCLi_SetMyIP               0x0215CCA0 arm
 *   SOCLi_DhcpTimeout           0x0215CD0C arm
 *   CPSi_RecvCallbackFunc       0x02157C28 arm
 *   SOCLi_TrashSocket           0x0215EBB4 arm
 *   SOCLi_CheckNConfig          0x0215F1D4 arm
 *   g_021A1CD8                  0x021A1CD8 data
 *   g_021AA440                  0x021AA440 data
 *   g_021AA450                  0x021AA450 data
 *   g_021A1CFC                  0x021A1CFC data
 *   g_021A82BC                  0x021A82BC data
 *
 * Static: clears the CPS configuration, copies the alloc/free/link callbacks and the
 * yield wait out of the SOCL configuration, picks the LAN buffer, clamps the MTU into
 * [0x240, 1500] and derives the TCP window and MSS from it, then selects the DHCP or
 * the static-IP startup and hands the configuration to CPS_Startup.
 *
 * Near miss, DIFF not MATCH: 162 concrete bytes differ, 388 compiled against 380 in
 * the object.  The 17 relocation sites all resolve, the 12-word literal pool is
 * byte-identical in content and order, and the code is identical to +0x5C.  All of the
 * residue is downstream of one allocator choice; the spellings tried for it are
 * recorded here rather than guessed at:
 *
 *   +0x60  the lan_buf select keeps its value in r1 here and in r0 in the object, so
 *          the object has to reload cps_config->lan_buflen at +0x70 (its r0 was
 *          clobbered by the select's own test) while this build forwards the stored
 *          value and needs a `mov r1, r0` after the call instead.
 *   +0xA8  the object holds the rwin local in r7, `mss - 0x28` in r4 and shifts the
 *          doubled value into r2 (mss's dead register), leaving r3 for the CPSMyIP
 *          zero; here rwin is r4, the difference is r3, the doubled value is r4 and the
 *          zero is r2.
 *   +0xDC  because the object frees r2 at +0xC8 it hoists the literal 1 into r2 ahead
 *          of the use_dhcp test, which leaves the then-arm at five instructions and gets
 *          it predicated (ldreq/streq).  This build rematerialises the 1 inside each
 *          arm, the then-arm becomes six instructions, misses the five-instruction
 *          predication threshold, branches, and the function is eight bytes longer.
 *
 * The object names its 0x021AA450 base SOCLiCPSConfig; this build reaches the same
 * address as &g_021AA440.cps, so the two ABS32 pool words carry equal values.
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets, plus all
 * 11 1.2/2.0 trees x -O4,p): no configuration reaches 380 bytes and none beats
 * 162 concrete bytes; 1.1p1 -O4,p stays the reference.  Residue already named in
 * full above (the +0x60 lan_buf select, the +0xA8 register trio and the +0xDC
 * predication threshold).  This row is the allocator wall of the slice.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

/* DWARF of the defining object: CPSConfig, 48 bytes. */
typedef struct
{
    u32 mode;
    void *(*alloc)(u32);
    void (*free)(void *);
    void (*dhcp_callback)(void);
    int (*link_is_on)(void);
    u64 random_seed;
    u8 *lan_buf;
    u32 lan_buflen;
    u32 mymss;
    u32 requested_ip;
    u32 yield_wait;
} CPSConfig;

/* DWARF: the 20-byte aggregate at +4 of SOCLConfig. */
typedef struct
{
    u32 addr;
    u32 mask;
    u32 gateway;
    u32 dns;
    u32 dns2;
} SOCLHostIp;

/* DWARF of the defining object: SOCLConfig, 56 bytes. */
typedef struct
{
    int use_dhcp;
    SOCLHostIp host_ip;
    void *(*alloc)(u32);
    void (*free)(void *);
    u32 cmd_packet_max;
    u32 lan_buffer_size;
    void *lan_buffer;
    long cps_thread_prio;
    long mtu;
    long rwin;
} SOCLConfig;

/*
 * The vendor object's data symbols at 0x021AA440..0x021AA47F are four 4-byte
 * scalars (SOCLiYieldWait, SOCLiRequestedIP, SOCLiDhcpState,
 * SOCLiUDPSendSocket) followed by SOCLiCPSConfig, 48 bytes.  The code
 * reaches all of them through address bases 0x021AA440 and 0x021AA450, so the
 * run is declared as the one object whose layout reproduces those bases.
 */
typedef struct
{
    u32 yieldWait;
    u32 requestedIp;
    u32 dhcpState;
    u32 udpSendSocket;
    CPSConfig cps;
} SOCLiCPSParam;

/* 0x021A1CD8: SOCLiConfigPtr and the word above it, one address base. */
typedef struct
{
    SOCLConfig *config;
    u32 defaultLanBufferSize;
} SOCLiStartupConfig;

extern SOCLiCPSParam g_021AA440;
extern SOCLiStartupConfig g_021A1CD8;
extern u16 g_021A1CFC[];
extern u32 g_021A82BC;

void MI_CpuFill8(void *dstp, u8 data, u32 size);
void CPS_SetThreadPriority(u32 new_prio);
void WCM_SetRecvDCFCallback(void (*callback)(u8 *, u8 *, u8 *, long));
void CPS_SetScavengerCallback(void (*f)(void));
void CPS_SetCheckNConfigCallback(int (*f)(void));
void CPS_Startup(CPSConfig *config);
int SOCL_LinkIsOn(void);
void SOCLi_SetMyIP(void);
void SOCLi_DhcpTimeout(void);
void CPSi_RecvCallbackFunc(u8 *, u8 *, u8 *, long);
void SOCLi_TrashSocket(void);
int SOCLi_CheckNConfig(void);

static void SOCLi_StartupCPS(void)
{
    CPSConfig *cps_config;
    SOCLConfig *socl_config;
    long mss;

    cps_config = &g_021AA440.cps;
    socl_config = g_021A1CD8.config;

    MI_CpuFill8(cps_config, 0, sizeof(CPSConfig));
    g_021AA440.cps.alloc = socl_config->alloc;
    g_021AA440.cps.free = socl_config->free;
    g_021AA440.cps.link_is_on = SOCL_LinkIsOn;
    g_021AA440.cps.random_seed = 0;
    g_021AA440.cps.yield_wait = g_021AA440.yieldWait;
    cps_config->lan_buflen = socl_config->lan_buffer_size != 0 ? socl_config->lan_buffer_size
                                                                : g_021A1CD8.defaultLanBufferSize;
    cps_config->lan_buf = socl_config->lan_buffer != 0 ? socl_config->lan_buffer
                                                       : g_021A1CD8.config->alloc(cps_config->lan_buflen);

    mss = socl_config->mtu;
    if (mss == 0) {
        mss = 0x240;
    }
    if (mss > 1500) {
        mss = 1500;
    } else if (mss < 0x240) {
        mss = 0x240;
    }
    {
        long rwin = socl_config->rwin;

        if (rwin == 0) {
            rwin = 0x10C0;
        }
        g_021A1CFC[1] = (u16)rwin;
        g_021A1CFC[2] = (u16)((mss - 0x28) * 2);
        cps_config->mymss = (u32)(mss - 0x28);
    }
    g_021A82BC = 0;
    if (socl_config->use_dhcp == 0) {
        g_021AA440.dhcpState = 0;
        cps_config->mode = 1;
        cps_config->dhcp_callback = SOCLi_SetMyIP;
    } else {
        cps_config->mode = 0;
        cps_config->dhcp_callback = SOCLi_DhcpTimeout;
        g_021AA440.dhcpState = 1;
        cps_config->requested_ip = g_021AA440.requestedIp;
    }
    CPS_SetThreadPriority(socl_config->cps_thread_prio == 0 ? 0xB : socl_config->cps_thread_prio);
    WCM_SetRecvDCFCallback(CPSi_RecvCallbackFunc);
    CPS_SetScavengerCallback(SOCLi_TrashSocket);
    CPS_SetCheckNConfigCallback(SOCLi_CheckNConfig);
    CPS_Startup(cps_config);
}
