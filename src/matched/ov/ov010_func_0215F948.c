/*
 * function: EVENT_GAMECLEAR_InitStepSequence
 * address:  0x0215F948
 * packet:   pkt_ov010_0215F948
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

void EVENT_GAMECLEAR_InitStepSequence(u8 *p)
{
    u32 *t = (u32 *)p;
    if (t[2] == 0 || t[2] != 1) {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 3;
        t[0x44 / 4] = 4;
        t[0x48 / 4] = 7;
        t[0x4c / 4] = 8;
        t[0x50 / 4] = 12;
        t[0x54 / 4] = 9;
        t[0x58 / 4] = 12;
        t[0x5c / 4] = 10;
        t[0x60 / 4] = 11;
        t[0x64 / 4] = 12;
        t[0x68 / 4] = 13;
        t[0x6c / 4] = 14;
    } else {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 1;
        t[0x44 / 4] = 3;
        t[0x48 / 4] = 4;
        t[0x4c / 4] = 5;
        t[0x50 / 4] = 6;
        t[0x54 / 4] = 10;
        t[0x58 / 4] = 11;
        t[0x5c / 4] = 7;
        t[0x60 / 4] = 8;
        t[0x64 / 4] = 13;
        t[0x68 / 4] = 14;
    }
    t[0x34 / 4] = t[0x38 / 4];
}
