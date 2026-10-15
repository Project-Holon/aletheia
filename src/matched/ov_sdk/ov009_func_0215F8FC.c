/*
 * function: SOC_Startup
 * address:  0x0215F8FC
 * packet:   pkt_ov009_0215F8FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Startup (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:
 *   SOCL_Startup  0x0215CA8C  arm  ov009
 *   gSocStatics     0x021AA4BC  data
 *   func_0215F8A4  0x0215F8A4  arm  ov009
 *   func_0215F8D0  0x0215F8D0  arm  ov009
 *   gSoclStartupConfig     0x021AA50C  data
 *
 * soc.o's statics sit in one block; the vendor addresses the stores through
 * one pool word anchored at 0x021AA4BC (hostip_1 of SOC_GetHostByName) and
 * passes soclConfig (0x021AA50C, block +0x50) by its own symbol, so the block
 * is written as a struct overlay named by offset and the call argument as its
 * own extern.
 */

typedef unsigned long u32;

#define SOC_HtoNl(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                      (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

typedef struct SOCConfig {
    unsigned short vendor;
    unsigned short version;
    void *(*alloc)(u32, long);
    void (*free)(u32, void *, long);
    u32 flag;
    u32 addr;
    u32 netmask;
    u32 router;
    u32 dns1;
    u32 dns2;
    long timeWaitBuffer;
    long reassemblyBuffer;
    long mtu;
    long rwin;
} SOCConfig;

typedef struct SOCLConfig {
    int use_dhcp;
    u32 my_ip;
    u32 net_mask;
    u32 gateway_ip;
    u32 dns_ip0;
    u32 dns_ip1;
    void *(*alloc)(u32);
    void (*free)(void *);
    u32 cmd_packet_max;
    u32 pad24[3];
    long mtu;
    long rwin;
} SOCLConfig;

typedef struct SOCStatics {
    char pad0[4];
    void (*FreeFunc_SOC)(u32, void *, long);
    char pad8[4];
    void *(*AllocFunc_SOC)(u32, long);
    char pad10[0x50 - 0x10];
    SOCLConfig soclConfig;
} SOCStatics;

extern int SOCL_Startup(void *socl_config);
extern void *func_0215F8A4(u32 size);
extern void func_0215F8D0(void *ptr);
extern SOCStatics gSocStatics;
extern SOCLConfig gSoclStartupConfig;

int SOC_Startup(const SOCConfig *config)
{
    gSocStatics.soclConfig.use_dhcp = (config->flag == 1);
    gSocStatics.soclConfig.my_ip = SOC_HtoNl(config->addr);
    gSocStatics.soclConfig.net_mask = SOC_HtoNl(config->netmask);
    gSocStatics.soclConfig.gateway_ip = SOC_HtoNl(config->router);
    gSocStatics.soclConfig.dns_ip0 = SOC_HtoNl(config->dns1);
    gSocStatics.soclConfig.dns_ip1 = SOC_HtoNl(config->dns2);
    gSocStatics.soclConfig.alloc = func_0215F8A4;
    gSocStatics.soclConfig.free = func_0215F8D0;
    gSocStatics.AllocFunc_SOC = config->alloc;
    gSocStatics.FreeFunc_SOC = config->free;
    gSocStatics.soclConfig.cmd_packet_max = 0x40;
    gSocStatics.soclConfig.mtu = config->mtu;
    gSocStatics.soclConfig.rwin = config->rwin;
    return SOCL_Startup(&gSoclStartupConfig);
}
