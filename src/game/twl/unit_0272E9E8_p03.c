/*
 * file:     unit_0272E9E8_p03.c
 * unit:     yes
 * function: func_0272F804, func_0272F8A8, func_0272F9C4
 * address:  0x0272F804
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

u32 func_0272F804(u32 type);
asm void func_0272F8A8(void);
asm void func_0272F9C4(void);



u32 func_0272F804(u32 type)
{
    switch (type) {
    case 0:
        return 0x6000;
    case 1:
        return 0;
    case 2:
    case 8:
        return 0x800;
    case 9:
        return 0x40000800;
    case 3:
        return 0x4000;
    case 4:
        return 0x4800;
    case 10:
        return 0x60005000;
    case 5:
        return 0x20001000;
    case 6:
        return 0x60001000;
    case 7:
        return 0x20000800;
    default:
        return 0;
    }
}


asm void func_0272F8A8(void)
{
}

asm void func_0272F9C4(void)
{
}
