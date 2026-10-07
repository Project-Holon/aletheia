/*
 * file:     unit_021C7BA0_p05.c
 * unit:     yes
 * function: func_021C93BC, func_021C93D0
 * address:  0x021C93BC
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
 *   d_021D4084 0x021D4084 data a4
 */
typedef unsigned long u32;

void EXT_TestResetCounter(void);
int func_021C93D0(void);
extern unsigned d_021D4084[];


void EXT_TestResetCounter(void)
{
    *(u32 *)0x021D4084 = 0;
}

int func_021C93D0(void)
{
    switch (d_021D4084[0]) {
    case 1:
        return 1;
    case 12:
        d_021D4084[0] = 1;
        return 1;
    }
    return 0;
}
