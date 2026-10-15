/*
 * function: NWMi_RegisterSleepCallback
 * address:  0x02702A40
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NwmSleepCallback  0x02702A8C  arm twl
 *   data_027341A4  0x027341A4  data twl a2
 *   data_027341B8  0x027341B8  data twl a2
 *   PMi_InsertPreSleepCallbackEx  0x0208C848  arm twl a2
 */

typedef unsigned int u32;

extern void NwmSleepCallback(void);
extern u32 data_027341A4[];
extern u32 data_027341B8[];
extern void PMi_InsertPreSleepCallbackEx(u32 *, u32);

void NWMi_RegisterSleepCallback(void) {
    data_027341A4[5] = (u32)NwmSleepCallback;
    data_027341A4[6] = 0;
    PMi_InsertPreSleepCallbackEx(data_027341B8, 0xFFFF);
}
