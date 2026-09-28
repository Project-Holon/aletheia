/*
 * function: NWMi_ForceUnloadDeviceCallback
 * address:  0x021C44D8
 * packet:   pkt_ov016_021C44D8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NWMi_ForceUnloadDeviceCallback (nwm_unloaddev.o)
 *
 * symbols:
 *   isUnloaded  0x021de5c4  data
 */

extern unsigned char isUnloaded;

static void NWMi_ForceUnloadDeviceCallback(void)
{
    isUnloaded = 1;
}
