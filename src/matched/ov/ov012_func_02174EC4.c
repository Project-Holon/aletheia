/*
 * function: COLOSSEUM_RecvAllReady
 * address:  0x02174EC4
 * packet:   pkt_02174EC4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets byte 0xCB of the block at ctx+0x355C to 1, when the block exists.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;

struct Obj19294 {
    unsigned char pad_0[13660];
    void *f355C;
};

void COLOSSEUM_RecvAllReady(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19294 *)ctx)->f355C;
    if (p) p[0xcb] = 1;
}
