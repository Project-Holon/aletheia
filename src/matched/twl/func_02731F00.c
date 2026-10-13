/*
 * function: WCMi_NwmifGetAllowedChannel
 * address:  0x02731F00
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWM_GetAllowedChannel  0x02702980  arm  twl
 */

typedef unsigned int u32;

extern u32 NWM_GetAllowedChannel(void);

u32 WCMi_NwmifGetAllowedChannel(void)
{
    return (NWM_GetAllowedChannel() << 15) >> 16;
}
