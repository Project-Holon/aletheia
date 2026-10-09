/*
 * file:     unit_021B6D8C_p05.c
 * unit:     yes
 * function: AOSS_SetIPAddr, AOSS_Disconnect, AOSS_Memcmp
 * address:  0x021B8194
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   aoss_data    0x021DAAB4  data
 *   CPSMyIp      0x021A82BC  data
 *   AOSS_Htonl   0x021B82E4  thumb
 *   SOC_Startup  0x0215F8FC  arm
 *   OS_Sleep     0x02085A38  arm
 *   SOC_Cleanup       0x0215FA90  arm
 *   AOSSi_Disconnect  0x021B8640  thumb
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

extern unsigned long AOSS_Htonl(unsigned long hostlong);
extern int SOC_Startup(SOCConfig *config);
extern void OS_Sleep(unsigned long msec);
extern int SOC_Cleanup(void);
extern int AOSSi_Disconnect(void);
int AOSS_SetIPAddr(unsigned long ip, unsigned long sm, unsigned long gw);
int AOSS_Disconnect(void);
int AOSS_Memcmp(void *s1, void *s2, int n);
extern AOSS_DATA_SECTION aoss_data;
extern unsigned long CPSMyIp;



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



int AOSS_Disconnect(void)
{
    if (SOC_Cleanup() < 0)
        return -1;
    return -(AOSSi_Disconnect() != 0);
}

int AOSS_Memcmp(void *s1, void *s2, int n)
{
    unsigned char *c1 = s1;
    unsigned char *c2 = s2;
    int diff = 0;

    while (n-- > 0 && (diff = *c1 - *c2) == 0) {
        c1++;
        c2++;
    }
    return diff;
}
