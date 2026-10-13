/*
 * function: func_02174E88
 * address:  0x02174E88
 * packet:   pkt_02174E88
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears byte 0xDF of the block at ctx+0x355C, when the block exists.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;

struct Obj19292 {
    unsigned char pad_0[13660];
    void *f355C;
};

void func_02174E88(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19292 *)ctx)->f355C;
    if (p) p[0xdf] = 0;
}
