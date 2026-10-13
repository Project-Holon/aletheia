/*
 * function: NWMi_DeleteSleepCallback
 * address:  0x02702A78
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027341B8  0x027341B8  data twl a2
 *   func_0208C86C  0x0208C86C  arm twl
 */

typedef unsigned int u32;

extern u32 data_027341B8[];
extern void func_0208C86C(u32 *);

void NWMi_DeleteSleepCallback(void)
{
    func_0208C86C(data_027341B8);
}
