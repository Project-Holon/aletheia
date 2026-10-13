/*
 * file:     unit_0217F130.c
 * unit:     yes
 * function: func_0217F130, func_0217F150, func_0217F1C0, func_0217F1CC, func_0217F1E0, func_0217F21C
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
 *   SOC_GetHostByName                  0x0215F650  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   g_021A383C                     0x021A383C  data
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   strlen     0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memcpy     0x02092344  arm
 *   g_020A60DC     0x020A60DC  data
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
extern struct SOCHostEnt *SOC_GetHostByName(char *name);
extern void *func_0217EAB0(unsigned long size);
extern void func_0217EAE0(void *p);
extern int strlen(char *s);
extern void *gsimalloc(unsigned long size);
extern void *memcpy(void *dst, void *src, unsigned long n);
void func_0217F130(char *theNumberStr, long long theNumber);
int func_0217F150(char *hostname, struct GSIResolveHostnameInfo **handle);
void func_0217F1C0(void *p);
int func_0217F1CC(int *p);
char *goastrdup(char *src);
char *func_0217F21C(char *s);
extern char g_021A3834[];
extern char g_021A383C[];
extern unsigned char g_020A60DC[];



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


void func_0217F1C0(void *p)
{
    func_0217EAE0(p);
}



/*
 * Saves the word at +4, calls the helper and returns it.
 */
int func_0217F1CC(int *p)
{
    int v = p[1];

    func_0217EAE0(p);

    return v;
}



char *goastrdup(char *src)
{
    unsigned long len;
    char *res;

    if (src == 0)
        return 0;
    len = strlen(src);
    res = (char *)gsimalloc(len + 1);
    if (res != 0)
        memcpy(res, src, len + 1);

    return res;
}



/*
 * In-place character remap: for every byte of the NUL-terminated string at
 * s that is a non-negative value below 0x80, replace it with the byte at
 * the same index in the 128-entry table at 0x020A60DC; leave negative and
 * high bytes alone.  Returns s.
 */
char *func_0217F21C(char *s)
{
    char *ret = s;
    int c = *s;

    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = g_020A60DC[c];
            }
            *s = c;
            c = *++s;
        } while (c != 0);
    }
    return ret;
}
