/*
 * function: func_0200E0E8
 * address:  0x0200E0E8
 * packet:   pkt_0200E0BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209DE90  0x0209DE90  data
 *
 * Wave 17 lane untried_small. Three levers together: the range table read as
 * `struct Rec { u16 a; u16 b; }` (two pool words, tbl and tbl + 2, as in
 * func_0200E124); the slot word read as an 11-bit bitfield (the image masks
 * with `lsls #21; lsrs #21`, which `& 0x7ff` never produces); and an element
 * pointer walked beside the index in a `while` loop.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u16 a;
    u16 b;
} Rec;

typedef struct Slot {
    u32 id   : 11;
    u32 rest : 21;
} Slot;

extern const Rec g_0209DE90[];

u32 func_0200E0E8(const Slot *obj, int idx)
{
    u32 r = 0xffff;
    u32 i = g_0209DE90[idx].a;
    u32 hi = g_0209DE90[idx].b;
    const Slot *p = &obj[i];

    while (i < hi) {
        if (p->id == 0) {
            r = i;
            break;
        }
        i++;
        p++;
    }
    return r;
}
