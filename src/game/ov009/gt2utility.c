/*
 * file:     gt2utility.c
 * unit:     yes
 * function: gt2AddressToString, gt2StringToAddress, func_02198808
 * address:  0x02198620
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
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   g_021AE41C  0x021AE41C  data
 *   g_021AE420  0x021AE420  data
 *   g_021A594C  0x021A594C  data
 *   g_021A5954  0x021A5954  data
 *   g_021A5958  0x021A5958  data
 *   strchr              0x02094A28  arm
 *   memcpy              0x02092344  arm
 *   atoi                0x020964E0  arm
 *   inet_addr           0x0217ED38  arm  ov009
 *   SOC_GetHostByName   0x0215F650  arm  ov009
 *   __ctype_mapC        0x020A61DC  data
 *   strlen       0x0209477C arm
 *   g_021A595C   0x021A595C data
 */
#define GT2_ISDIGIT(c) ((u32)(c) >= 0x80 ? 0 : (__ctype_mapC[(c)] & 8))
typedef struct SOCInAddr {
	unsigned int addr;
} SOCInAddr;

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

extern char *func_0215FA9C(SOCInAddr in);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char *strchr();
extern void *memcpy();
extern int atoi();
extern u32 inet_addr();
extern SOCHostEnt *SOC_GetHostByName();
extern int strlen(const char *s);
char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
int gt2StringToAddress(char *string, u32 *ip, u16 *port);
void gti2MessageCheck(unsigned char **message, int *len);
extern int g_021AE41C;
extern char g_021AE420[][22];
extern char g_021A594C[];
extern char g_021A5954[];
extern char g_021A5958[];
extern u16 __ctype_mapC[];
extern char g_021A595C[];


/*
 * sdk:      gt2AddressToString (libdwcgsgt2.TWL.HYB.a(gt2utility.o))
 */
char *gt2AddressToString(unsigned int ip, unsigned short port, char *string)
{
	char *strAddress;
	SOCInAddr inAddr;

	if (string == 0) {
		g_021AE41C ^= 1;
		string = g_021AE420[g_021AE41C];
	}
	if (ip != 0) {
		inAddr.addr = ip;
		if (port != 0) {
			strAddress = func_0215FA9C(inAddr);
			OS_SPrintf(string, g_021A594C, strAddress, port);
		} else {
			strAddress = func_0215FA9C(inAddr);
			OS_SPrintf(string, g_021A5954, strAddress);
		}
	} else {
		if (port != 0)
			OS_SPrintf(string, g_021A5958, port);
		else
			string[0] = 0;
	}
	return string;
}


/*
 * sdk:      gt2StringToAddress (gt2utility.o)
 */
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


void gti2MessageCheck(unsigned char **message, int *len)
{
    if (*message == 0) {
        *message = (unsigned char *)g_021A595C;
        *len = 0;
        return;
    }
    if (*len == -1)
        *len = strlen((char *)*message) + 1;
}
