/*
 * function: func_021F3EE4
 * address:  0x021F3EE4
 * packet:   pkt_ov041_021F3EE4
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3EE4  0x021F3EE4  thumb
 *   d_021F40F0     0x021F40F0  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 pad;
    u16 b;
} E;

extern E d_021F40F0[];

u8 func_021F3EE4(u16 a, u16 b)
{
    u8 i;

    for (i = 0; i < 10; i++) {
        if (a == d_021F40F0[i].a && b == d_021F40F0[i].b) {
            return i;
        }
    }
    return i;
}
