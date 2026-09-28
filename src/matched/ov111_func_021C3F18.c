/*
 * function: func_021C3F18
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
 *   func_020061E4  0x020061E4  thumb
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

extern void func_020061E4(int se);

void func_021C3F18(Work *p, int speed)
{
    if (p->cooldown != 0) {
        p->cooldown--;
        return;
    }
    if (speed > 5) {
        p->cooldown = 5;
        if (p->b32F6 == 0) {
            func_020061E4(0x65C);
        } else {
            func_020061E4(0x7CF);
        }
    }
}
