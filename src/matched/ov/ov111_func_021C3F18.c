/*
 * function: VIEWER_MAIN_PlaySe
 * address:  0x021C3F18
 * packet:   pkt_ov111_021C3F18
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x32F6];
    u8 b32F6;
    u8 pad32F7[2];
    u8 cooldown;
} Work;

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void VIEWER_MAIN_PlaySe(Work *p, int speed)
{
    if (p->cooldown != 0) {
        p->cooldown--;
        return;
    }
    if (speed > 5) {
        p->cooldown = 5;
        if (p->b32F6 == 0) {
            GFL_USE_PlaySeDefaultVolume(0x65C);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x7CF);
        }
    }
}
