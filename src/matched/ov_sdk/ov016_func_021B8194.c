/*
 * function: AOSS_SetIPAddr
 * address:  0x021B8194
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_data    0x021DAAB4  data
 *   CPSMyIp      0x021A82BC  data
 *   AOSS_Htonl   0x021B82E4  thumb
 *   SOC_Startup  0x0215F8FC  arm
 *   OS_Sleep     0x02085A38  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_SetIPAddr (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8194.c \
 *       --func AOSS_SetIPAddr --addr 0x021B8194 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

/*
 * aoss.o's 96-byte .data section (0x021DAAB4): s_sFd, AOSS_StatusExclusion's
 * static before, and soconfig, declared as one object because the vendor
 * object addresses them section-relative.
 */
typedef struct {
    unsigned char  pad00[0x10];
    unsigned long  addr;       /* +0x10 */
    unsigned long  netmask;    /* +0x14 */
    unsigned long  router;     /* +0x18 */
    unsigned char  pad1C[0x58 - 0x1C];
} SOCConfig;

typedef struct {
    int       s_sFd;
    int       before;
    SOCConfig soconfig;
} AOSS_DATA_SECTION;

extern AOSS_DATA_SECTION aoss_data;
extern unsigned long CPSMyIp;
extern unsigned long AOSS_Htonl(unsigned long hostlong);
extern int SOC_Startup(SOCConfig *config);
extern void OS_Sleep(unsigned long msec);

int AOSS_SetIPAddr(unsigned long ip, unsigned long sm, unsigned long gw)
{
    aoss_data.soconfig.addr = AOSS_Htonl(ip);
    aoss_data.soconfig.netmask = AOSS_Htonl(sm);
    aoss_data.soconfig.router = AOSS_Htonl(gw);
    if (SOC_Startup(&aoss_data.soconfig) < 0)
        return -1;
    while (CPSMyIp == 0)
        OS_Sleep(100);
    return 0;
}
