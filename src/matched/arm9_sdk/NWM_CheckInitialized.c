/*
 * function: NWM_CheckInitialized
 * address:  0x02090ED8
 * packet:   pkt_02090ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   NWMi_CheckInitialized 0x02702698 arm twl
 */

typedef unsigned int u32;
typedef int BOOL;

extern BOOL OS_IsRunOnTwl(void);
extern u32 NWMi_CheckInitialized(void);

u32 NWM_CheckInitialized(void)
{
    if (!OS_IsRunOnTwl()) {
        return 3;
    }
    return NWMi_CheckInitialized();
}
