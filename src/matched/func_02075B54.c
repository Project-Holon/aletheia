/*
 * function: func_02075B54
 * address:  0x02075B54
 * packet:   pkt_02075B54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Signed compare against zero for the negative index (`movlt`/`bxlt`) but an
 *  * unsigned `>=` for the bound (`movhs`/`bxhs`), which is what an `int` index
 *  * compared against a `u32` count gives; the -1 element test is the
 *  * R_ARM_ABS32-free third guard the tail ends on. No relocations at all.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Entry { u32 f0; u32 f4; u32 f8; };   /* 0xC bytes each */
struct Table { u8 pad00[0x1c]; u32 count; struct Entry arr[]; };

struct Entry *func_02075B54(struct Table *t, int idx)
{
    struct Entry *e;

    if (idx < 0) return 0;
    if (idx >= t->count) return 0;
    e = &t->arr[idx];
    if (e->f0 == -1) return 0;
    return e;
}
