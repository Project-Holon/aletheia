/*
 * function: func_0201756C
 * address:  0x0201756C
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017588  0x02017588  thumb
 *
 * Forwarder: func_02017588(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000) -- random IVs, random personality.  Wave 11,
 * 2026-09-23: the u64 `id` straddles r3 and the first stack word; declaring
 * it u64 is the whole fix for the 18-byte prologue residue (push {r4,r5,r6}
 * and the late `ldr r6,[sp,#0x20]`).
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern void func_02017588(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);

void func_0201756C(void *obj, u16 species, u16 level, u64 id)
{
    func_02017588(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}
