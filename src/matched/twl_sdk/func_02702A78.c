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
 *   PM_DeletePreSleepCallback  0x0208C86C  arm twl
 */

typedef unsigned int u32;

extern u32 data_027341B8[];
extern void PM_DeletePreSleepCallback(u32 *);

void NWMi_DeleteSleepCallback(void)
{
    PM_DeletePreSleepCallback(data_027341B8);
}
