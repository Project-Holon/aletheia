/*
 * function: PALANM_BlendColors
 * address:  0x02021F64
 * packet:   pkt_02021B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A per-pixel RGB555 alpha-blend loop, same family as PALANM_CalcFadeColors and
 * PALANM_ApplyFade: each channel of src[i] is pulled toward the corresponding
 * channel of `color` by `weight`/16 and the three results repacked into
 * dst[i].  `color` is the fifth argument and arrives on the caller's stack
 * (the entry `add r0,sp,#0x20; ldrh r0,[r0]`).
 *
 * No relocations: the function calls nothing and reads no globals.
 *
 * EXACT*, not EXACT: the next function has no label, so the inferred extent
 * runs two bytes long (116 vs the 114 compiled, the difference being the
 * alignment halfword at 0x02021FD6).
 *
 * Two levers, both recorded in docs/notes/PALANM_BlendColors.c.txt:
 *   - the per-pixel channels must be read through a bitfield pointer into
 *     src[i] itself, ((struct Rgb555 *)&src[i])->r, not through a value-copy
 *     union: the copy spills the pixel to a stack slot the image never uses.
 *   - `weight` is a SIGNED int.  As u32 the products (t - s) * weight become
 *     unsigned and the three `>> 4` compile to `lsrs`; the image has `asrs`
 *     at +0x3E, +0x4A and +0x54.  That signedness was the whole residue.
 */
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rgb555 {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 pad : 1;
};

void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight,
                   struct Rgb555 color)
{
    u16 i;
    int tr = color.r;
    int tg = color.g;
    int tb = color.b;

    for (i = 0; i < count; i++) {
        int sr = ((struct Rgb555 *)&src[i])->r;
        int sg = ((struct Rgb555 *)&src[i])->g;
        int sb = ((struct Rgb555 *)&src[i])->b;
        int rb = sb + ((tb - sb) * weight >> 4);
        int rr = sr + ((tr - sr) * weight >> 4);
        int rg = sg + ((tg - sg) * weight >> 4);

        dst[i] = (u16)(rr | (rg << 5) | (rb << 10));
    }
}
