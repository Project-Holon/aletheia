/*
 * file:     natneg_4.c
 * function: func_02199CE8
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
 *   func_0217ED38  0x0217ED38  arm
 *   SOC_GetHostByName  0x0215F650  arm
 */

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    unsigned int **addrList;
} SOCHostEnt;

extern int func_0217ED38(int a);
extern SOCHostEnt *SOC_GetHostByName(char *name);

unsigned int func_02199CE8(char *name)
{
    SOCHostEnt *hent;
    unsigned int ret;

    ret = func_0217ED38((int)name);
    if (ret != (unsigned int)-1)
        return ret;
    hent = SOC_GetHostByName(name);
    if (hent == 0)
        return 0;
    return **hent->addrList;
}
