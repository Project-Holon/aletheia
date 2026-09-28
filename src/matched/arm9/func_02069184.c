/*
 * function: func_02069184
 * address:  0x02069184
 * packet:   pkt_02069078
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Number of OBJs NitroSystem's 1D OBJ arrangement (func_020691E0) spends on
 * an areaWidth x areaHeight character area: 8x8-char OBJs over the aligned
 * part, then per 8-char strip one OBJ for a 4-char remainder and two for
 * each of the 2- and 1-char remainders (a 1x8 or 2x8 OBJ does not exist),
 * and the remainder corner.  Exported; nothing in the image calls it.
 *
 * Levers, from the permuter (docs/notes/permuter.md): the bit pair is
 * `((v & 2) >> 1) + (v & 1)` (bit 1 first), the declarations run
 * X8, Y8, X2, num, X4, Y4, Y2, and the corner product is bound to its own
 * local before the return.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image seeds the product chain with a materialised zero, `mov r2, #0` at
 * 0x02069190 then `mla lr, r3, r5, r2` at 0x02069194; dsi/1.1p1 folds the
 * same C to a bare `mul lr, r3, r5` (every spelling of the zero the earlier
 * notes list does the same), 25 concrete bytes out.  0 under the pin.
 */
typedef unsigned int u32;

u32 func_02069184(u32 areaWidth, u32 areaHeight)
{
    u32 numX8 = areaWidth >> 3;
    u32 numY8 = areaHeight >> 3;
    u32 numX2 = ((areaWidth & 2) >> 1) + (areaWidth & 1);
    u32 num = 0;
    u32 numX4 = (areaWidth & 4) >> 2;
    u32 numY4 = (areaHeight & 4) >> 2;
    u32 numY2 = ((areaHeight & 2) >> 1) + (areaHeight & 1);
    u32 corner;

    num += numX8 * numY8;
    num += numY8 * (numX2 * 2 + numX4);
    num += numX8 * (numY2 * 2 + numY4);
    corner = (numX2 + numX4) * (numY2 + numY4);
    return num + corner;
}
