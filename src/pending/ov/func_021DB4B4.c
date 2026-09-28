/*
 * function: func_021DB4B4
 * address:  0x021DB4B4
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (parked)
 *
 * DIFF: original makes two separate calls to the ARM9 helper _s32_div_f at 0x0209C0A4 (blx, ARM) and materialises (a-2) once in r5 across both; ours emits two Thumb BLs to the same helper and recomputes (a-2) from a callee-saved copy of a. Blocking site: the div helper call ISA/attestation at 0x0209C0A4.
 *
 * Position of a slot: 0 and 1 are special, the rest on a 6-column grid.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

int func_021DB4B4(int a)
{
    int b, q, r;

    if (a == 0)
        return 0;
    if (a == 1)
        return 0x30;
    b = a - 2;
    q = b / 6;
    r = b % 6;
    return q * 0xa0 + 0x60 + r * 0x1a;
}

