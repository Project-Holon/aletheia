/*
 * function: func_021BB9E4
 * address:  0x021BB9E4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears +0x10/+0x14 then runs the 0x84/0x88/0x8c/0x90 handles through the five
 * resource teardown entry points.
 *
 * symbols:
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Actor;
struct Obj;
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021BB9E4(void *a0, char *a1)
{
    *(u32 *)(a1 + 0x10) = 0;
    *(u32 *)(a1 + 0x14) = 0;
    func_0204B9A0(*(void **)(a1 + 0x84));
    func_0204B9A0(*(void **)(a1 + 0x88));
    func_0204B9A0(*(void **)(a1 + 0x8c));
    func_0204B8C4(*(void **)(a1 + 0x84), 0);
    func_0204B8C4(*(void **)(a1 + 0x88), 0);
    func_0204B92C(*(void **)(a1 + 0x84), 0);
    func_0204B92C(*(void **)(a1 + 0x88), 0);
    func_0204B3DC(*(void **)(a1 + 0x84), 0);
    func_0204B3DC(*(void **)(a1 + 0x88), 0);
    func_0204B3DC(*(void **)(a1 + 0x8c), 0);
    func_0204B3DC(*(void **)(a1 + 0x90), 0);
}
