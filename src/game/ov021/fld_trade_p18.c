/*
 * file:     fld_trade_p18.c
 * unit:     yes
 * function: func_021CEA84, func_021CEAB0, func_021CEADC
 * address:  0x021CEA84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

void func_021CEA84(u8 *p, int n);
void func_021CEAB0(u8 *p);
u8 *func_021CEADC(u8 *p);


void func_021CEA84(u8 *p, int n)
{
    p[0x521] &= 0xff ^ (1 << n);
    p[0x522] &= 0xff ^ (1 << n);
}


void func_021CEAB0(u8 *p)
{
    if (p[0x523] == 1 || p[0x525] == 1) {
        p[0x524] = 1;
    } else {
        p[0x523] = 1;
        p[0x524] = 0;
    }
}


u8 *func_021CEADC(u8 *p)
{
    p[0x525] = 0;
    p[0x523] = p[0x524];
    p[0x524] = 0;
    return p;
}
