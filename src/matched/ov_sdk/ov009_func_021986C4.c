/*
 * function: gt2StringToAddress
 * address:  0x021986C4
 * packet:   pkt_ov009_021986C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gt2StringToAddress (gt2utility.o)
 *
 * symbols:
 *   strchr              0x02094A28  arm
 *   memcpy              0x02092344  arm
 *   atoi                0x020964E0  arm
 *   inet_addr           0x0217ED38  arm  ov009
 *   SOC_GetHostByName   0x0215F650  arm  ov009
 *   __ctype_mapC        0x020A61DC  data
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

int gt2StringToAddress(char *string, u32 *ip, u16 *port)
{
    u32 srcIP = 0;
    u16 srcPort = 0;

    if (!string || !string[0])
    {
        srcIP = 0;
        srcPort = 0;
    }
    else
    {
        char stackHost[257];
        char *colon;
        char *host;

        colon = strchr(string, ':');
        if (!colon)
        {
            host = string;
            srcPort = 0;
        }
        else
        {
            char *check;
            int len;
            int temp;

            if (colon == string)
            {
                host = 0;
                srcIP = 0;
            }
            else
            {
                len = colon - string;
                memcpy(stackHost, string, len);
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
            SOCHostEnt *he;

            srcIP = inet_addr(host);
            if (srcIP == 0xFFFFFFFF)
            {
                he = SOC_GetHostByName(host);
                if (he == 0)
                    return 0;
                srcIP = *(u32 *)he->addrList[0];
            }
        }
    }

    if (ip)
        *ip = srcIP;
    if (port)
        *port = srcPort;
    return 1;
}
