/*
 * function: DWCi_CMNlButton
 * address:  0x021BD264
 * packet:   pkt_ov016_021BD264
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_GetParam_                   0x021C0E64  arm
 *   DWCi_BTNlInit                    0x021BC9E4  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(common.o), symbol DWCi_CMNlButton (name and prototype
 * from the vendor object DWARF). Callee of the procInit1 chains. The object is stamped
 * Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so 1.1p1.
 */

extern void DWCi_GetParam_(void **param0, void **param1);
extern void DWCi_BTNlInit(int kind);

void DWCi_CMNlButton(int kind)
{
    int prm;

    DWCi_GetParam_(0, (void **)&prm);
    if (prm == 1)
        DWCi_BTNlInit(kind);
}
