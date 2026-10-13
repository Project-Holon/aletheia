/*
 * function: DWCi_CMNlStep
 * address:  0x021BD214
 * packet:   pkt_ov016_021BD214
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CMNlStep (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   DWCi_GetParam_  0x021c0e64  arm  ov016
 *   DWCi_STEPlBegin  0x021d0040  arm  ov016
 *   DWCi_STEPlChange  0x021d05bc  arm  ov016
 */

extern void DWCi_GetParam_(void **param0, void **param1);
extern void DWCi_STEPlBegin(int step);
extern void DWCi_STEPlChange(int step);

void DWCi_CMNlStep(int step)
{
    int prm;

    DWCi_GetParam_((void **)&prm, 0);
    if (prm == 1)
        DWCi_STEPlBegin(step);
    else if (prm == 2)
        DWCi_STEPlChange(step);
}
