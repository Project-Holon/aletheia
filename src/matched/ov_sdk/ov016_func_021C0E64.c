/*
 * function: DWCi_GetParam_
 * address:  0x021C0E64
 * packet:   pkt_ov016_021C0E64
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Language                         0x021DE56C  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(main.o), symbol DWCi_GetParam_ (name and prototype from
 * the vendor object DWARF). Callee of DWCi_CMNlButton (common.o). The object is stamped
 * Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so 1.1p1.
 */

struct LANG {
    char pad[0x10];
    void *f10;
    void *f14;
};

extern struct LANG Language;

void DWCi_GetParam_(void **param0, void **param1)
{
    if (param0)
        *param0 = Language.f10;
    if (param1)
        *param1 = Language.f14;
}
