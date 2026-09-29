/*
 * function: func_02198850
 * address:  0x02198850
 * packet:   pkt_ov009_02198850
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      AddressToString (natify.o)
 *
 * symbols:
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   g_021AE44C  0x021AE44C  data
 *   g_021AE46C  0x021AE46C  data
 *   g_021A5960  0x021A5960  data
 *   g_021A5968  0x021A5968  data
 *   g_021A596C  0x021A596C  data
 */

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct {
    int pad0[7];
    int nIndex;
} AddressStringState;

extern AddressStringState g_021AE44C;
extern char g_021AE46C[2][22];
extern char g_021A5960[];
extern char g_021A5968[];
extern char g_021A596C[];
extern char *func_0215FA9C(SOCInAddr in);
extern int func_02084F40(char *dst, const char *fmt, ...);

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
