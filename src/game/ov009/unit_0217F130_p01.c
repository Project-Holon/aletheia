/*
 * file:     unit_0217F130_p01.c
 * unit:     yes
 * function: func_0217F130, func_0217F150
 * address:  0x0217F130
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02084F40                  0x02084F40  arm
 *   g_021A3834                     0x021A3834  data
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

extern int func_02084F40(char *dst, char *fmt, ...);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern struct SOCHostEnt *func_0215F650(char *name);
extern void *func_0217EAB0(unsigned long size);
void func_0217F130(char *theNumberStr, long long theNumber);
int func_0217F150(char *hostname, struct GSIResolveHostnameInfo **handle);
extern char g_021A3834[];
extern char g_021A383C[];


/*
 * sdk:      gsiInt64ToString (gsplatformutil.o)
 */
void func_0217F130(char *theNumberStr, long long theNumber)
{
    func_02084F40(theNumberStr, g_021A3834, theNumber);
}


/*
 * sdk:      gsiStartResolvingHostname (gsplatformutil.o)
 */
int func_0217F150(char *hostname, struct GSIResolveHostnameInfo **handle)
{
    struct GSIResolveHostnameInfo *info;
    struct SOCHostEnt *SOCHostEnt;

    func_0217D254(8, (char *)3, 16, g_021A383C);
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
