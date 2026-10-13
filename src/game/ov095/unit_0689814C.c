/*
 * file:     unit_0689814C.c
 * unit:     yes
 * function: func_0689814C, func_06898158
 * address:  0x0689814C
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
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D610 0x0689D610 data a4
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int, int);
void *func_0689814C(int *p);
void func_06898158(void);
extern unsigned char d_0689D610[];

/*
 * extent: 12-byte leaf, followed by labelled func_06898158.
 */
void *func_0689814C(int *p)
{
    *p = 1;
    return d_0689D610;
}

void func_06898158(void)
{
    if (BTL_EVENT_GetVar(22) == 12)
        BTL_EVENT_MultiplyVar(49, 0x548);
}
