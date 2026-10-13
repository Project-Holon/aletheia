/*
 * function: PMSIV_WORDWIN_GetThumbRow
 * address: 0x021BFE60
 * packet: pkt_ov110_021BFE60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit int cast of the int loop index at the unsigned result
 *   assignment preserves values and selects r4 for the index, r5 for lo.
 * symbols:
 *   PMSIV_WORDWIN_GetThumb 0x021BFD94 thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef struct { s16 x, y; } Vec2;
typedef unsigned int   u32;
struct Vec2;
extern u32 PMSIV_WORDWIN_GetThumb(u8 *p, struct Vec2 *out);
unsigned PMSIV_WORDWIN_GetThumbRow(u8 *p, unsigned n)
{
    int i;
    unsigned result;
    Vec2 pos;
    s16 y;
    PMSIV_WORDWIN_GetThumb(p, (struct Vec2 *)(&pos));
    if (n == 0) goto zero;
    else {
        y = pos.y;
        do {
            if (y == 18) { result = 0; goto end; }
            else if (y == 149) result = n;
            else {
                for (i = 0; i <= n; i = (s16)(i + 1)) {
                    s16 lo, hi;
                    lo = 132 * (unsigned)i / (n + 1) + 18;
                    hi = 132 * (unsigned)(i + 1) / (n + 1) + 17;
                    if (lo > hi) hi = lo;
                    if (lo <= y && y <= hi) { result = (int)i; break; }
                }
            }
            goto end;
        } while (0);
        goto zero;
    }
    goto end;
zero: result = 0;
end:
    return result;
}
