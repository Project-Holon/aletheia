/*
 * file:     field_wfbc_p34.c
 * unit:     yes
 * function: func_02196B7C, func_02196B90
 * address:  0x02196B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021966F0  0x021966F0  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_021966F0(u8 *p);
void func_02196B7C(u8 *p);
void func_02196B90(void);


/*
 * Untraced thunk: registers the record at 0x021966F0.
 *
 * Addresses are Black-image addresses.
 */
void func_02196B7C(u8 *p)
{
    func_02196034(p, func_021966F0, 0x47A);
}


/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196B90(void)
{
}
