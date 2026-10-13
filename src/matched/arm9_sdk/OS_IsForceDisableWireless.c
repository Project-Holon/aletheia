/*
 * function: OS_IsForceDisableWireless
 * address:  0x02087E84
 * packet:   pkt_02087E84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   OS_IsForceDisableWireless_ltdmain 0x027312F8 arm twl
 */

typedef int BOOL;

extern BOOL OS_IsRunOnTwl(void);
extern BOOL OS_IsForceDisableWireless_ltdmain(void);

BOOL OS_IsForceDisableWireless(void)
{
    if (!OS_IsRunOnTwl()) {
        return 0;
    }
    return OS_IsForceDisableWireless_ltdmain();
}
