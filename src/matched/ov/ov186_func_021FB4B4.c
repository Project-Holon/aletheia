/*
 * function: BR_BTN_HitTestWithSound
 * address:  0x021FB4B4
 * packet:   pkt_021FB4B4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_BTN_TestHitBox  0x021FB4CC  thumb  ov186
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

extern int BR_BTN_TestHitBox(unsigned int *p, int a1, int a2);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y)
{
    int r = BR_BTN_TestHitBox(obj, x, y);

    if (r != 0)
        GFL_USE_PlaySeDefaultVolume(0x703);
    return r;
}
