/*
 * file:     msl_wchar.c
 * unit:     yes
 * function: fwide, wcslen, wcscpy, MSL_C_LIB_ShouldRoundUp, MSL_C_LIB_IncrementDigits, MSL_C_LIB_SetPrecision
 * address:  0x02096508
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "msl_crt_shared_types.h"
#include "msl_stdio_shared_types.h"
#include "msl_wchar_shared_types.h"

extern int MSL_C_LIB_ShouldRoundUp(u8 *p, int i);

int fwide(u8 *stream, int orientation);

int wcslen(const u16 *s);

u16 *wcscpy(u16 *d, const u16 *s);

int MSL_C_LIB_ShouldRoundUp(u8 *dec, int idx);

void MSL_C_LIB_IncrementDigits(u8 *dec, int idx);

void MSL_C_LIB_SetPrecision(DB *dec, int precision);

/*
 * note:     the trailing star is the two unlabelled leaves that follow in the
 *           word run -- wcslen (0x02096578) and wcscpy
 *           (0x02096594), both matched in this window -- so the listing extent
 *           runs to 0x020965B4.  Wants seeds for both addresses in
 *           layout/function_starts.txt.
 */
int fwide(u8 *stream, int orientation)
{
    u32 f;

    if (stream == 0 || ((((struct MslStream *)stream)->mode << 22) >> 29) == 0)
        return 0;

    f = ((struct MslStream *)stream)->mode;
    switch ((f << 20) >> 30) {
    case 0:
        if (orientation > 0)
            ((struct MslStream *)stream)->mode = (f & ~0xc00u) | 0x800u;
        else if (orientation < 0)
            ((struct MslStream *)stream)->mode = (f & ~0xc00u) | 0x400u;
        break;
    case 1:
        orientation = -1;
        break;
    case 2:
        orientation = 1;
        break;
    }
    return orientation;
}

int wcslen(const u16 *s)
{
    int n = -1;
    u16 c;

    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}

/*
 * note:     the second of the two unlabelled leaves trailing fwide's
 *           word run (the first is wcslen, its own file).  It is
 *           wcslen's wide-string copy counterpart: a `do { t = p;
 *           *p = *s++; p++; } while (*t);` loop, which is what keeps the
 *           `mov ip, r3` / `ldrh r2, [ip]` re-read of the character just
 *           stored -- the store and the loop test go through two different
 *           pointer variables, so the value is not forwarded into the compare.
 */
u16 *wcscpy(u16 *d, const u16 *s)
{
    u16 *r = d;
    u16 *p = d;
    u16 *t;

    do {
        t = p;
        *p = *s++;
        p++;
    } while (*t);
    return r;
}

int MSL_C_LIB_ShouldRoundUp(u8 *dec, int idx)
{
    u8 *q = dec + 5 + idx;

    if (q[0] > 5) return 1;
    if (q[0] < 5) return -1;
    for (q++; q < dec + 5 + dec[4]; q++) {
        if (*q) return 1;
    }
    return ((dec + 5)[idx - 1] & 1) ? 1 : -1;
}

void MSL_C_LIB_IncrementDigits(u8 *dec, int idx)
{
    u8 *base = dec + 5;
    u8 *cur = base + idx - 1;

    for (;;) {
        if (*cur < 9) {
            *cur = *cur + 1;
            return;
        }
        if (cur == base) {
            *cur = 1;
            ((struct DB *)dec)->exp = ((struct DB *)dec)->exp + 1;
            return;
        }
        *cur = 0;
        cur--;
    }
}

/*
 * closed:   blocker MSL_C_LIB_ShouldRoundUp is now a manifest entry (matched class)
 *
 * Clamps the new value against the count byte at +4, records it and, when the
 * worker returns non-negative, propagates it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_SetPrecision.c \
 *       --func MSL_C_LIB_SetPrecision --addr 0x02096670 --cc 1.1p1 --arm
 */
void MSL_C_LIB_SetPrecision(DB *dec, int precision)
{
    int r;

    if (precision <= 0) {
        return;
    }
    if (precision >= dec->length) {
        return;
    }
    r = MSL_C_LIB_ShouldRoundUp((u8 *)dec, precision);
    dec->length = precision;
    if (r < 0) {
        return;
    }
    MSL_C_LIB_IncrementDigits((u8 *)dec, precision);
}
