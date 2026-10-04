/*
 * function: func_021E0CE8
 * address:  0x021E0CE8
 * packet:   pkt_021E0CE8
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);

void func_021E0CE8(char *p, int index, int a2)
{
    func_0204B3DC((struct Obj *)*(int *)(p + index * 0x1c + 0x194), (unsigned int)a2);
}
