/*
 * file:     unit_0689D4F0_p03.c
 * unit:     yes
 * function: func_0689D5C8, func_0689D5F4
 * address:  0x0689D5C8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned int u32;

u8 func_0689D5C8(u8 *base, u8 key);
int func_0689D5F4(u8 *p, int i);


/*
 * Scan a table of 3-byte records: find the first record whose first byte is
 * non-zero and whose third byte equals `key`; return its index (0..5), or 6.
 * Addresses are Black-image addresses.
 */
u8 func_0689D5C8(u8 *base, u8 key)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (base[i * 3] != 0 && base[i * 3 + 2] == key)
            return (u8)i;
    }
    return 6;
}

/*
 * ABI: reads r0 base and full-word r1 index; byte load returned in r0.
 */
int func_0689D5F4(u8 *p, int i) { return (p + i)[18]; }
