/*
 * file:     unit_02198850_p01.c
 * unit:     yes
 * function: func_02198850, func_021988F4
 * address:  0x02198850
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
 *   func_02084F40  0x02084F40  arm
 *   g_021AE44C  0x021AE44C  data
 *   g_021AE46C  0x021AE46C  data
 *   g_021A5960  0x021A5960  data
 *   g_021A5968  0x021A5968  data
 *   g_021A596C  0x021A596C  data
 *   func_0217EFB8  0x0217EFB8  arm  ov009
 *   func_0217F038  0x0217F038  arm  ov009
 */
typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct {
    int pad0[7];
    int nIndex;
} AddressStringState;

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    SOCInAddr **addrList;
} SOCHostEnt;

extern char *func_0215FA9C(SOCInAddr in);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern SOCHostEnt *func_0217EFB8(void);
extern int func_0217F038(SOCInAddr *addr);
char *func_02198850(unsigned int ip, unsigned short port, char *string);
unsigned int func_021988F4(void);
extern AddressStringState g_021AE44C;
extern char g_021AE46C[2][22];
extern char g_021A5960[];
extern char g_021A5968[];
extern char g_021A596C[];


/*
 * sdk:      AddressToString (natify.o)
 */
char *func_02198850(unsigned int ip, unsigned short port, char *string)
{
    SOCInAddr inAddr;
    char *strAddress;

    if (!string) {
        g_021AE44C.nIndex ^= 1;
        string = g_021AE46C[g_021AE44C.nIndex];
    }
    if (ip) {
        inAddr.addr = ip;
        if (port) {
            strAddress = func_0215FA9C(inAddr);
            func_02084F40(string, g_021A5960, strAddress, port);
        } else {
            strAddress = func_0215FA9C(inAddr);
            func_02084F40(string, g_021A5968, strAddress);
        }
    } else if (port) {
        func_02084F40(string, g_021A596C, port);
    } else {
        string[0] = 0;
    }
    return string;
}


unsigned int func_021988F4(void)
{
    int num_local_ips;
    SOCHostEnt *phost;
    SOCInAddr *addr;
    unsigned int localip;

    localip = 0;
    phost = func_0217EFB8();
    if (!phost)
        return 0;
    for (num_local_ips = 0;; num_local_ips++) {
        addr = phost->addrList[num_local_ips];
        if (!addr)
            break;
        if (addr->addr != 16777343) {
            localip = *(unsigned int *)addr;
            if (func_0217F038((SOCInAddr *)addr))
                return localip;
        }
    }
    return localip;
}
