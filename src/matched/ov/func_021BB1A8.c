/*
 * function: func_021BB1A8
 * address:  0x021BB1A8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020457B0  0x020457B0  arm
 *   unit_0201C440  0x0201C440  thumb
 *   sub_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *
 * Allocates eight objects and homes them in the block: four buffers of 0x17C,
 * 0x17C, 0x17C and 0xB4 bytes at +0xF4, +0xFC, +0xF0, +0xF8, two objects from
 * one factory at +0x1B8 and +0x1B4, one four-argument object at +0x1C0 and one
 * at +0x9B0.  The offsets are spelled per access, which is why the listing
 * re-materialises 0x17C as `movs #0x5f; lsls #2` and adds small deltas to it.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef int BOOL;

struct Tcbl;
struct U16Vec;
extern struct U16Vec *sub_020457B0(u32 capacity, u32 heapId);
extern void *unit_0201C440(int tag);
extern struct Tcbl *sub_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(int a, int b, int c, int d);

typedef struct {
    char pad[0xF0];
    void *f0F0;
    void *f0F4;
    void *f0F8;
    void *f0FC;
    char pad2[0xB4];
    void *f1B4;
    void *f1B8;
    void *f1BC;
    void *f1C0;
} S;

void func_021BB1A8(char *s)
{
    *(void **)(s + 0xF4) = sub_020457B0(0x17C, 0x21);
    *(void **)(s + 0xFC) = sub_020457B0(0x17C, 0x21);
    *(void **)(s + 0xF0) = sub_020457B0(0x17C, 0x21);
    *(void **)(s + 0xF8) = sub_020457B0(0xB4, 0x21);
    *(void **)(s + 0x1B8) = unit_0201C440(0x21);
    *(void **)(s + 0x1B4) = unit_0201C440(0x21);
    *(void **)(s + 0x1C0) = sub_0203101C(0x21, 0x21, 2, 0);
    *(void **)(s + 0x9B0) = func_02028590(0xF, 1, 0, 0x21);
}
