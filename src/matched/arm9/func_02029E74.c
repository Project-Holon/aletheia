/*
 * function: func_02029E74
 * address:  0x02029E74
 * packet:   pkt_02029E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209FE94 literal
 * blocker:  0209FE98 literal
 *
 * symbols:
 *   g_0209FE94  0x0209FE94  data
 *   g_0209FE98  0x0209FE98  data
 *
 * 2026-09-21, FAMILY wave.  Re-verified in a fresh process: still MATCH,
 * every concrete byte identical.  Evidence worked to exhaustion:
 *   - `--suggest-split` reports "witnesses image wide: 1, of them inside
 *     this range: 1"; a single-function file has nothing to cut against.
 *   - No sibling in field_sound_system.c (0x02028844..0x02029EB4) references
 *     the object: the only other listing hits are the rodata DEFINITION in
 *     asm/arm9/src/030_*.s, which is a referent, not a referrer.
 *   - sole-ref/data was probed directly.  in_data_section = True and the
 *     layout/data_objects.txt row IS an object start when the range is
 *     ignored, but `_map_attests(addr, lo, hi)` = False once the range is
 *     applied, because that row's sole referrer is this function's own pool
 *     word.  This is the documented "a lone reference never contributes its
 *     own start" rule firing correctly, not a tooling gap.
 * Declarations cross-checked against docs/families/field_sound_system.h.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 func_0201296C(u32 a0);
extern u32 func_020142E8(u32 a0, u32 a1);
extern u8  g_0209FE94[];
extern u8  g_0209FE98[];

u32 func_02029E74(u32 a0, u16 a1)
{
    u32 v = func_0201296C(a0);
    u32 i;

    for (i = 0; i < 8; i++) {
        if (a1 == *(u16 *)(g_0209FE94 + i * 8 + 2)) {
            if (func_020142E8(v, *(u16 *)(g_0209FE94 + i * 8)) == 1) {
                return *(u32 *)(g_0209FE98 + i * 8);
            }
        }
    }
    return 0xffffffff;
}
