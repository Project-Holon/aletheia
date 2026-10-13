/*
 * function: EVENT_TRAINER_EYE_UpdatePairEvent
 * address:  0x021AE754
 * packet:   pkt_ov021_021AE754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_TRAINER_EYE_Run  0x021AE72C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct S;
extern int EVENT_TRAINER_EYE_Run(struct S *s);
extern u32 func_020307B0(void *p);

int EVENT_TRAINER_EYE_UpdatePairEvent(u32 a, u32 b, u32 *c)
{
    if (c[0] != 0) {
        if (EVENT_TRAINER_EYE_Run((struct S *)c[0]) == 1) {
            func_020307B0((void *)c[0]);
            c[0] = 0;
        }
    }
    if (c[1] != 0) {
        if (EVENT_TRAINER_EYE_Run((struct S *)c[1]) == 1) {
            func_020307B0((void *)c[1]);
            c[1] = 0;
        }
    }
    if (c[0] == 0 && c[1] == 0) {
        return 1;
    }
    return 0;
}
