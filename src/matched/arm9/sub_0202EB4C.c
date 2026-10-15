/*
 * unit:     no
 * function: APP_ENV_IsEulaAgreed
 * address:  0x0202EB4C
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_ENV_IsRunOnTwl   0x0202EB0C  thumb
 *   OS_IsAgreeEULA  0x02087DE0  arm
 *
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ENV_IsEulaAgreed.c \
 *       --func APP_ENV_IsEulaAgreed --addr 0x0202EB4C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 APP_ENV_IsRunOnTwl(void);
extern int OS_IsAgreeEULA(void);

u32 APP_ENV_IsEulaAgreed(void)
{
    if (APP_ENV_IsRunOnTwl() == 1) {
        return OS_IsAgreeEULA();
    }
    return 1;
}
