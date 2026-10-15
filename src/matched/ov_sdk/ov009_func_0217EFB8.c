/*
 * function: getlocalhost
 * address:  0x0217EFB8
 * packet:   pkt_ov009_0217EFB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      getlocalhost (gsplatformsocket)
 *
 * note: function-local statics, declared in the order aliases_0, localhost,
 * ips_2, ipPtrs_1 (they reach r4 as one base).  The first literal (+0x6C) is
 * relocated against `.bss`+0 by 1.1p1; the four static symbols: lines place
 * that section and agree on one base.
 *
 * symbols:
 *   func_0215EF48                  0x0215EF48  arm ov009
 *   SOC_U32to4U8                  0x0215FBAC  arm ov009
 *   gGsLocalhostName                     0x021A37BC  data
 *   _ZZ12getlocalhostvE9aliases_0 0x021AD0F4  data
 *   _ZZ12getlocalhostvE9localhost_0 0x021AD0FC  data
 *   _ZZ12getlocalhostvE5ips_2_1   0x021AD10C  data
 *   _ZZ12getlocalhostvE8ipPtrs_1_2 0x021AD120  data
 */

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

extern unsigned long func_0215EF48(void);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern char gGsLocalhostName[];

struct SOCHostEnt *getlocalhost(void)
{
    static char *aliases_0[2];
    static struct SOCHostEnt localhost;
    static unsigned int ips_2[5];
    static unsigned char *ipPtrs_1[6];

    localhost.name = gGsLocalhostName;
    localhost.aliases = aliases_0;
    localhost.addrType = 2;
    localhost.length = 0;
    localhost.addrList = ipPtrs_1;
    ips_2[0] = 0;
    SOC_U32to4U8(func_0215EF48(), (unsigned char *)ips_2);
    if (ips_2[0] == 0)
        return 0;
    ipPtrs_1[0] = (unsigned char *)ips_2;
    localhost.length = 4;
    ipPtrs_1[1] = 0;
    return &localhost;
}
