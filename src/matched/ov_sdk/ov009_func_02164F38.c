/*
 * function: WCM_GetWorkSize
 * address:  0x02164F38
 * packet:   pkt_ov009_02164F38
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_GetWorkSize (system.o)
 *
 * symbols:
 *   WCMi_GetDefaultDeviceId         0x02165b68 arm
 *   OS_IsRunOnTwl                   0x02085d3c arm
 */

extern unsigned char WCMi_GetDefaultDeviceId(void);
extern int OS_IsRunOnTwl(void);

int WCM_GetWorkSize(long *workSize, unsigned char deviceId)
{
    if (deviceId == 0)
        deviceId = WCMi_GetDefaultDeviceId();

    switch (deviceId) {
    case 1:
        *workSize = 0x2300;
        break;
    case 2:
        if (!OS_IsRunOnTwl())
            return 0;
        *workSize = 0x4800;
        break;
    default:
        return 0;
    }
    return 1;
}
