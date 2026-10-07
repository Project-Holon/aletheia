/*
 * function: SOCLi_StartupCPS
 * address:  0x0215CB24
 * packet:   pkt_ov009_0215CB24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_StartupCPS (libsoc.TWL.HYB.a(socl_startup.o))
 *
 * 2026-10-01 (lane 14): EXACT (was 148 B, 388/380).  Closed by:
 *   - the object's data defined in the file (lever 2): SOCLiYieldWait,
 *     SOCLiRequestedIP, SOCLiDhcpState, SOCLiUDPSendSocket, SOCLiCPSConfig in
 *     .bss (declaration order chosen so 1.1p1 lays them out at +0/+4/+8/+C/+10)
 *     and SOCLiConfigPtr/SOCLiDefaultLanBufferSize in .data (ROM values 0 and
 *     0x4000; the zero pointer is kept in .data by `#pragma explicit_zero_data`,
 *     as the vendor object has it).  All fields go through cps_config; the
 *     anchor addressing is the compiler's, the old one-struct model is gone.
 *   - lan_buflen as an if/else of two stores: the front end then does not
 *     forward the value into the alloc argument and reloads it (replaces the
 *     old `volatile` field lever).
 *   - mymss stored before the sndbuf halfword (rwin r7, mss-0x28 r4).
 *   - DHCP arm first (`if (use_dhcp != 0)`) with dhcpState = 1 before the
 *     callback, so the shared 1 is hoisted and the static arm is the
 *     predicated else arm placed first.
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
 *   SOCLiConfigPtr              0x021A1CD8 data
 *   SOCLiDefaultLanBufferSize   0x021A1CDC data
 *   SOCLiYieldWait              0x021AA440 data
 *   SOCLiRequestedIP            0x021AA444 data
 *   SOCLiDhcpState              0x021AA448 data
 *   SOCLiUDPSendSocket          0x021AA44C data
 *   SOCLiCPSConfig              0x021AA450 data
 *   g_021A1CFC                  0x021A1CFC data
 *   g_021A82BC                  0x021A82BC data
 */

#include "../../../matched/include/G_SOCLSocketParam.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

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

typedef struct
{
    u32 addr;
    u32 mask;
    u32 gateway;
    u32 dns;
    u32 dns2;
} SOCLHostIp;

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

static u32 SOCLiDefaultLanBufferSize = 0x4000;
#pragma explicit_zero_data on
static SOCLConfig *SOCLiConfigPtr = 0;
#pragma explicit_zero_data reset
static CPSConfig SOCLiCPSConfig = { 0 };
static u32 SOCLiDhcpState = 0;
static u32 SOCLiRequestedIP = 0;
static u32 SOCLiUDPSendSocket = 0;
static u32 SOCLiYieldWait = 0;

extern struct SOCLSocketParam g_021A1CFC;
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

    cps_config = &SOCLiCPSConfig;
    socl_config = SOCLiConfigPtr;

    MI_CpuFill8(cps_config, 0, sizeof(CPSConfig));
    cps_config->alloc = socl_config->alloc;
    cps_config->free = socl_config->free;
    cps_config->link_is_on = SOCL_LinkIsOn;
    cps_config->random_seed = 0;
    cps_config->yield_wait = SOCLiYieldWait;
    if (socl_config->lan_buffer_size != 0)
        cps_config->lan_buflen = socl_config->lan_buffer_size;
    else
        cps_config->lan_buflen = SOCLiDefaultLanBufferSize;
    cps_config->lan_buf = socl_config->lan_buffer != 0 ? socl_config->lan_buffer
                                                       : SOCLiConfigPtr->alloc(cps_config->lan_buflen);

    mss = socl_config->mtu;
    if (mss == 0) {
        mss = 0x240;
    }
    if (mss > 1500) {
        mss = 1500;
    } else if (mss < 0x240) {
        mss = 0x240;
    }
    ((u16 *)&g_021A1CFC)[1] = (u16)(socl_config->rwin != 0 ? socl_config->rwin : 0x10C0);
    cps_config->mymss = (u32)(mss - 0x28);
    ((u16 *)&g_021A1CFC)[2] = (u16)((mss - 0x28) * 2);
    g_021A82BC = 0;
    if (socl_config->use_dhcp != 0) {
        cps_config->mode = 0;
        SOCLiDhcpState = 1;
        cps_config->dhcp_callback = SOCLi_DhcpTimeout;
        cps_config->requested_ip = SOCLiRequestedIP;
    } else {
        SOCLiDhcpState = 0;
        cps_config->mode = 1;
        cps_config->dhcp_callback = SOCLi_SetMyIP;
    }
    CPS_SetThreadPriority(socl_config->cps_thread_prio == 0 ? 0xB : socl_config->cps_thread_prio);
    WCM_SetRecvDCFCallback(CPSi_RecvCallbackFunc);
    CPS_SetScavengerCallback(SOCLi_TrashSocket);
    CPS_SetCheckNConfigCallback(SOCLi_CheckNConfig);
    CPS_Startup(cps_config);
}
