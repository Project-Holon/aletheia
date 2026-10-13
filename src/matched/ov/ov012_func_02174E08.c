/*
 * function: COLOSSEUM_RecvReady
 * address:  0x02174E08
 * packet:   pkt_02174E08
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets byte 0xD4 + index of the block at ctx+0x355C to 1, when the block exists.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;

struct Obj19291 {
    unsigned char pad_0[13660];
    void *f355C;
};

void COLOSSEUM_RecvReady(int index,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19291 *)ctx)->f355C;
    if (p) (p+index)[0xd4] = 1;
}
