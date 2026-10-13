/*
 * function: func_02164C5C
 * address:  0x02164C5C
 * packet:   pkt_02164C5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the word at offset 4.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;

struct Obj18984 {
    unsigned char pad_0[4];
    unsigned int f4;
};

void func_02164C5C(u8 *p) { ((struct Obj18984 *)p)->f4=0; }
