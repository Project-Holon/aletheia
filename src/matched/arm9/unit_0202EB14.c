/*
 * unit:     yes
 * function: APP_ENV_HasParentalControlBits
 * address:  0x0202EB14
 * packet:   pkt_0202EB14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   OS_GetParentalControlInfoPtr  0x02087E60  arm
 */

typedef unsigned int u32;

struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

extern u32 APP_ENV_IsRunOnTwl(void);
extern struct DeviceInfo *OS_GetParentalControlInfoPtr(void);

int APP_ENV_HasParentalControlBits(void)
{
    if (APP_ENV_IsRunOnTwl()) {
        if (OS_GetParentalControlInfoPtr()->bit0 && OS_GetParentalControlInfoPtr()->bit5) {
            return 1;
        }
        return 0;
    }
    return 0;
}
