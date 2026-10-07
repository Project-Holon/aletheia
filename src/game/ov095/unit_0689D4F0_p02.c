/*
 * file:     unit_0689D4F0_p02.c
 * unit:     yes
 * function: func_0689D588, func_0689D59C
 * address:  0x0689D588
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689D5C8 0x0689D5C8 thumb ov095
 *   func_0689D5B8 0x0689D5B8 thumb ov095
 */
typedef unsigned char u8;

extern u8 func_0689D5C8(u8 *, u8);
extern int func_0689D5B8(void *, int);
int func_0689D588(u8 *p, u8 key);
int func_0689D59C(u8 *p, void *q, u8 key);

/*
 * note: Two-byte zero alignment padding follows; contiguous scratch TU is EXACT.
 */
int func_0689D588(u8 *p, u8 key)
{
    if (func_0689D5C8(p, key) != 6) return 1;
    return 0;
}

int func_0689D59C(u8 *p, void *q, u8 key)
{
    int i;
    i = func_0689D5C8(p, key);
    if (i != 6) return func_0689D5B8(q, i);
    return 0;
}
