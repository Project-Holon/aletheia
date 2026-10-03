/*
 * function: func_021F0ED0
 * address:  0x021F0ED0
 * packet:   pkt_021F0ED0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */

typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021F0ED0(char *p, int a)
{
    func_0204B3DC(*(void **)(p + 0x14), a);
}
