/*
 * function: func_021F4000
 * address:  0x021F4000
 * packet:   pkt_ov041_021F4000
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Extent after the 0x80-byte function and pool is rodata, not a follower.
 * symbols:
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 */
#include "../unit_021F36C0_types.h"

/* One step of the camera bounce: raise the camera eye a half unit, then lower it, twice. */
void func_021F4000(Gimmick41Bounce *bounce, struct FieldCamera *camera)
{
    int step;
    VecFx32 eye;

    if (bounce->active != 0) {
        bounce->tick++;
        if (bounce->wait == 0) {
            if (bounce->phase % 2 == 0) {
                step = 0x8000;
            } else {
                step = -0x8000;
                bounce->downSteps++;
            }
            bounce->phase = (bounce->phase + 1) % 2;
            func_0218ECE4(camera, &eye);
            eye.y += step;
            func_0218ECF4(camera, &eye);
            bounce->wait = 1;
        } else {
            bounce->wait--;
        }
        if (bounce->downSteps >= 2) {
            bounce->active = 0;
            bounce->finished = 1;
        }
    }
}
