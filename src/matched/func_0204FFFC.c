/*
 * function: func_0204FFFC
 * address:  0x0204FFFC
 * packet:   pkt_0204F7DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204F5A8   0x0204F5A8  arm
 *   func_0204ED24   0x0204ED24  arm
 *   func_02033C9C   0x02033C9C  arm
 *   func_020307B0   0x020307B0  arm
 *
 * The destructor of the object whose table the pkt_0204F150 accessors work
 * on: walk the 0x28-byte entries at +0x18 (the count is the halfword at
 * +0x1c) and release every one that is not the 0xffff sentinel, then free the
 * six pointers at +0x4, +0xc, +0x14, +0x18, +0x20 and the object itself,
 * alternating between the two allocators.
 *
 * The loop bound is the field, not a local: the halfword at +0x1c is
 * re-loaded for the back-edge test (the release call in the body could change
 * it), so the source spells the field in the condition.  0xffff cannot be an
 * ARM immediate, hence the pool word it is compared against.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204F5A8(u32 v);
extern void func_0204ED24(u32 v);
extern void func_02033C9C(u32 v);
extern void func_020307B0(u32 v);

void func_0204FFFC(u8 *a0)
{
    int i;

    for (i = 0; i < *(u16 *)(a0 + 0x1c); i++) {
        u32 v = *(u32 *)(*(u32 *)(a0 + 0x18) + i * 0x28);

        if (v != 0xffff) {
            func_0204F5A8(*(u32 *)(a0 + 4));
        }
    }
    func_02033C9C(*(u32 *)(a0 + 0x20));
    func_020307B0(*(u32 *)(a0 + 0x18));
    func_02033C9C(*(u32 *)(a0 + 0x14));
    func_020307B0(*(u32 *)(a0 + 0xc));
    func_0204ED24(*(u32 *)(a0 + 4));
    func_020307B0((u32)a0);
}
