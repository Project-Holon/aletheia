/*
 * function: WCM_GetAllowedChannel
 * address:  0x0216576C
 * packet:   pkt_ov009_0216576C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_GetAllowedChannel (system.o)
 *
 * symbols:
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WCMi_WmifGetAllowedChannel       0x02166de4 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WCMi_NwmifGetAllowedChannel      0x02731f00 arm
 */

extern char *WCMi_GetSystemWork(void);
extern unsigned short WCMi_WmifGetAllowedChannel(void);
extern int OS_IsRunOnTwl(void);
extern unsigned short WCMi_NwmifGetAllowedChannel(void);

unsigned short WCM_GetAllowedChannel(void)
{
    char *w = WCMi_GetSystemWork();

    if (*(unsigned char *)(w + 0x1000 + 0x2de) >= 3 &&
        *(unsigned char *)(w + 0x1000 + 0x2de) <= 10) {
        switch (*(unsigned char *)(w + 0x1000 + 0x2df)) {
        case 1:
            return WCMi_WmifGetAllowedChannel();
        case 2:
            if (OS_IsRunOnTwl())
                return WCMi_NwmifGetAllowedChannel();
            break;
        }
    }
    return 0;
}
