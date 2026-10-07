/*
 * file:     fldeff_namipoke_p04.c
 * unit:     yes
 * function: func_021ACBE4, func_021ACC04
 * address:  0x021ACBE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct E { int f0; int f4; int f8; } E;

int func_021ACBE4(int n);
int func_021ACC04(E *a, E *b, u32 mode);


int func_021ACBE4(int n)
{
    if (n > 0x40000)
        n = 0x40000;
    return n / 0xA3D * 0x28;
}


int func_021ACC04(E *a, E *b, u32 mode)
{
    int r = 0;

    switch (mode) {
    case 0:
        r = b->f8 - a->f8;
        break;
    case 1:
        r = a->f8 - b->f8;
        break;
    case 2:
        r = b->f0 - a->f0;
        break;
    case 3:
        r = a->f0 - b->f0;
        break;
    }
    return r;
}
