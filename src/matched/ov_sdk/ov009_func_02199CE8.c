/*
 * function: NameToIp
 * address:  0x02199CE8
 * packet:   pkt_ov009_02199CE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NameToIp (natify.o)
 *
 * symbols:
 *   inet_addr  0x0217ED38  arm
 *   SOC_GetHostByName  0x0215F650  arm
 */

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    unsigned int **addrList;
} SOCHostEnt;

extern int inet_addr(int a);
extern SOCHostEnt *SOC_GetHostByName(char *name);

unsigned int NameToIp(char *name)
{
    SOCHostEnt *hent;
    unsigned int ret;

    ret = inet_addr((int)name);
    if (ret != (unsigned int)-1)
        return ret;
    hent = SOC_GetHostByName(name);
    if (hent == 0)
        return 0;
    return **hent->addrList;
}
