/*
 * function: sub_020422D4
 * address:  0x020422D4
 * packet:   pkt_02041F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The two register values a layer's window mode implies: six modes, each
 * writing one byte into each of the two output pointers, and nothing at all
 * for a mode above five (`addls` over a bare `bx lr`).  Modes 0, 1, 4 and 5
 * write the same constant twice, so the compiler materialises it once and
 * reuses r0 for both stores; modes 2 and 3 write two different ones in the
 * order they are given.  The arms are byte stores, so the values are `u8`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020422D4.c \
 *       --func sub_020422D4 --addr 0x020422D4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void sub_020422D4(u32 mode, u8 *a, u8 *b)
{
    switch (mode) {
    case 0:
        *a = 0x10;
        *b = 0x10;
        break;
    case 1:
        *a = 0x20;
        *b = 0x20;
        break;
    case 2:
        *a = 0x20;
        *b = 0x40;
        break;
    case 3:
        *a = 0x40;
        *b = 0x20;
        break;
    case 4:
        *a = 0x40;
        *b = 0x40;
        break;
    case 5:
        *a = 0x80;
        *b = 0x80;
        break;
    }
}
