/*
 * function: func_021D9E48
 * address:  0x021D9E48
 * packet:   pkt_021D9E48
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021D9E48(char *p, int i, int a)
{
    func_0204B3DC(*(void **)(p + i * 0x1c + 0x194), a);
}
