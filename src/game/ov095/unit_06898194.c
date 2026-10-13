/*
 * file:     unit_06898194.c
 * unit:     yes
 * function: func_06898194, func_068981A0
 * address:  0x06898194
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D628 0x0689D628 data a4
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_OverwriteVar(int, int);
unsigned *func_06898194(unsigned *p);
void func_068981A0(void);
extern unsigned d_0689D628[];

unsigned *func_06898194(unsigned *p)
{
    *p = 1;
    return d_0689D628;
}

void func_068981A0(void)
{
    int value;
    value = BTL_EVENT_GetVar(61);
    BTL_EVENT_OverwriteVar(61, value + 1);
}
