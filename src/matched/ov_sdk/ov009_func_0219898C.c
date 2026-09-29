/*
 * function: func_0219898C
 * address:  0x0219898C
 * packet:   pkt_ov009_0219898C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OutputMapping (natify.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02198850  0x02198850  arm  ov009
 *   g_021A5970  0x021A5970  data
 *   g_021A5994  0x021A5994  data
 */

typedef struct _AddressMapping {
    unsigned int privateIP;
    unsigned short privatePort;
    unsigned short pad6;
    unsigned int publicIP;
    unsigned short publicPort;
} AddressMapping;

extern void func_0217D254(int cat, int type, int level, const char *fmt, ...);
extern char g_021A5970[];
extern char g_021A5994[];
extern char *func_02198850(unsigned int ip, unsigned short port, char *string);

void func_0219898C(AddressMapping *theMap)
{
    char *a;
    char *b;

    if (!theMap) {
        func_0217D254(7, 0, 0x10, g_021A5970);
        return;
    }
    a = func_02198850(theMap->privateIP, theMap->privatePort, 0);
    b = func_02198850(theMap->publicIP, theMap->publicPort, 0);
    func_0217D254(7, 0, 0x10, g_021A5994, a, b);
}
