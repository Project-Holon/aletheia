/*
 * file:     socl_startup.c
 * unit:     yes
 * function: func_0215CA8C, func_0215CAE4, SOCLi_StartupCPS, func_0215CCA0, SOCLi_DhcpTimeout, func_0215CD24
 * address:  0x0215CA8C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   .bss           0x021AA440  data
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   func_0215F0D4  0x0215F0D4  arm  ov009
 *   func_0215EC90  0x0215EC90  arm  ov009
 *   func_0215CD3C  0x0215CD3C  arm  ov009
 *   func_0215D070  0x0215D070  arm  ov009
 *   func_02166384  0x02166384  arm  ov009
 *   g_020050C4  0x020050C4  data
 *   g_021A1D14  0x021A1D14  data
 *   g_021A827C  0x021A827C  data
 *   g_021A8298  0x021A8298  data
 *   g_021A82DC  0x021A82DC  data
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
#include "../../matched/include/G_SOCLSocketParam.h"

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
static void *SOCLiUDPSendSocket = 0;
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
extern void OSi_ReferSymbol(const void *symbol);
extern void func_0215F0D4(void);
extern void func_0215EC90(void);
extern int func_0215CD3C(long cp_max_count);
extern void *func_0215D070(void *param);
extern unsigned char *func_02166384(void);
extern char g_020050C4[42];
extern int g_021A1D14;
extern u32 g_021A827C;
extern u32 g_021A8298;
extern u32 g_021A82DC[2];
int func_0215CA8C(SOCLConfig *socl_config);
int func_0215CAE4(void);
void func_0215CCA0(void);
int func_0215CD24(void);
static void SOCLi_StartupCPS(void);


/*
 * sdk:      SOCL_Startup (libsoc.TWL.HYB.a(socl_startup.o))
 */
int func_0215CA8C(SOCLConfig *socl_config)
{
	int result;

	OSi_ReferSymbol(g_020050C4);
	if (SOCLiConfigPtr != 0) {
		return 0;
	}
	func_0215F0D4();
	SOCLiConfigPtr = socl_config;
	SOCLi_StartupCPS();
	result = func_0215CAE4();
	if (result < 0) {
		func_0215EC90();
		SOCLiConfigPtr = 0;
	}
	return result;
}


/*
 * sdk:      SOCLi_StartupSOCL (libsoc.TWL.HYB.a(socl_startup.o))
 */
int func_0215CAE4(void)
{
	int r;

	r = func_0215CD3C(SOCLiConfigPtr->cmd_packet_max);
	if (r >= 0) {
		SOCLiUDPSendSocket = func_0215D070(&g_021A1D14);
	}
	return r;
}

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

/*
 * sdk:      SOCLi_SetMyIP (libsoc.TWL.HYB.a(socl_startup.o))
 */
void func_0215CCA0(void)
{
	g_021A82BC = SOCLiConfigPtr->host_ip.addr;
	g_021A827C = SOCLiConfigPtr->host_ip.mask;
	g_021A8298 = SOCLiConfigPtr->host_ip.gateway;
	g_021A82DC[0] = SOCLiConfigPtr->host_ip.dns;
	g_021A82DC[1] = SOCLiConfigPtr->host_ip.dns2;
	SOCLiDhcpState |= 2;
}

void SOCLi_DhcpTimeout(void)
{
	SOCLiDhcpState |= 2;
}

/*
 * Non-zero test on the word call.
 */
int func_0215CD24(void)
{
    return func_02166384() != 0;
}
