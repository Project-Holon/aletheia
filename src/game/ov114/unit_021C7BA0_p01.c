/*
 * file:     unit_021C7BA0_p01.c
 * unit:     yes
 * function: func_021C8658, func_021C866C, func_021C86A8
 * address:  0x021C8658
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D3D2C  0x021D3D2C  data  a4
 */
typedef unsigned long u32;

void EXT_TestResetCounter(void);
int func_021C866C(void);
int func_021C86A8(void);
extern unsigned int d_021D3D2C[];


void EXT_TestResetCounter(void)
{
    *(u32 *)0x021D3D2C = 0;
}


/*
 * Unlabelled ARM leaf in a .word run (disasm.py only labels lr-saving
 * prologues).  Extent 0x021C866C..0x021C86A8 (60 bytes) read from the ov114
 * listing: 14 instructions plus one pool word naming d_021D3D2C.
 */
int func_021C866C(void)
{
    switch (d_021D3D2C[0]) {
    case 1:
        return 1;
    case 0x18:
        d_021D3D2C[0] = 1;
        return 1;
    }
    return 0;
}


/*
 * Unlabelled ARM leaf in a .word run.  Extent 0x021C86A8..0x021C86B8
 * (16 bytes): ldr/ldr/bx plus one pool word naming d_021D3D2C.
 */
int func_021C86A8(void)
{
    return d_021D3D2C[1];
}
