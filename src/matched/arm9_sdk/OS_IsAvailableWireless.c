/*
 * function: OS_IsAvailableWireless
 * address:  0x02087DC4
 * packet:   pkt_02087DC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   OS_IsAvailableWireless_ltdmain 0x027312D0 arm twl
 */

typedef int BOOL;

extern BOOL OS_IsRunOnTwl(void);
extern BOOL OS_IsAvailableWireless_ltdmain(void);

BOOL OS_IsAvailableWireless(void)
{
    if (!OS_IsRunOnTwl()) {
        return 1;
    }
    return OS_IsAvailableWireless_ltdmain();
}
