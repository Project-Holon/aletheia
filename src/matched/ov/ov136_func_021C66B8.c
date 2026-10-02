/*
 * function: func_021C66B8
 * address:  0x021C66B8
 * packet:   pkt_ov136_021C66B8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC        0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0204B3DC(void *, u32);
void func_021C66B8(u8 *p, int i, u32 v)
{
    func_0204B3DC(*(void **)(p + i * 4 + 0x1F0), v);
}
