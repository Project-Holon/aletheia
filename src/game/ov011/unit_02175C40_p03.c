/*
 * file:     unit_02175C40_p03.c
 * unit:     yes
 * function: func_02175EB8, func_02175ED8
 * address:  0x02175EB8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175BCC 0x02175BCC thumb ov011
 */
typedef unsigned char u8;

typedef struct Sub {
    u8 pad000[0x1a5];
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 bit2 : 1;
    u8 bit3 : 1;
    u8 bit4 : 1;
} Sub;

extern u8 *func_02175BCC(u8 *p);
int func_02175EB8(void *p);
int func_02175ED8(Sub *s);

/*
 * extent: alignment at 02175ED6 then existing filed leaf ov011_func_02175ED8.c.
 * interface: BCC matched caller returns int; body returns original object +0xac or null.
 */
int func_02175EB8(void *p)
{
    u8 *r;
    r = (u8 *)func_02175BCC(p);
    if (r == 0) return 0;
    if (r[0x37] == 1) return 1;
    return 0;
}


/*
 * Flag getter: bit 4 of the byte at 0x1A5 (the lsls #27 / lsrs #31 pair is
 * a one-bit bitfield read).  A leaf with no lr save, so disasm.py left it as
 * .word data; filed for ov011 func_02172D70, whose only unresolved call
 * site besides arm9 0x02008494 it was.
 */
int func_02175ED8(Sub *s)
{
    return s->bit4;
}
