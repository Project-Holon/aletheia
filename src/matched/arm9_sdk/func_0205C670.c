/*
 * function: CheckWirelessPowerON
 * address:  0x0205C670
 * packet:   pkt_0205C670
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CheckWirelessPowerON (dwc_ac.o)
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

typedef int BOOL;
extern BOOL OS_IsRunOnTwl(void);
extern BOOL OS_IsAvailableWireless(void);
extern BOOL OS_IsForceDisableWireless(void);

BOOL CheckWirelessPowerON(void)
{
    if (OS_IsRunOnTwl()) {
        if (OS_IsAvailableWireless() == 1 && OS_IsForceDisableWireless() == 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}
