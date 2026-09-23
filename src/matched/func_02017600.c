/*
 * function: func_02017600
 * address:  0x02017600
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201761C  0x0201761C  thumb
 *
 * Forwarder: func_0201761C(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000).  Twin of func_0201756C; wave 11, 2026-09-23, closed
 * by the u64 `id` parameter.
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern void func_0201761C(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);

void func_02017600(void *obj, u16 species, u16 level, u64 id)
{
    func_0201761C(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}
