/*
 * function: GIMMICK46_SetExteriorHidden
 * address:  0x021F3FA8
 * packet:   pkt_ov046_021F3FA8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   GIMMICK46_SetMmdlVanish  0x021F4064  thumb  ov046
 */

typedef unsigned int u32;
extern void func_021BE4B4(char *ctx, int b, int c, u32 d);
extern void GIMMICK46_SetMmdlVanish(u32, int, u32);

void GIMMICK46_SetExteriorHidden(char *a, u32 b, u32 c)
{
    func_021BE4B4(a, 0, 15, c);
    func_021BE4B4(a, 0, 10, c);
    func_021BE4B4(a, 0, 11, c);
    func_021BE4B4(a, 0, 12, c);
    func_021BE4B4(a, 0, 13, c);
    func_021BE4B4(a, 0, 14, c);
    GIMMICK46_SetMmdlVanish(b, 4, c);
    GIMMICK46_SetMmdlVanish(b, 5, c);
    GIMMICK46_SetMmdlVanish(b, 9, c);
    GIMMICK46_SetMmdlVanish(b, 6, c);
}
