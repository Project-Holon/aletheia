/*
 * unit:     yes
 * function: func_02043900
 * address:  0x02043900
 * packet:   pkt_0204384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02043900_File  0x020A7E68  data
 *   func_02030734       0x02030734  arm
 *   MIi_CpuCopy32       0x02082A90  arm
 *
 * bmp.c's bitmap constructor, 0x02043900-0x02043994 including its two pool
 * words.  The file-name pool word is 0x020A7E68, which spells "bmp.c", and
 * the line number is 321.  The accessor that follows at 0x02043994 is kept
 * in its own file so its manifest entry survives
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * The header the constructor reads is a resource record: two halfword cell
 * counts at +0 and +2 (stored back multiplied by eight, so the bitmap's +4
 * and +6 are pixel extents and the record's are tiles), a format word at +4,
 * a byte size at +0x10 and the source pointer at +0x14.  Format 3 means a
 * +8 of 0x20 and format 4 means 0x40; anything else leaves +8 untouched.
 *
 * The literal zero is written once into r6 and spends its life as three
 * different things: the allocator's alignment argument, the halfword stored
 * at +0xA, and nothing else
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The format test is a two-case `switch`, not an `if`/`else if` chain, and
 * the difference is four bytes and the whole tail's schedule: the chain
 * predicates the first arm in place (`moveq`/`strheq` then `beq` over the
 * rest) and needs no joining `b`, while the switch puts the first case out
 * of line at 0x0204396C and reaches the join with the `b` at 0x02043968.
 * With the chain the two stores after the allocation also come out in the
 * other order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043900.c \
 *       --addr 0x02043900 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   unk08;
    u16   unk0A;
};

struct BmpInfo {
    u16   cellsX;
    u16   cellsY;
    u32   format;
    u8    pad08[8];
    u32   size;
    void *src;
};

extern const char func_02043900_File[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

void func_02043900(struct Bmp *b, struct BmpInfo *info, u32 heap)
{
    b->width = info->cellsY * 8;
    b->height = info->cellsX * 8;
    b->pixels = func_02030734(heap, info->size, 0, func_02043900_File, 321);
    b->unk0A = 0;
    switch (info->format) {
    case 3:
        b->unk08 = 0x20;
        break;
    case 4:
        b->unk08 = 0x40;
        break;
    }
    MIi_CpuCopy32(info->src, b->pixels, info->size);
}
