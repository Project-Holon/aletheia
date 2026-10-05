/*
 * function: func_02026680
 * address:  0x02026680
 * packet:   pkt_02026680
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears bit 0 of six 12-byte entries at +0x3F and the bytes at +0x85 and +0x84.
 * Caller: ov011 0x021731C8.
 */

typedef unsigned char u8;
typedef struct { u8 b0 : 1; u8 rest : 7; u8 pad[0xb]; } E;

void func_02026680(u8 *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        ((E *)(p + 0x3f))[i].b0 = 0;
    }
    p[0x85] = 0;
    p[0x84] = 0;
}
