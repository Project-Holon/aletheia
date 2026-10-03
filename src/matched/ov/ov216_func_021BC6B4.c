/*
 * function: func_021BC6B4
 * address:  0x021BC6B4
 * packet:   pkt_021BC6B4
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 */

struct S021BC6B4
{
    char pad[0x264];
    void *slots[2];
};

typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);

void func_021BC6B4(struct S021BC6B4 *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        func_0204B3DC(p->slots[i], 0);
        func_0204B3B4(p->slots[i]);
    }
}
