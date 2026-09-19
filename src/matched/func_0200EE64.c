/*
 * function: func_0200EE64
 * address:  0x0200EE64
 * packet:   pkt_0200EE64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200EE50  0x0200EE50  thumb
 *   sub_0200F0CC  0x0200F0CC  thumb
 *   sub_0200EED8  0x0200EED8  thumb
 *
 * Drain loop over a producer: while the enumerator at 0x0200F0CC still hands
 * back 1, take the item at the out-slot and, unless bit 20 of its +4 word is
 * set, retire the 0x50-byte destination cursor through sub_0200EED8.  The
 * enumerator call is rotated (first test above the loop body) so this is a
 * plain `while`, not a do/while.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void sub_0200EE50(void *p);
extern int sub_0200F0CC(u32 a0, void **out, u32 *hint);
extern void sub_0200EED8(void *item, u8 *dst);

void func_0200EE64(u32 a0, u8 *a1)
{
    u32 hint = 0;
    void *item;

    sub_0200EE50(a1);

    while (sub_0200F0CC(a0, &item, &hint) == 1) {
        if ((*(u32 *)((u8 *)item + 4) & 0x100000) == 0) {
            sub_0200EED8(item, a1);
            a1 += 0x50;
        }
    }
}
