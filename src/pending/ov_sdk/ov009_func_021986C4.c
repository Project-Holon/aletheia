/*
 * function: func_021986C4
 * address:  0x021986C4
 * packet:   pkt_ov009_021986C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    4 B over (328 vs 324): zero constants in isdigit use a fresh reg (mov r2,#0) and r4 for host=0 and stackHost[len]=0 where the image reuses r5 and r4
 *
 * sdk:      gt2StringToAddress (libdwcgsgt2.TWL.HYB.a(gt2utility.o))
 *
 * symbols:
 *   strchr              0x02094A28  arm
 *   memcpy              0x02092344  arm
 *   atoi                0x020964E0  arm
 *   inet_addr           0x0217ED38  arm  ov009
 *   SOC_GetHostByName   0x0215F650  arm  ov009
 *   __ctype_mapC        0x020A61DC  data
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets): no
 * configuration reaches 324 bytes; 1.1p1 -O4,p at 328/189 concrete bytes is best
 * (-O4,s gives 308/173, also 4 bytes short, different stream).
 * The 4 bytes are one extra `mov r2, #0`: the image reuses the live zero that
 * `srcIP = 0` already holds (r4) for the GT2_ISDIGIT clamp (`movhs r0, r4` at
 * +0084), this build materialises a fresh zero in r2 in the loop preheader
 * (+0074 `mov r2, #0`, then `movhs r0, r2`), which also pushes `check` from the
 * image's r2 into r3 and takes `host = 0` / `stackHost[len] = 0` off the image's
 * r5 onto r4.  Named residue: the clamp's zero is not textually the `srcIP = 0`
 * value (a fresh literal), so the allocator gives it its own register.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SOCHostEnt
{
    char *name;
    char **aliases;
    short addrType;
    short length;
    u8 **addrList;
} SOCHostEnt;

extern char *strchr();
extern void *memcpy();
extern int atoi();
extern u32 inet_addr();
extern SOCHostEnt *SOC_GetHostByName();
extern u16 __ctype_mapC[];

#define GT2_ISDIGIT(c) ((u32)(c) >= 0x80 ? 0 : (__ctype_mapC[(c)] & 8))

int func_021986C4(char *string, u32 *ip, u16 *port)
{
    u16 srcPort = 0;
    u32 srcIP = 0;
    char stackHost[257];
    char *colon;
    char *host;
    int len;
    char *check;
    int temp;
    SOCHostEnt *SOCHostEnt;

    host = string;
    if (!host || !*host)
    {
        srcIP = 0;
        srcPort = srcIP;
    }
    else
    {
        colon = strchr(host, ':');
        if (colon)
        {
            if (colon == host)
            {
                host = 0;
            }
            else
            {
                len = colon - host;
                memcpy(stackHost, host, len);
                stackHost[len] = 0;
                host = stackHost;
            }
            for (check = colon + 1; *check; check++)
            {
                if (!GT2_ISDIGIT(*check))
                    return 0;
            }
            temp = atoi(colon + 1);
            if (temp < 0 || temp > 0xFFFF)
                return 0;
            srcPort = (u16)temp;
        }
        if (host)
        {
            srcIP = inet_addr(host);
            if (srcIP == 0xFFFFFFFF)
            {
                SOCHostEnt = SOC_GetHostByName(host);
                if (!SOCHostEnt)
                    return 0;
                srcIP = *(u32 *)SOCHostEnt->addrList[0];
            }
        }
    }
    if (ip)
        *ip = srcIP;
    if (port)
        *port = srcPort;
    return 1;
}
