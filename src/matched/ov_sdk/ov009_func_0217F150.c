/*
 * function: gsiStartResolvingHostname
 * address:  0x0217F150
 * packet:   pkt_ov009_0217F150
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiStartResolvingHostname (gsplatformutil.o)
 *
 * symbols:
 *   func_0217D254                  0x0217D254  arm ov009
 *   SOC_GetHostByName                  0x0215F650  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   gGsResolveDebugFmt                     0x021A383C  data
 */

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};
struct GSIResolveHostnameInfo {
    void *pad0;
    unsigned long ip;
};

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern struct SOCHostEnt *SOC_GetHostByName(char *name);
extern void *func_0217EAB0(unsigned long size);
extern char gGsResolveDebugFmt[];

int gsiStartResolvingHostname(char *hostname, struct GSIResolveHostnameInfo **handle)
{
    struct GSIResolveHostnameInfo *info;
    struct SOCHostEnt *SOCHostEnt;

    func_0217D254(8, (char *)3, 16, gGsResolveDebugFmt);
    SOCHostEnt = SOC_GetHostByName(hostname);
    if (SOCHostEnt == 0)
        return -1;
    info = (struct GSIResolveHostnameInfo *)func_0217EAB0(8);
    if (info == 0)
        return -1;
    info->ip = *(unsigned long *)SOCHostEnt->addrList[0];
    *handle = info;
    return 0;
}
