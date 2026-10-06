/*
 * function: func_02043130
 * address:  0x02043130
 * packet:   pkt_02043130
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reorder an 8x8 tile in place, using one 0x40-byte scratch tile from the
 * heap the caller names in `page` (its low 15 bits, with bit 15 set).
 *
 *  - bit 0 of `flags` mirrors every 8-byte row horizontally: the scratch
 *    tile is filled with the row's bytes taken in reverse and copied back
 *    over the original, so the tile is transformed through the scratch.
 *  - bit 1 rotates the eight rows by reversing their order, one memcpy per
 *    row straight into the scratch tile, then one memcpy back.
 * `flags` is tested with `tst`/`beq`, so 0 means "nothing to do" and the
 * early `popeq` is the whole prologue.
 *
 * Shape notes:
 *  - The heap id is a u16 local, not a cast expression: the original
 *    truncates `page` to u16 *before* the mask (`lsl #0x10` /
 *    `and r0, r1, r0, lsr #16`) and truncates again after the `orr`, which
 *    only falls out of `heap = (u16)page; heap = (heap & 0x7FFF) | 0x8000;`.
 *  - Both loop counters are u8: the increments carry the `and #0xff` that
 *    an int counter does not.
 *  - The two memcpy pairs through `tmp` are what make this a three-call
 *    shape; the helper at 0x02082D44 is the project's 8-bit copy.
 *
 * symbols:
 *   func_02043130_File 0x020A7E5C  data
 *   func_02030734      0x02030734  arm
 *   func_020307B0      0x020307B0  arm
 *   func_02082D44      0x02082D44  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043130.c \
 *       --func func_02043130 --addr 0x02043130 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_02043130_File[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082D44(void *dst, void *src, u32 n);

void func_02043130(u16 flags, u8 *buf, u32 page)
{
    u8 *tmp;
    u16 heap;
    u8 i;
    u8 j;

    if (flags == 0) {
        return;
    }

    heap = (u16)page;
    heap = (heap & 0x7FFF) | 0x8000;

    tmp = func_02030734(heap, 0x40, 0,
                        (const char *)func_02043130_File, 0xD48);

    if (flags & 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                tmp[i * 8 + j] = buf[i * 8 + (7 - j)];
            }
        }
        func_02082D44(buf, tmp, 0x40);
    }

    if (flags & 2) {
        for (i = 0; i < 8; i++) {
            func_02082D44(tmp + i * 8, buf + (7 - i) * 8, 8);
        }
        func_02082D44(buf, tmp, 0x40);
    }

    func_020307B0(tmp);
}
