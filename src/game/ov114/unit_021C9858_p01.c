/*
 * file:     unit_021C9858_p01.c
 * unit:     yes
 * function: func_021C9858, func_021C9890
 * address:  0x021C9858
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

unsigned long func_021C9858(unsigned long len);
void func_021C9890(u32 v);

/*
 * sdk:      b64size (dwc_encsession.o)
 */
unsigned long func_021C9858(unsigned long len)
{
    return (len / 3 + (len % 3 != 0 ? 1 : 0)) * 4;
}


/*
 * Duplicates a 16-bit value across the 32-bit word at 0x021D4228.
 */
void func_021C9890(u32 v)
{
    *(u32 *)0x021D4228 = v | ((u32)v << 16);
}
