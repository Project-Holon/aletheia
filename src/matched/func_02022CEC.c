/*
 * function: func_02022CEC
 * address:  0x02022CEC
 * packet:   pkt_02022DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *
 * Allocate the working buffer for one of the three background planes and
 * stamp its descriptor word: the two small planes share the 0x604-byte
 * buffer (tag 0xa9b, mode word 1, the plane's row limit written at +0x600)
 * while the third takes the 0xc08-byte buffer (tag 0xaa3, mode word 2) and
 * zeroes +0x600 at a 0x604 stride.  a1 outside 0..2 does nothing.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022CEC.c \
 *       --func func_02022CEC --addr 0x02022CEC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3)
{
    int i;
    u8 *p;

    switch (a1) {
    case 0:
    case 1:
        p = func_02030734((u16)a3, 0x604, 0, 0x020A7450, 0xA9B);
        a0[1] = 1;
        a0[0] = (u32)p;
        a0[2] = a2;
        *(u32 *)(p + 0x600) = a1;
        break;
    case 2:
        p = func_02030734((u16)a3, 0xC08, 0, 0x020A7450, 0xAA3);
        a0[0] = (u32)p;
        a0[1] = 2;
        a0[2] = a2;
        for (i = 0; i < 2; i++) {
            *(u32 *)(a0[0] + 0x600 + i * 0x604) = i;
        }
        break;
    }
}
