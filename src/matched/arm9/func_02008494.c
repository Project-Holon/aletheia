/*
 * function: MYSTATUS_Copy
 * address:  0x02008494
 * packet:   pkt_02008494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *
 * Copy of 0x20 bytes: a tail call through the pool with the length in r2.
 * Seeded in layout/function_starts.txt from the bl sites in ov010, ov011,
 * ov012, ov018, ov021 and others (w6_fix18).
 */

extern void func_02082D44(void *src, void *dst, unsigned int size);

void MYSTATUS_Copy(void *src, void *dst)
{
    func_02082D44(src, dst, 0x20);
}
