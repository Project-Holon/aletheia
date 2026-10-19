/*
 * file:     app_env.c
 * unit:     yes
 * function: APP_ENV_IsRunOnTwl, APP_ENV_HasParentalControlBits, APP_ENV_IsWirelessAvailable, APP_ENV_IsEulaAgreed, APP_ENV_GetOwnerColorAndBirthMonth
 * address:  0x0202EB0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetParentalControlInfoPtr  0x02087E60  arm
 *   OS_IsAvailableWireless  0x02087DC4  arm
 *   OS_IsAgreeEULA  0x02087DE0  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 */
#include "comm_player_support_shared_types.h"

/* Hardware capability word (DSi/wireless flags) behind OS_GetParentalControlInfoPtr. */
struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

/* Owner info record behind OS_GetOwnerInfo: only bytes 2 and 3 are read. */
struct OwnerInfo {
    u8 reserved00;
    u8 reserved01;
    u8 favoriteColor;
    u8 birthMonth;
    u8 rest[0x50];
};

extern s32 OS_IsRunOnTwl(void);

extern struct DeviceInfo *OS_GetParentalControlInfoPtr(void);

extern s32 OS_IsAvailableWireless(void);

extern int OS_IsAgreeEULA(void);

extern void OS_GetOwnerInfo(struct OwnerInfo *info);

u32 APP_ENV_IsRunOnTwl(void);

int APP_ENV_HasParentalControlBits(void);

void APP_ENV_IsWirelessAvailable(void);

u32 APP_ENV_IsEulaAgreed(void);

void APP_ENV_GetOwnerColorAndBirthMonth(u8 *outFavoriteColor, u8 *outBirthMonth);

/*
 * A pool-word-and-bx tail call into an ARM SDK entry point
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), eight bytes with no
 * prologue. Its result is compared against 1 by APP_ENV_IsEulaAgreed, which is the
 * only caller.
 */
u32 APP_ENV_IsRunOnTwl(void)
{
    return OS_IsRunOnTwl();
}

/* Nonzero when running on a DSi with both capability bits (0 and 5) set. */
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

/* Bare tail call into an ARM SDK leaf. */
void APP_ENV_IsWirelessAvailable(void)
{
    OS_IsAvailableWireless();
}

/*
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 */
u32 APP_ENV_IsEulaAgreed(void)
{
    if (APP_ENV_IsRunOnTwl() == 1) {
        return OS_IsAgreeEULA();
    }
    return 1;
}

/*
 * Fills an 0x54-byte structure on the stack from an ARM SDK getter and
 * copies two of its bytes out through the two pointer parameters. The
 * whole 0x54 bytes are reserved even though only offsets 2 and 3 are
 * read, so the stack object is the SDK's structure and not a pair of
 * bytes; `add r0, sp, #0` is emitted twice, once for the call and once
 * as the base of the two loads, which is what a named local rather than
 * a re-taken address looks like here.
 */
void APP_ENV_GetOwnerColorAndBirthMonth(u8 *outFavoriteColor, u8 *outBirthMonth)
{
    struct OwnerInfo info;

    OS_GetOwnerInfo(&info);
    *outFavoriteColor = info.favoriteColor;
    *outBirthMonth = info.birthMonth;
}
