/*
 * file:     trial_house_p03.c
 * unit:     yes
 * function: func_021CF164, func_021CF17C
 * address:  0x021CF164
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
 *   func_0203A574  0x0203A574  arm
 *   data_021DB4BC  0x021DB4BC  data
 *   func_0203A5E4  0x0203A5E4  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_0203A5E4(u32 v);
void func_021CF164(u32 a);
void func_021CF17C(void);
extern const u8 data_021DB4BC[];


/*
 * Opens the ov021 resource 0x021DB4BC in heap 0x2700 with 8 entries.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF164(u32 a)
{
    func_0203A574(0x2700, (u32)data_021DB4BC, 8, a);
}


/*
 * Tail call with 0x2700.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF17C(void)
{
    func_0203A5E4(0x2700);
}
