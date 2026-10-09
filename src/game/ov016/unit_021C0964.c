/*
 * file:     unit_021C0964.c
 * function: aossFree
 * address:  0x021C0964
 * packet:   pkt_ov016_021C0964
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      aossFree (libdwcutil.TWL.HYB.a libaoss.o, static void aossFree(void *ptr))
 *
 * symbols:
 *   DWCi_HEAPlFree2  0x021D647C  arm
 *
 * Free hook DWCi_AOSSlInit (func_021C07A8) passes to AOSSi_InitLocal next to
 * aossAlloc (0x021C0954).
 */

extern void DWCi_HEAPlFree2(void *mem);

void aossFree(void *ptr)
{
    DWCi_HEAPlFree2(ptr);
}
