/*
 * function: getlocalhost
 * address:  0x0217EFB8
 * packet:   pkt_ov009_0217EFB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      getlocalhost (libdwcgscommon.TWL.HYB.a gsplatformsocket)
 *
 * callee of enum_local_ips (0x0219B6CC).  Near miss, and deferred.
 * Same 120 vs 128-byte body shape; the original bases every function-local
 * static off the address of aliases_0 (0x021AD0F4) with constant offsets
 * (localhost +8, ips_2 +0x18, ipPtrs_1 +0x2C), the merged-static-block
 * base that vendor stamp 4.0.0.1025 produced.  dsi/1.1p1 instead
 * materialises a separate base for each static and emits a different
 * store schedule (stmne for ipPtrs_1[0..1], localhost as the field-store
 * base), so the 5 data relocations and the s16 addrType/length stores do
 * not line up.  Not a source-shape fix: the static-block base choice is
 * the variance.  blocker: codegen, function-static block base selection.
 *
 * symbols:
 *   SOCL_GetHostID                   0x0215EF48 arm
 *   SOC_U32to4U8                     0x0215FBAC arm
 *   g_021A37BC                       0x021A37BC data
 *   _ZZ12getlocalhostvE7aliases_0    0x021AD0F4 data
 *   _ZZ12getlocalhostvE9localhost    0x021AD0FC data
 *   _ZZ12getlocalhostvE3ips_2        0x021AD10C data
 *   _ZZ12getlocalhostvE6ipPtrs_1     0x021AD120 data
 */

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

extern unsigned long SOCL_GetHostID(void);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern char g_021A37BC[];

static char *aliases_0[2];
static struct SOCHostEnt localhost;
static unsigned int ips_2[5];
static unsigned char *ipPtrs_1[6];

struct SOCHostEnt *getlocalhost(void)
{
    localhost.name = g_021A37BC;
    localhost.aliases = aliases_0;
    localhost.addrType = 2;
    localhost.length = 0;
    localhost.addrList = ipPtrs_1;
    ips_2[0] = 0;
    SOC_U32to4U8(SOCL_GetHostID(), (unsigned char *)ips_2);
    if (ips_2[0] == 0)
        return 0;
    ipPtrs_1[0] = (unsigned char *)ips_2;
    ipPtrs_1[1] = 0;
    localhost.length = 4;
    return &localhost;
}
