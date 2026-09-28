/*
 * function: func_0217F150
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
 *   func_0215F650                  0x0215F650  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   g_021A383C                     0x021A383C  data
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

extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern struct SOCHostEnt *func_0215F650(char *name);
extern void *func_0217EAB0(unsigned long size);
extern char g_021A383C[];

int func_0217F150(char *hostname, struct GSIResolveHostnameInfo **handle)
{
    struct GSIResolveHostnameInfo *info;
    struct SOCHostEnt *SOCHostEnt;

    func_0217D254(8, 3, 16, g_021A383C);
    SOCHostEnt = func_0215F650(hostname);
    if (SOCHostEnt == 0)
        return -1;
    info = (struct GSIResolveHostnameInfo *)func_0217EAB0(8);
    if (info == 0)
        return -1;
    info->ip = *(unsigned long *)SOCHostEnt->addrList[0];
    *handle = info;
    return 0;
}
