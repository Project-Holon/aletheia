/*
 * unit:     no
 * function: NNS_FndCreateExpHeapEx
 * address:  0x02060C5C
 * packet:   pkt_02060C5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndCreateExpHeap  0x02060814  arm
 *
 * The expanded heap's create front door: word-align the arena the caller
 * handed over (start rounded up, end rounded down), reject it if the rounding
 * inverted the range or left less than 0x4c bytes -- the 0x38-byte heap
 * handle plus one 0x10-byte block header plus a word -- and otherwise hand
 * the aligned pair to NNSi_FndCreateExpHeap, which lays the handle out in place.
 *
 * Two shapes are load-bearing.  The end address is `size + (u32)start`, not
 * `start + size`: the image's `add r1, r1, r0` accumulates into the size
 * register, which is the commutative-operand-order tell.  And the two
 * rejections are ONE `||`, not two `if`s: the image's `bhi` jumps to the same
 * `mov r0, #0` / `pop` the length test falls into, which a chain of separate
 * `if`s cannot reach -- mwcc if-converts each one into its own
 * `movhi`/`pophi` pair instead and four instructions differ.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_FndCreateExpHeapEx.c \
 *       --func NNS_FndCreateExpHeapEx --addr 0x02060C5C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ExpHeap;
extern void *NNSi_FndCreateExpHeap(struct ExpHeap *heap, void *lo, u32 attr);

void *NNS_FndCreateExpHeapEx(void *start, u32 size, u32 attr)
{
    void *end = (void *)((size + (u32)start) & ~3);
    void *lo  = (void *)(((u32)start + 3) & ~3);

    if (lo > end || (u32)((u8 *)end - (u8 *)lo) < 0x4c) {
        return 0;
    }
    return NNSi_FndCreateExpHeap(lo, end, attr);
}
